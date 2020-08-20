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

#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#include <stdio.h>

/********************************************************/
/* Define the missing members for the SkierInfo data    */
/* used to store Skier information read from a file     */
/********************************************************/
struct SkierInfo
{
	char name[40];
	int age;
	char ageGroup[8];
	char raceLength;
	char raceDistance[6];
	double startTime;
	double midwayTime;
	double finishTime;
	//1 if withdrawn, 0 if not
	int withdrawn;
};



/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!        DO NOT ALTER THE CONTENTS BELOW       !!!*/
/*!!!             ( function prototype )           !!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

double readTime(FILE* fp);

int readFileRecord(FILE* fp, struct SkierInfo* info);

void clearKeyboard(void);

void pause(void);

int getInt(void);

int getIntInRange(int min, int max);

int yes(void);

char raceType(void);

void convertTime(double decimalTime, int* hours, int* minutes);

void sort(struct SkierInfo* info, int size);

void extraData(struct SkierInfo* info);

int allData(FILE* fp, struct SkierInfo* info);

void printThree(struct SkierInfo* info, int* winners, int index);

void lastThree(struct SkierInfo* info, int numSkiers);

void topThree(struct SkierInfo* info, int numSkiers);

void allInCategory(struct SkierInfo* info, int numSkiers);

void allWinners(struct SkierInfo* info, int numSkiers);

void getName(struct SkierInfo* info);

void getAge(struct SkierInfo* info);

double getMinutesSeconds(void);

void getTime(struct SkierInfo* info);

void addSkier(struct SkierInfo* info, int* numSkiers, FILE* fp);

int menu(void);

void manageSystem(void);

#endif

