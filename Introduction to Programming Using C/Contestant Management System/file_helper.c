/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Derek Shigetomi          dgshigetomi@myseneca.ca
   2)
   3)

   +--------------------------------------------------------+
   |                   FILE: main.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  S  U  M  M  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#define MAX_SKIERS 2000
#define _CRT_SECURE_NO_WARNINGS

#include "file_helper.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

   /********************************************************/
   /* Read from the opened file the time (HH:MM) parts of  */
   /* the record and return the time as decimal hours      */
   /********************************************************/
double readTime(FILE* fp)
{
    int hour, min;

    fscanf(fp, "%d%*c", &hour);
    fscanf(fp, "%d", &min);

    return hour + (min / 60.0);
}

/********************************************************/
/* Read all the information on one skier from the valid */
/* (pre-opened) file and store it in the struct.        */
/* Return true when end of file has been reached.       */
/********************************************************/
int readFileRecord(FILE* fp, struct SkierInfo* info)
{
    int result = 1, ch;

    if (!feof(fp))
    {
        result = 0;

        // read from file and assign to data structure
        fscanf(fp, "%[^,]%*c", info->name);
        fscanf(fp, "%d", &info->age);
        fscanf(fp, " %c", &info->raceLength);
        info->startTime = readTime(fp);
        info->midwayTime = readTime(fp);
        info->finishTime = readTime(fp);

        // Last Field (withdrawn: may not be present)
        ch = fgetc(fp);
        info->withdrawn = 0;

        if (ch == ' ')
        {
            ch = fgetc(fp);
            info->withdrawn = ch == 'W';
            ch = fgetc(fp);
        }

        // clear input file buffer until end of line (record):
        while (!feof(fp) && ch != '\n')
        {
            ch = fgetc(fp);
        }
    }

    return result;
}

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

// NEW FUNCTIONS BELOW //
//********************//

// Gets race category (S, M, L) from user. Case insensitive
char raceType(void) {

    int valid = 0;
    char race;
    char newLine;

    do {
        scanf("%c%c", &race, &newLine);
        race = toupper(race);
        if ((race == 'S' || race == 'M' || race == 'L') && newLine == '\n') {
            valid = 1;
        }
        else if (newLine != '\n') {
            clearKeyboard();
            printf("Error. Please enter a valid race category: ");
        }
        else {
            printf("Error. Please enter a valid race category: ");
        }
    } while (valid == 0);

    return race;
}

// convert decimal time to hours and minutes
void convertTime(double decimalTime, int* hours, int* minutes) {
    int time_mins = (int)floor(decimalTime * 60.0);
    int convertHours = time_mins / 60;
    int convertMinutes = time_mins % 60;
    *hours = convertHours;
    *minutes = convertMinutes;
}

// sort skier struct by finishing time and withdrawn value
void sort(struct SkierInfo* info, int size) {
    int i, j, m;
    struct SkierInfo temp;

    for (i = 0; i < size; i++) {
        m = i;
        for (j = i + 1; j < size; j++)
            if (info[j].finishTime < info[m].finishTime) {
                m = j;
            }
        if (m != i) {
            temp = info[i];
            info[i] = info[m];
            info[m] = temp;
        }
    }
    for (i = 0; i < size; i++) {
        m = i;
        for (j = i + 1; j < size; j++)
            if (info[j].withdrawn < info[m].withdrawn) {
                m = j;
            }
        if (m != i) {
            temp = info[i];
            info[i] = info[m];
            info[m] = temp;
        }
    }
}

// gets extra values for printing
void extraData(struct SkierInfo* info) {
    if (info->age >= 16 && info->age <= 20) {
        strcpy(info->ageGroup, "Junior");
    }
    else if (info->age >= 21 && info->age <= 34) {
        strcpy(info->ageGroup, "Adult");
    }
    else {
        strcpy(info->ageGroup, "Senior");
    }
    if (info->raceLength == 'S') {
        strcpy(info->raceDistance, "10 km");
    }
    else if (info->raceLength == 'M') {
        strcpy(info->raceDistance, "25 km");
    }
    else {
        strcpy(info->raceDistance, "50 km");
    }
}

// scans entire file into skier array struct
int allData(FILE* fp, struct SkierInfo* info) {
    int end = 0, i;
    for (i = 0; i < MAX_SKIERS && end == 0; i++) {
        readFileRecord(fp, &info[i]);
        if (strcmp(info[i].name, "") == 0) {
            end = 1;
        }
        extraData(&info[i]);
    }
    return i - 1;
}

// code to print top/bottom three skiers
void printThree(struct SkierInfo* info, int* winners, int index) {
    int hours = 0, minutes = 0;
    // if no skiers have been added to the winner index array
    if (winners[0] == -1) {
        printf("\nNo skiers participated in this category.\n\n");
    }
    else {
        printf("\nSkier                                        Age Group     Time\n");
        printf("---------------------------------------------------------------\n");
        for (int k = 0; k < index; k++) {
            if (winners[k] != -1) {
                convertTime(info[winners[k]].finishTime, &hours, &minutes);
                printf("%-44s %-13s %d%c%.2d\n", info[winners[k]].name, info[winners[k]].ageGroup, hours, ':', minutes);
            }
        }
        printf("\n");
    }
}

// determine bottom three skiers in category, then print
void lastThree(struct SkierInfo* info, int numSkiers) {
    int i, index = 0;

    int hours = 0, minutes = 0;

    int winners[3];
    // initialize all values of array to -1
    memset(winners, -1, sizeof(winners));
    char race = raceType();

    // iterate backwards and take last 3 that have not withdrawn
    for (i = numSkiers; i-- > 0 && index < 3;) {
        if (info[i].withdrawn != 1 && info[i].raceLength == race) {
            // keep index of winner
            winners[index] = i;
            index++;

        }
    }
    printThree(info, winners, index);
}

// determine top three skiers in category, then print
void topThree(struct SkierInfo* info, int numSkiers) {

    int i, index = 0;

    int hours = 0, minutes = 0;

    int winners[3];
    // initialize all values of array to -1
    memset(winners, -1, sizeof(winners));
    char race = raceType();

    for (i = 0; i < numSkiers && index < 3; i++) {
        if (info[i].withdrawn != 1 && info[i].raceLength == race) {
            // keep index of winner
            winners[index] = i;
            index++;
        }
    }
    printThree(info, winners, index);
}

// prints all skiers in a specific category
void allInCategory(struct SkierInfo* info, int numSkiers) {
    int i, index = 0;

    int hours = 0, minutes = 0;

    int winners[MAX_SKIERS];
    // initialize all values of array to -1
    memset(winners, -1, sizeof(winners));
    char race = raceType();

    for (i = 0; i < numSkiers; i++) {
        if (info[i].raceLength == race) {
            // keep index of winner
            winners[index] = i;
            index++;
        }
    }
    // if no skiers have been added to the winner index array
    if (winners[0] == -1) {
        printf("\nNo skiers participated in this category.\n\n");
    }
    else {
        printf("\nSkier                                        Age Group     Time     Withdrew\n");
        printf("----------------------------------------------------------------------------\n");
        for (int k = 0; k < index; k++) {
            if (winners[k] != -1) {
                if (info[winners[k]].withdrawn == 1) {
                    printf("%-44s %-13s N/A      Yes\n", info[winners[k]].name, info[winners[k]].ageGroup);
                }
                else {
                    convertTime(info[winners[k]].finishTime, &hours, &minutes);
                    printf("%-44s %-13s %d%c%.2d     No\n", info[winners[k]].name, info[winners[k]].ageGroup, hours, ':', minutes);
                }
            }

        }
        printf("\n");
    }

}

// print one winner in each category
void allWinners(struct SkierInfo* info, int numSkiers) {
    int i, index = 0;

    int hours = 0, minutes = 0;

    // save best times in each category, initialize to high number
    double bestS = 1000, bestM = 1000, bestL = 1000;

    // index of each category winner
    int winners[3];
    // initialize all values of array to -1
    memset(winners, -1, sizeof(winners));

    for (i = 0; i < numSkiers && index < 3; i++) {
        if (info[i].raceLength == 'S' && info[i].finishTime < bestS && info[i].withdrawn == 0) {
            winners[0] = i;
            bestS = info[i].finishTime;
            index++;
        }
        else if (info[i].raceLength == 'M' && info[i].finishTime < bestM && info[i].withdrawn != 1) {
            winners[1] = i;
            bestM = info[i].finishTime;
            index++;
        }
        else if (info[i].raceLength == 'L' && info[i].finishTime < bestL && info[i].withdrawn != 1) {
            winners[2] = i;
            bestL = info[i].finishTime;
            index++;
        }
    }

    printf("\nSkier                                        Age Group  Category  Time\n");
    printf("----------------------------------------------------------------------\n");

    for (int j = 0; j < 3; j++) {
        if (winners[j] == -1 && j == 0) {
            printf("No award for this category!                  N/A        10 km     N/A\n");
        }
        else if (winners[j] == -1 && j == 1) {
            printf("No award for this category!                  N/A        25 km     N/A\n");
        }
        else if (winners[j] == -1 && j == 2) {
            printf("No award for this category!                  N/A        50 km     N/A\n");
        }
        else {
            convertTime(info[winners[j]].finishTime, &hours, &minutes);
            printf("%-44s %-10s %-9s %d%c%.2d\n", info[winners[j]].name, info[winners[j]].ageGroup, info[winners[j]].raceDistance, hours, ':', minutes);
        }
    }
    printf("\n");
}

// get valid name (40 characters)
void getName(struct SkierInfo* info) {
    int valid = 0, i;
    char name[41] = { '\0' };
    do {
        int nonLetter = 0;
        scanf("%40[^\n]s", &name);
        clearKeyboard();
        for (i = 0; i < strlen(name) && nonLetter == 0; i++) {
            if (isalpha(name[i]) == 0 && isspace(name[i]) == 0) {
                printf("Error, please enter a name: ");
                nonLetter = 1;
            }
        }
        if (nonLetter == 0) {
            valid = 1;
        }
    } while (valid == 0);
    strcpy(info->name, name);
}

// get age from 16-99
void getAge(struct SkierInfo* info) {
    info->age = getIntInRange(16, 99);
}

// converts time from 00:00 to decimal
double getMinutesSeconds(void) {
    int hours = 0, minutes = 0, valid = 0;
    char colon = { '\0' };
    do {
        scanf("%d%c%d", &hours, &colon, &minutes);
        clearKeyboard();
        if ((hours >= 0 && hours <= 99) && (minutes >= 0 && minutes <= 59) && (colon == ':')) {
            valid = 1;
        }
        else {
            printf("Error. Please enter correct time (HH:SS): ");
        }
    } while (valid == 0);
    return hours + (minutes / 60.0);
}

// get start, mid and finish times
void getTime(struct SkierInfo* info) {
    printf("Enter the start time (HH:SS): ");
    info->startTime = getMinutesSeconds();
    printf("Enter the mid time (HH:SS): ");
    info->midwayTime = getMinutesSeconds();
    printf("Enter the end time (HH:SS): ");
    info->finishTime = getMinutesSeconds();
}

// add a skier: (name, age raceType startTime midwayTime finishTime), only saves if you exit program safely
void addSkier(struct SkierInfo* info, int* numSkiers, FILE* fp) {
    int i = *numSkiers;
    int startHours = 0, startMinutes = 0, midHours = 0, midMinutes = 0, endHours = 0, endMinutes = 0;
    char race;
    // name
    printf("Please enter a name (Max 40 characters): ");
    getName(&info[i]);
    // age
    printf("Please enter an age (16 - 99): ");
    getAge(&info[i]);
    // race length
    printf("Please enter race category (S, M, L): ");
    race = raceType();
    info[i].raceLength = race;
    // start, mid, end times
    getTime(&info[i]);
    // add in helper info
    extraData(&info[i]);

    convertTime(info[i].startTime, &startHours, &startMinutes);
    convertTime(info[i].midwayTime, &midHours, &midMinutes);
    convertTime(info[i].finishTime, &endHours, &endMinutes);

    fprintf(fp, "\n%s, %d %c %d:%d %d:%d %d:%d", info[i].name, info[i].age, info[i].raceLength, startHours, startMinutes, midHours, midMinutes, endHours, endMinutes);
    printf("Did skier withdraw from race? (Y/N): ");
    if (yes() == 1) {
        info[i].withdrawn = 1;
        fprintf(fp, " W");
    }
    *numSkiers += 1;
    sort(info, *numSkiers);
    printf("\n");
}

int menu(void) {

    printf("************** X-Country Ski Race Reporting **************\n");
    printf("  1. Print top 3 skiers in a category\n");
    printf("  2. Print all skiers in a category\n");
    printf("  3. Print last 3 skiers in a category\n");
    printf("  4. Print winners in all categories\n");
    printf("  5. Add skier\n");
    printf("  0. Exit\n\n");
    printf("Select an option:> ");

    return getIntInRange(0, 5);
}

// main process
void manageSystem(void) {

    int choice, numSkiers = 0;

    FILE* fp = NULL;
    fp = fopen("data.txt", "a+");
    if (fp == NULL) {
        printf("Failed to open file.\n");
    }

    struct SkierInfo info[MAX_SKIERS] = { '\0' };

    numSkiers = allData(fp, info);
    sort(info, numSkiers);

    int yesNo = 0;

    do {
        choice = menu();
        switch (choice) {
        case 1:
            printf("\nPlease enter a category (S, M, L): ");
            topThree(info, numSkiers);
            pause();
            printf("\n");
            break;
        case 2:
            printf("\nPlease enter a category (S, M, L): ");
            allInCategory(info, numSkiers);
            pause();
            printf("\n");
            break;
        case 3:
            printf("\nPlease enter a category (S, M, L): ");
            lastThree(info, numSkiers);
            pause();
            printf("\n");
            break;
        case 4:
            allWinners(info, numSkiers);
            pause();
            printf("\n");
            break;
        case 5:
            addSkier(info, &numSkiers, fp);
            pause();
            printf("\n");
            break;
        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            yesNo = yes();
            fclose(fp);
            printf("\n");
            break;
        }
    } while (yesNo != 1);

    printf("Skier Management System: terminated\n");

}