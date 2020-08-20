//==============================================
// Name:           Derek Shigetomi 
// Student Number: 028-970-135
// Email:          dgshigetomi@myseneca.ca
// Section:        NHH
// Date:           7/30/2020
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+
#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"
#include <string.h>

void getName(struct Name* name) {

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    clearKeyboard();

    printf("Do you want to enter a middle initial(s)? (y or n): ");

    if (yes() == 1) {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    }
    else {
        *name->middleInitial = '\0';
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();
}

// getAddress:
void getAddress(struct Address* address) {

    int streetNumber = 0;

    printf("Please enter the contact's street number: ");

    do {

        streetNumber = getInt();

        if (streetNumber < 1) {
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        }

    } while (streetNumber < 1);
    address->streetNumber = streetNumber;

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");
    if (yes() == 1) {
        int aptNumber = 0;
        printf("Please enter the contact's apartment number: ");
        do
        {
            aptNumber = getInt();

            if (aptNumber < 1) {
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            }
        } while (aptNumber < 1);
        address->apartmentNumber = aptNumber;
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers* numbers) {

    char cell[11];
    char home[11];
    char business[11];

    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(cell);
    strcpy(numbers->cell, cell);

    printf("Do you want to enter a home phone number? (y or n): ");
    if (yes() == 1) {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(home);
        strcpy(numbers->home, home);
    }
    else {
        *numbers->home = '\0';
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    if (yes() == 1) {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(business);
        strcpy(numbers->business, business);
    }
    else {
        *numbers->business = '\0';
    }
}

void getContact(struct Contact* contact) {
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
