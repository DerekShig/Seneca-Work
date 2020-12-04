#define _CRT_SECURE_NO_WARNINGS

#include "TriagePatient.h"
#include  <cstring>
using namespace std;

namespace sdds {

	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() : Patient(nextTriageTicket){
		nextTriageTicket++;
		symptoms = nullptr;
	}

	char TriagePatient::type() const {
		return 'T';
	}

	ostream& TriagePatient::csvWrite(ostream& os) const {
		Patient::csvWrite(os);
		os << ',' << symptoms;
		return os;

	}

	istream& TriagePatient::csvRead(istream& is) {
		char temp[511];
		delete[] symptoms;
		Patient::csvRead(is);
		is.ignore(1000, ',');
		is.getline(temp, 511, '\n');
		//is.clear(istream::eofbit | istream::failbit);
		symptoms = new char[strlen(temp) + 1];
		strcpy(symptoms, temp);
		nextTriageTicket = number() + 1;
		return is;
	}

	ostream& TriagePatient::write(ostream& os) const {
		if (fileIO()) {
			csvWrite(os);
		}
		else {
			os << "TRIAGE" << endl;
			Patient::write(os);
			os << endl;
			os << "Symptoms: " << symptoms << endl;
		}
		return os;
	}

	istream& TriagePatient::read(istream& is) {
		if (fileIO()) {
			csvRead(is);
		}
		else {
			char temp[511];
			delete[] symptoms;
			Patient::read(is);
			cout << "Symptoms: ";
			is.getline(temp, 511, '\n');
			symptoms = new char[strlen(temp) + 1];
			strcpy(symptoms, temp);
		}
		return is;
	}

	TriagePatient::~TriagePatient() {
		delete[] symptoms;
	}

}