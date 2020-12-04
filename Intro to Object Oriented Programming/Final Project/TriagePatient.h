#ifndef SDDS_TRIAGE_H
#define SDDS_TIRAGE_H
#include <iostream>
#include "Patient.h"
namespace sdds {
   class TriagePatient : public Patient {
	   char* symptoms;
   public:
	   TriagePatient();
	   char type() const;
	   ostream& csvWrite(ostream& os) const;
	   istream& csvRead(istream& is);
	   ostream& write(ostream& os)const;
	   istream& read(istream& is);
	   ~TriagePatient();
   };

}
#endif // !SDDS_


