//==============================================
// Name:           Derek Shigetomi
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Section:        NHH
// Workshop:       5 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 4

struct Employee {
	int id;
	int age;
	double salary;
};

/* main program */
int main(void)
{
	int option = 0;
	int num_employees = 0;
	int emp_index = 0;

	struct Employee emp[SIZE] = { {0} };

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{
		case 0:	// Exit the program

			printf("Exiting Employee Data Program. Good Bye!!!");
			break;

		case 1: // Display Employee Data

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			int i;
			for (i = 0; i < SIZE; i++) {
				if (emp[i].id > 0) {
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
				}
			}
			printf("\n");
			break;

		case 2:	// Adding Employee

			printf("Adding Employee\n");
			printf("===============\n");

			if (num_employees >= SIZE) {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}
			// if no employee has been removed 
			else if (emp_index == -1) { 

				printf("Enter Employee ID: ");
				scanf("%i", &emp[num_employees].id);
				printf("Enter Employee Age: ");
				scanf("%i", &emp[num_employees].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[num_employees].salary);
				printf("\n");
				num_employees++;
			}
			// if an employee has been removed, add an employee at the index where they were removed
			else {
				printf("Enter Employee ID: ");
				scanf("%i", &emp[emp_index].id);
				printf("Enter Employee Age: ");
				scanf("%i", &emp[emp_index].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[emp_index].salary);
				printf("\n");
				emp_index = -1;
				num_employees++;
			}

			break;

		case 3: // Update salary

			printf("Update Employee Salary\n");
			printf("======================\n");

			int flag = 0;
			int check_id = 0;

			do {

				printf("Enter Employee ID: ");
				scanf("%i", &check_id);

				int j;
				for (j = 0; j < SIZE; j++) {
					if (emp[j].id == check_id) {
						printf("The current salary is %.2lf\n", emp[j].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[j].salary);
						printf("\n");
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					printf("*** ERROR: Employee ID not found! ***\n");
				}

			} while (flag == 0);

			break;

		case 4: // Remove employee

			printf("Remove Employee\n");
			printf("===============\n");

			flag = 0;
			check_id = 0;

			do {

				printf("Enter Employee ID: ");
				scanf("%i", &check_id);
				int k;
				for (k = 0; k < SIZE; k++) {
					if (emp[k].id == check_id) {
						
						printf("Employee %i will be removed\n", emp[k].id);
						emp[k].id = 0;
						printf("\n");
						flag = 1;
						num_employees--;
						emp_index = k;
						break;
					}
				}

				if (flag == 0) {
					printf("*** ERROR: Employee ID not found! ***\n");
				}

			} while (flag == 0);

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}