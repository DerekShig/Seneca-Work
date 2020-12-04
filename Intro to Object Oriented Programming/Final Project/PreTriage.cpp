#define _CRT_SECURE_NO_WARNINGS

#include "PreTriage.h"
#include <fstream>
#include <cstring>
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"

using namespace std;
namespace sdds {

	PreTriage::PreTriage(const char* dataFilename) : m_averCovidWait(15), m_averTriageWait(5), 
		m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		load();
	}

	PreTriage::~PreTriage() {
		ofstream f(m_dataFilename, ofstream::trunc);
		cout << "Saving Average Wait Times," << endl;
		cout << "   COVID Test: ";
		m_averCovidWait.write(cout) << endl;
		cout << "   Triage: ";
		m_averTriageWait.write(cout) << endl;
		f << m_averCovidWait << ',' << m_averTriageWait << endl;
		cout << "Saving m_lineup..." << endl;
		for (int i = 0; i < m_lineupSize; i++) {
			cout << i + 1 << "- ";
			m_lineup[i]->csvWrite(cout) << endl;
			m_lineup[i]->csvWrite(f) << endl;
			delete m_lineup[i];
		}
		delete[] m_dataFilename;
		cout << "done!" << endl;
	}

	void PreTriage::run(void) {
		int choice = 0;
		do {
			m_appMenu >> choice;
			if (choice == 1) {
				reg();
			}
			else if (choice == 2) {
				admit();
			}
		} while (choice != 0);
	}

	void PreTriage::reg() {
		int choice = 0;
		if (m_lineupSize >= 100) { 
			cout << "Line up full!" << endl;
			return; 
		}
		m_pMenu >> choice;
		if (choice == 1) {
			m_lineup[m_lineupSize] = new CovidPatient();
		}
		else if (choice == 2) {
			m_lineup[m_lineupSize] = new TriagePatient();
		}
		else { return; }
		m_lineup[m_lineupSize]->setArrivalTime();
		m_lineup[m_lineupSize]->fileIO(false);
		cout << "Please enter patient information: " << endl;
		m_lineup[m_lineupSize]->read(cin);
		cout << endl;
		cout << "******************************************" << endl;
		m_lineup[m_lineupSize]->write(cout);
		cout << "Estimated Wait Time: ";
		getWaitTime(*m_lineup[m_lineupSize]).write(cout);
		cout << endl;
		cout << "******************************************" << endl << endl;
		m_lineupSize++;
		
	}

	void PreTriage::admit() {
		char type = '\0';
		int choice = 0;
		m_pMenu >> choice;
		if (choice == 1) {
			type = 'C';
		}
		else if (choice == 2) {
			type = 'T';
		}
		else { return; }
		int index = indexOfFirstInLine(type);
		if (index == -1) {
			return;
		}
		else {
			cout << endl;
			cout << "******************************************" << endl;
			m_lineup[index]->fileIO(false);
			cout << "Calling for ";
			m_lineup[index]->write(cout);
			cout << "******************************************" << endl << endl;
			setAverageWaitTime(*m_lineup[index]);
			removePatientFromLineup(index);
		}
	}

	const Time PreTriage::getWaitTime(const Patient& p) const {
		int matches = 0;
		for (int i = 0; i < m_lineupSize; i++) {
			if (m_lineup[i]->type() == p.type()) {
				matches++;
			}
		}
		if (p.type() == 'C') {
			matches *= (int)m_averCovidWait;
		}
		else {
			matches *= (int)m_averTriageWait;
		}
		return (Time)matches;
	}

	void PreTriage::setAverageWaitTime(const Patient& p) {
		if (p.type() == 'C') {
			m_averCovidWait = ((Time().reset() - (Time)p) + ((int)m_averCovidWait * (p.number() - 1))) / p.number();
		}
		else {
			m_averTriageWait = ((Time().reset() - (Time)p) + ((int)m_averTriageWait * (p.number() - 1))) / p.number();
		}
	}

	void PreTriage::removePatientFromLineup(int index) {
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	void PreTriage::load() {
		cout << "Loading data..." << endl;
		ifstream i;
		i.open(m_dataFilename);
		i >> m_averCovidWait;
		i.ignore();
		i >> m_averTriageWait;
		i.ignore(1000, '\n');
		bool valid = true;
		Patient* p{};
		char type = '\0';
		for (int j = 0; j < maxNoOfPatients && valid == true; j++) {
			type = '\0';
			i.get(type);
			i.ignore();
			if (type == 'C') {
				p = new CovidPatient();
			}
			else if (type == 'T') {
				p = new TriagePatient();
			}
			else {
				valid = false;
			}
			if (valid == true) {
				p->fileIO(true);
				p->csvRead(i);
				p->fileIO(false);
				m_lineup[m_lineupSize] = p;
				m_lineupSize++;
				if (type == 'C') {
					i.ignore(100, '\n');
				}
				if (m_lineupSize >= 100) {
					cout << "Warning: number of records exceeded 100" << endl;
					valid = false;
				}

			}
			
		}
		if (m_lineupSize == 0) {
			cout << "No data or bad data file!" << endl << endl;
		}
		else {
			cout << m_lineupSize << " Records imported..." << endl << endl;
		}
		i.close();	
	}

	int PreTriage::indexOfFirstInLine(char type) const {
		int found = -1;
		bool flag = true;
		for (int i = 0; i < maxNoOfPatients && flag == true; i++) {
			if (m_lineup[i]->type() == type) {
				found = i;
				flag = false;
			}
		}
		return found;
	}

}
