//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Section:        NHH
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	// Variable declarations
	double amount;
	int looney, quarters, dimes, nickles, pennies;
	double remainder;
	double GST;

	// User enters amount
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	// GST
	GST = amount * 0.13 + 0.005;
	amount += GST;
	printf("GST: %.2lf\n", GST);
	printf("Balance owing: $%.2lf\n", amount);

	// Loonies
	looney = (int)amount;
	remainder = amount - looney;
	printf("Loonies required: %i, balance owing $%1.2f\n", looney, remainder);
	
	// Quarters
	quarters = remainder / 0.25;
	remainder *= 100;
	remainder = (int)remainder % 25;
	printf("Quarters required: %i, balance owing $%1.2f\n", quarters, (float)remainder / 100);

	// Dimes
	dimes = remainder / 10;
	remainder = (int)remainder % 10;
	printf("Dimes required: %i, balance owing $%1.2f\n", dimes, (float)remainder / 100);

	// Nickles
	nickles = remainder / 5;
	remainder = (int)remainder % 5;
	printf("Nickles required: %i, balance owing $%1.2f\n", nickles, (float)remainder / 100);

	// Pennies
	pennies = remainder / 1;
	remainder = (int)remainder % 1;
	printf("Pennies required: %i, balance owing $%1.2f\n", pennies, (float)remainder / 100);

	// Exit program
	return 0;
}
