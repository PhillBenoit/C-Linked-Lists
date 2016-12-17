/*
 * hello.c
 *
 *  Created on: Nov 17, 2016
 *      Author: Phill
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "House.h"
#include "HouseList.h"
#include "Input.h"

char* MENU = "Please select an option:";

int MIN_MENU = 0;
int MAX_MENU = 5;

void getOccupants(struct house h) {
	int counter = 0;

	//asks for a number of occupants
	int countMax = getInt(OCC_NUM, 0, MAX_OCCUPANTS);

	//loops to add occupants
	while (counter < countMax) {
		strcpy(h.resident[counter], getString(OCC_NAME, STR_LEN));
		counter++;
	}

	//allocates null space for empty occupants
	while (counter < MAX_OCCUPANTS) {
		strcpy(h.resident[counter], "");
		counter++;
	}

	//adds the house to the list
	addHouse(h);
}

//uses input functions to populate information about a house
//passes to previous method to add occupants
void menuEnterHouse() {
	printf("---Enter a House---\n");
	struct house h;
	h.number = getInt(NUMBER, MIN_NUM, MAX_NUM);
	strcpy(h.street, getString(STREET, STR_LEN));
	h.year = getInt(YEAR, MIN_YEAR, MAX_YEAR);
	getOccupants(h);
}

//displays all houses in the list
void menuDisplayList() {
	printf("---Display List of Houses---\n");
	printList();
	printf("----------------------------\n");
}

//gets search information then attempts to find and display the specified house
void menuDisplayHouse() {
	printf("---Display a House---\n");
	int number = getInt(NUMBER, MIN_NUM, MAX_NUM);
	char street[STR_LEN+1];
	strcpy(street, getString(STREET, STR_LEN));
	displayHouse(number, street);
}

//gets search information then attempts to find and delete the specified house
void menuDeleteHouse() {
	printf("---Delete a House---\n");
	int number = getInt(NUMBER, MIN_NUM, MAX_NUM);
	char street[STR_LEN+1];
	strcpy(street, getString(STREET, STR_LEN));
	deleteHouse(number, street);
}

//adds 3 pre-built houses to the list.  Used for testing.
void menuPopulateList() {
	printf("---Populate List---\n");
	struct house h;

	h.number = 1600;
	strcpy(h.street, "Pen avenue");
	h.year = 1900;
	strcpy(h.resident[0], "Barack");
	strcpy(h.resident[1], "Michelle");
	strcpy(h.resident[2], "Sasha");
	strcpy(h.resident[3], "Malia");
	strcpy(h.resident[4], "Bo");
	addHouse(h);

	h.number = 177;
	strcpy(h.street, "Bleeker");
	h.year = 1999;
	strcpy(h.resident[0], "Steven");
	strcpy(h.resident[1], "Wong");
	strcpy(h.resident[2], "");
	strcpy(h.resident[3], "");
	strcpy(h.resident[4], "");
	addHouse(h);

	h.number = 300;
	strcpy(h.street, "Madison");
	h.year = 1972;
	strcpy(h.resident[0], "Reed");
	strcpy(h.resident[1], "Sue");
	strcpy(h.resident[2], "Johny");
	strcpy(h.resident[3], "Ben");
	strcpy(h.resident[4], "");
	addHouse(h);
}

//visual display of options
void displayMenu() {
	printf("**************************************************\n");
	printf("*       Neighborhood Association List            *\n");
	printf("*                                                *\n");
	printf("*    1) Display the current list                 *\n");
	printf("*                                                *\n");
	printf("*    2) Display a house on the list              *\n");
	printf("*                                                *\n");
	printf("*    3) Add a house to the list                  *\n");
	printf("*                                                *\n");
	printf("*    4) Remove a house from the list             *\n");
	printf("*                                                *\n");
	printf("*    5) Add 3 pre-built houses to the list       *\n");
	printf("*                                                *\n");
	printf("*                                                *\n");
	printf("*                                                *\n");
	printf("*    0) Exit                                     *\n");
	printf("*                                                *\n");
	printf("**************************************************\n");
}

//delay to allow user to read screen before returning to the main menu
void pauseProgram() {
	int sleepCounter = 5;
	printf("Returning to menu in");
	while (sleepCounter > 0) {
		printf(" %d", sleepCounter);
		fflush(stdout);
		sleep(1);
		sleepCounter--;
	}
	printf("\n");
}

//main loop of the program.  Displays options and asks for input.
//repeats until the user enters 0
void runMenu() {
	displayMenu();
	int selection = getInt(MENU, MIN_MENU, MAX_MENU);
	while (selection != 0) {
		switch (selection) {
			case 1 : menuDisplayList(); break;
			case 2 : menuDisplayHouse(); break;
			case 3 : menuEnterHouse(); break;
			case 4 : menuDeleteHouse(); break;
			case 5 : menuPopulateList(); break;
		}
		pauseProgram();
		displayMenu();
		selection = getInt(MENU, MIN_MENU, MAX_MENU);
	}
}

//my first program in C adapted to start and end the menu
int main() {
	printf("Hello World!!!\n");
	runMenu();
	printf("---End of Program---\n");
	return 0;
}
