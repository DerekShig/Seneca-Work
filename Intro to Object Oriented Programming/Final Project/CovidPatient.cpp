#include "CovidPatient.h"
#include <iostream>

using namespace std;

namespace sdds {
   int nextCovidTicket = 1;
  

   CovidPatient::CovidPatient() : Patient(nextCovidTicket) {
	   nextCovidTicket++;
   }

   char CovidPatient::type() const{
	   return 'C';
   }

   ostream& CovidPatient::csvWrite(ostream& os) const {
	   Patient::csvWrite(os);
	   return os;
   }

   istream& CovidPatient::csvRead(istream& is) {
	   Patient::csvRead(is);
	   nextCovidTicket = Patient::number() + 1;
	   return is;
   }

   ostream& CovidPatient::write(ostream& os) const {
	   if (fileIO()) {
		   csvWrite(os);
	   }
	   else {
		   os << "COVID TEST" << endl;
		   Patient::write(os);
		   os << endl;
	   }
	   return os;
   }

   istream& CovidPatient::read(istream& is) {
	   if (fileIO()) {
		   csvRead(is);
	   }
	   else {
		   Patient::read(is);
	   }
	   return is;
   }

}