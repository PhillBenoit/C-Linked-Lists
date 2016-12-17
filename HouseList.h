/*
 * HouseList.h
 *
 *  Created on: Nov 17, 2016
 *      Author: Phill
 */

#include "House.h"

#ifndef HOUSELIST_H_
#define HOUSELIST_H_

struct houseElement {
	struct house h;
	struct houseElement *next;
	struct houseElement *previous;
};

int LIST_COUNTER;
int LIST_MAX;

void addHouse(struct house a);
void printElement(struct house output);
void printList();
void deleteHouse(int n, char a[]);
struct houseElement *findHouse(int n, char a[]);
void displayHouse(int n, char a[]);

#endif /* HOUSELIST_H_ */
