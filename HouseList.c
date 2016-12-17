/*
 * HouseList.c
 *
 *  Created on: Nov 17, 2016
 *      Author: Phill
 */

#include "House.h"
#include "HouseList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//uses first/last system for more efficiently
struct houseElement *first, *last;

//counter of houses and max size of the list
int LIST_COUNTER = 0;
int LIST_MAX = 10;

//adds a house to the list
void addHouse(struct house a) {
	if (LIST_COUNTER < LIST_MAX) {
		struct houseElement *link = (struct houseElement*)
										malloc(sizeof(struct houseElement));
		link->h = a;

		//Initializes first and last if empty
		if (first == NULL) {
			first = link;
			last = link;
		}

		//sets up the link in the list
		link->previous = last;
		last->next = link;
		link->next = NULL;
		last = link;

		LIST_COUNTER++;
		printf("The house was added successfully.\n");
		printHouse(last->h);
	} else {
		printf("The list is full. (Max size: %d)\n", LIST_MAX);
	}
}

//only prints street number and name
void printElement(struct house output) {
	printf("%d %s\n", output.number, output.street);
}

//loops through the while list and displays it using previous method
void printList() {
	struct houseElement *output = first;

	if (output == NULL) {
		printf("No houses to display.\n");
	}

	while (output != NULL) {
		printElement(output->h);
		output = output->next;
	}
}


void deleteHouse(int n, char a[]) {
	struct houseElement* toBeRemoved = findHouse(n, a);
	if (toBeRemoved != NULL) {
		// 4 cases used to identify how to delete the house
		if (toBeRemoved == first  && toBeRemoved != last) {
			first = toBeRemoved->next;
			first->previous = NULL;
		}
		if (toBeRemoved == last && toBeRemoved != first) {
			last = last->previous;
			last->next = NULL;
		}
		if (toBeRemoved == last && toBeRemoved == first) {
			last = NULL;
			first = NULL;
		}
		//makes use of previous / next linking to allow for
		//universal functionality in the find method
		if (toBeRemoved->next != NULL && toBeRemoved->previous != NULL) {
			toBeRemoved->previous->next = toBeRemoved->next;
			toBeRemoved->next->previous = toBeRemoved->previous;
		}
		LIST_COUNTER--;
		printf("%d %s was removed from the list.\n", n, a);
	}
}

//finds a house then displays it
void displayHouse(int n, char a[]) {
	struct houseElement* h;
	h = findHouse(n, a);
	if (h != NULL) {
		printHouse(h->h);
	}
}

//this function is used in two places
//finding a house to display and finding a house to delete
struct houseElement *findHouse(int n, char a[]) {
	struct houseElement* returnElement = first;

	while (returnElement != NULL && returnElement->h.number != n &&
			strcmp(returnElement->h.street, a) != 0) {
		returnElement = returnElement->next;
	}

	if (returnElement->h.number == n && strcmp(returnElement->h.street, a) == 0) {
		return returnElement;
	}

	printf("The house you entered was not found in the list.\n");
	return NULL;
}
