#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"
namespace sdds {

   class CovidPatient : public Patient {
   public:
	   CovidPatient();
	   char type() const;
	   ostream& csvWrite(ostream& os) const;
	   istream& csvRead(istream& is);
	   ostream& write(ostream& os)const;
	   istream& read(istream& is);
   };
}
#endif // !SDDS_COVIDPATIENT_H_