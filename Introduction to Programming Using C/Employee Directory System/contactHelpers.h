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

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents here...                         |
// +-------------------------------------------------+

#include <stdio.h>
#include "contacts.h"

void clearKeyboard(void);

void pause(void);

int getInt(void);

int getIntInRange(int min, int max);

int yes(void);

int menu(void);

void contactManagerSystem(void);

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | NOTE:  Add new function prototypes as per the   |
// |        Milestone-3 specifications document      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char phoneNum[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

void displayContactHeader(void);

void displayContactFooter(int count);

void displayContact(const struct Contact* contact);

void displayContacts(const struct Contact contacts[], int size);

void searchContacts(const struct Contact contacts[], int size);

void addContact(struct Contact contacts[], int size);

void updateContact(struct Contact contacts[], int size);

void deleteContact(struct Contact contacts[], int size);

void sortContacts(struct Contact contacts[], int size);