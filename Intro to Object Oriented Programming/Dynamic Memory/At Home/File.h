//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Date:           10/4/2020
// Section:        NDD
// Workshop:       2 (DIY)
// I have done all the coding by myself
//==============================================

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {

	struct Info {
		int acc;
		double amount;
	};

	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	void read(int &number);
	void read(double &balance);

}
#endif // !SDDS_FILE_H_
