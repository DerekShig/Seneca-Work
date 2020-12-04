#include <iostream>
#include "IOAble.h"
#include "Ticket.h"

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
namespace sdds {
	class Patient : public IOAble {
		char* p_name;
		int p_number;
		Ticket p;
		bool p_flag;
	public:
		Patient(int ticketNum = 0, bool flag = false);
		Patient& operator=(Patient&) = delete;
		~Patient();
		virtual char type() const = 0;
		bool fileIO() const;
		void fileIO(bool b);
		bool operator==(char c) const;
		bool operator==(const Patient& p) const;
		void setArrivalTime();
		operator Time() const;
		int number() const;
		ostream& csvWrite(ostream& os) const override;
		istream& csvRead(istream& is) override;
		ostream& write(ostream& os)const override;
		istream& read(istream& is) override;
	};
}
#endif // !SDDS_PATIENT_H_


