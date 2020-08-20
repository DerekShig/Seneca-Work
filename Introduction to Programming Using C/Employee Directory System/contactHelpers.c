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
#define MAXCONTACTS 5

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

#include <string.h>
#include <ctype.h>
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        contents below...                        |
// +-------------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}

void pause(void) {
    printf("(Press Enter to Continue)");
    clearKeyboard();
}

// get valid integer number from user
int getInt(void) {

    int number = 0;
    char newLine;

    do {

        scanf("%d%c", &number, &newLine);

        if (newLine != '\n') {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }

    } while (newLine != '\n');

    return number;
}

int getIntInRange(int min, int max) {

    int number = 0;
    int valid = 0;

    do {

        number = getInt();

        if (number >= min && number <= max) {
            valid = 1;
        }
        else {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        }

    } while (valid == 0);

    return number;
}

int yes(void) {

    char letter;
    char newLine;
    int valid = 0;
    int rtrn = 0;

    do {

        scanf("%c%c", &letter, &newLine);

        if ((letter == 'Y' || letter == 'y') && newLine == '\n') {
            valid = 1;
            rtrn = 1;
        }
        else if ((letter == 'N' || letter == 'n') && newLine == '\n') {
            valid = 1;
        }
        else if (newLine != '\n') {
            clearKeyboard();
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }
        else {
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }

    } while (valid == 0);

    return rtrn;
}

int menu(void) {

    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n\n");
    printf("Select an option:> ");

    return getIntInRange(0, 6);
}

void contactManagerSystem(void) {

    int yesNo = 0;

    struct Contact contact[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" },
                                              { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
                                              { "4161112222", "4162223333", "4163334444" } },
                                            {  
                                              { "Maggie", "R.", "Greene" },
                                              { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },             
                                              { "9051112222", "9052223333", "9053334444" } },          
                                            {              
                                              { "Morgan", "A.", "Jones" },             
                                              { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },             
                                              { "7051112222", "7052223333", "7053334444" } },          
                                            {              
                                              { "Sasha", {'\0'}, "Williams" },             
                                              { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },             
                                              { "9052223333", "9052223333", "9054445555" } }, 
                                           };

    do {
        int choice = menu();
        switch (choice) {
            // Display contacts
        case 1:
            //printf("\n<<< Feature %d is unavailable >>>\n\n", choice);
            displayContacts(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
            // Add contact
        case 2:
            addContact(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
            // Update contact
        case 3:
            updateContact(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
            // Delete contact
        case 4:
            deleteContact(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
            // Search contact by cell phone
        case 5:
            searchContacts(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
            // Sort contact by cell phone
        case 6:
            sortContacts(contact, MAXCONTACTS);
            printf("\n--- Contacts sorted! ---\n\n");
            pause();
            printf("\n");
            break;
            // Exit program
        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            yesNo = yes();
            printf("\n");
            break;
        }
    } while (yesNo != 1);

    printf("Contact Management System: terminated\n");

}
// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// get a 10-digit number from user
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;
    int validNum;
    int i;

    while (needInput == 1) {
        validNum = 1;
        scanf("%10s", phoneNum);
        clearKeyboard();

        for (i = 0; i < strlen(phoneNum) && validNum == 1; i++) {
            if (isdigit(phoneNum[i]) == 0) {
                validNum = 0;
            }
        }
        if (i != 10 || validNum == 0) {
            printf("Enter a 10-digit phone number: ");
        }
        else {
            needInput = 0;
        }

    }
}

// Return index of matching contact. If not found, return -1
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i, contactFound = 0;

    for (i = 0; i < size && contactFound == 0; i++) {
        //if cellNum matches a contact
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
            contactFound = 1;
        }
    }
    if (contactFound == 0) {
        i = -1;
    }
    else {
        i -= 1;
    }
    return i;
}

void displayContactHeader(void) {
    printf("\n+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

void displayContactFooter(int count) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", count);
}

// Display valid contact, ie contact with valid cell number
void displayContact(const struct Contact* contact) {
    printf(" %s ", contact->name.firstName);
    if (strcmp(contact->name.middleInitial, "") != 0) {
        printf("%s ", contact->name.middleInitial);
    }
    printf("%s\n", contact->name.lastName);
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
    if (contact->address.apartmentNumber > 0) {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// Display all valid contacts
void displayContacts(const struct Contact contacts[], int size) {
    displayContactHeader();
    int i, totalContact = 0;
    for (i = 0; i < size; i++) {
        if (strcmp(contacts[i].numbers.cell, "") != 0) {
            displayContact(&contacts[i]);
            totalContact++;
        }
    }
    displayContactFooter(totalContact);
}

// search contact by cell number
void searchContacts(const struct Contact contacts[], int size) {

    int index;
    char phone[11];

    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(phone);
    index = findContactIndex(contacts, size, phone);
    if (index != -1) {
        printf("\n");
        displayContact(&contacts[index]);
        printf("\n");
    }
    else {
        printf("*** Contact NOT FOUND ***\n\n");
    }
}

// add contact if space
void addContact(struct Contact contacts[], int size) {
    int available;
    available = findContactIndex(contacts, size, "");
    if (available == -1) {
        printf("\n*** ERROR: The contact list is full! ***\n\n");
    }
    else {
        printf("\n");
        getContact(&contacts[available]);
        printf("--- New contact added! ---\n\n");
    }

}

// update contact with matching cell number
void updateContact(struct Contact contacts[], int size) {
    int index;
    char phone[11];
    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(phone);
    index = findContactIndex(contacts, size, phone);
    if (index != -1) {
        printf("\nContact found:\n");
        displayContact(&contacts[index]);
        printf("\nDo you want to update the name? (y or n): ");
        if (yes() == 1) {
            getName(&contacts[index].name);
        }
        printf("Do you want to update the address? (y or n): ");
        if (yes() == 1) {
            getAddress(&contacts[index].address);
        }
        printf("Do you want to update the numbers? (y or n): ");
        if (yes() == 1) {
            getNumbers(&contacts[index].numbers);
        }
        printf("--- Contact Updated! ---\n\n");
    }
    else {
        printf("*** Contact NOT FOUND ***\n\n");
    }
}

// delete contact with matching cell number, sets cell number to blank string
void deleteContact(struct Contact contacts[], int size) {
    int index;
    char phone[11];
    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(phone);
    index = findContactIndex(contacts, size, phone);
    if (index != -1) {
        printf("\nContact found:\n");
        displayContact(&contacts[index]);
        printf("\nCONFIRM: Delete this contact? (y or n): ");
        if (yes() == 1) {
            *contacts[index].numbers.cell = '\0';
            printf("--- Contact deleted! ---\n\n");
        }
        else {
            printf("\n");
        }
    }
}

// sort contacts in ascending order based on cell number
void sortContacts(struct Contact contacts[], int size) {

     int i, j, m;
     struct Contact temp = { {{'\0'}} };

     for (i = 0; i < size; i++) {
         m = i;
         for (j = i + 1; j < size; j++)
             if (strcmp(contacts[j].numbers.cell, contacts[m].numbers.cell) < 0) {
                 m = j;
             }
         if (m != i) {
             temp = contacts[i];
             contacts[i] = contacts[m];
             contacts[m] = temp;
         }
     }
}