/*
 * House.c
 *
 *  Created on: Nov 17, 2016
 *      Author: Phill
 */

#include "House.h"
#include <stdio.h>
#include <string.h>

int STR_LEN = 10; //Maximum length of street and person names
int MAX_OCCUPANTS = 5; //Maximum number of house occupants

//min / max street number
int MIN_NUM = 1;
int MAX_NUM = 99999999;

//min / max building year
int MIN_YEAR = 1900;
int MAX_YEAR = 2016;

//input questions
char* NUMBER = "Please enter a street number:";
char* STREET = "Please enter a street name:";
char* YEAR = "Please enter the year it was constructed:";
char* OCC_NUM = "Please enter the number of occupants:";
char* OCC_NAME = "Please enter an occupant's name:";

void printHouse(struct house p) {
	printf("==================================================\n");
	printf("Address: %d %s \nYear it was constructed: %d\n",
			p.number, p.street, p.year);
	//will not print any residents if none exist
	if (strcmp(p.resident[0], "") != 0) {
		printf("Residents:\n");
	}
	int counter = 0;
	while (counter < MAX_OCCUPANTS && strcmp(p.resident[counter], "") != 0) {
		printf("  %s\n", p.resident[counter]);
		counter++;
	}
	printf("--------------------------------------------------\n");
}
