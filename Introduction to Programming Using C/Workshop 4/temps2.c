//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Section:        NHH
// Workshop:       4 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	int num_days;
	int flag = 1;
	int error = 0;

	do {
		// Check if user made error, change print statement
		if (error == 1) {
			printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
			scanf("%i", &num_days);
			printf("\n");
		}
		// If no error
		else {
			printf("Please enter the number of days, between 3 and 10, inclusive: ");
			scanf("%i", &num_days);
			error = 1;
			printf("\n");
		}
		// If number of days meets condition, break out of loop
		if (num_days >= 3 && num_days <= 10) {
			flag = 0;
		}

	} while (flag == 1);

	int days[10];
	int high_arr[10];
	int low_arr[10];
	int highest = -100, lowest = 100;	// This is just for testing purposes / validate input so high is not very low and low is very high
	int highest_day = 0, lowest_day = 0;

	int i = 0;
	for (; i < num_days; i++) {

		days[i] = i + 1;

		printf("Day %i - High: ", i + 1);
		scanf("%i", &high_arr[i]);

		printf("Day %i - Low: ", i + 1);
		scanf("%i", &low_arr[i]);

		if (high_arr[i] > highest) {
			highest = high_arr[i];
			highest_day = i + 1;
		}
		if (low_arr[i] < lowest) {
			lowest = low_arr[i];
			lowest_day = i + 1;
		}
	}

	// Prints temp records
	printf("\n");
	printf("Day  Hi  Low\n");
	int j = 0;
	for (; j < num_days; j++) {
		printf("%i    %i    %i\n", days[j], high_arr[j], low_arr[j]);
	}

	printf("\n");
	printf("The highest temperature was %i, on day %i\n", highest, highest_day);
	printf("The lowest temperature was %i, on day %i\n\n", lowest, lowest_day);

	// Reset flag and error for second user input validation
	flag = 1;
	error = 0;

	int day_range;

	do {
		// Check if user made error, change print statement
		if (error == 1) {
			printf("Invalid entry, please enter a number between 1 and %i, inclusive: ", num_days);
			scanf("%i", &day_range);
			printf("\n");
		}
		// If no error
		else {
			printf("Enter a number between 1 and %i to see the average temperature for the entered number of days, enter a negative number to exit: ", num_days);
			scanf("%i", &day_range);
			printf("\n");
		}
		// If day range meets condition, calculate average temp in range
		if (day_range >= 1 && day_range <= num_days) {
			
			float total_temp = 0;

			int k = 0;
			for (; k < day_range; k++) {
				total_temp += high_arr[k] + low_arr[k];
			}
			total_temp /= day_range * 2;
			
			printf("The average temperature up to day %i is: %.2f\n\n", day_range, total_temp);
			error = 0;
		}
		// user exits
		else if (day_range < 0) {
			flag = 0;
		}
		// user doesnt enter valid input ie: not between 1 and day_range.
		else {
			error = 1;
		}

	} while (flag == 1);

	printf("Goodbye!");

	return 0;
}