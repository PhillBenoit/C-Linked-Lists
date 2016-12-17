/*
 * House.h
 *
 *  Created on: Nov 17, 2016
 *      Author: Phill
 */
#ifndef HOUSE_H_
#define HOUSE_H_

int STR_LEN;
int MAX_OCCUPANTS;

int MIN_NUM;
int MAX_NUM;

int MIN_YEAR;
int MAX_YEAR;

char* NUMBER;
char* STREET;
char* YEAR;
char* OCC_NUM;
char* OCC_NAME;

struct house {
	int number;
	char street[11];
	int year;
	char resident[5][11];
};

void printHouse(struct house p);

#endif /* HOUSE_H_ */
