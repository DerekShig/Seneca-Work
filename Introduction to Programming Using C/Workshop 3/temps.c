//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Section:        NHH
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#define NUMS 4

#include <stdio.h>
#include <stdbool.h>

int main(void) {

	printf("---=== IPC Temperature Analyzer ===---\n");

	// Variable declarations
	int high, low;
	int highest = 0, high_day;
	int lowest = 0, low_day;
	float high_total = 0, low_total = 0;
	float avg, high_avg, low_avg;
	int n = 1;

	// Loop through days
	for (; n <= NUMS; n++) {

		bool loop = true;

		do {
			// Get high value
			printf("Enter the high value for day %i: ", n);
			scanf("%i", &high);
			printf("\n");

			// Get low value
			printf("Enter the low value for day %i: ", n);
			scanf("%i", &low);
			printf("\n");

			// If input meets conditions
			if ((high > low) && (high < 41 && high > -41) && (low > -41 && low < 41)) {
				loop = false;
				high_total += high;
				low_total += low;
				// Get max temp and day
				if (high > highest) {
					highest = high;
					high_day = n;
				}
				// Get lowest temp and day
				if (low < lowest) {
					lowest = low;
					low_day = n;
				}
			}
			else {
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
				printf("\n");
			}
		} while (loop);

	}

	// Calculations
	low_avg = low_total / NUMS;
	high_avg = high_total / NUMS;
	avg = (high_total + low_total) / (NUMS * 2);

	printf("The average (mean) LOW temperature was: %.2lf\n", low_avg);
	printf("The average (mean) HIGH temperature was: %.2lf\n", high_avg);
	printf("The average (mean) temperature was: %.2f\n", avg);
	printf("The highest temperature was %i, on day %i\n", highest, high_day);
	printf("The lowest temperature was %i, on day %i\n", lowest, low_day);

	return  0;
}