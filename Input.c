/*
 * Input.c
 *
 *  Created on: Dec 4, 2016
 *      Author: Phill
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//q is the input question
//max is the maximum number of characters
char *getString(char *q, int max) {
	//large buffer for input
	char *buffer = malloc(255*sizeof(char));

	printf("%s\n", q);
	//flushing appears to be necessary for the Eclipse terminal emulator
	fflush(stdout);
	scanf("%s", buffer);

	//runs loop while input is too long
	while (strlen(buffer) > max) {
		printf("Input not recognized.  Please use shorter input."
				" (maximum %d characters)\n", max);
		printf("%s\n", q);
		fflush(stdout);
		scanf("%s", buffer);
	}

	//shrink buffer to max + 1
	buffer = realloc(buffer, (max+1)*sizeof(char));

	//explicitly use the last space for a null character
	buffer[max] = '\0';

	printf("You entered: %s\n", buffer);
	return buffer;
}

//calls getString for input then converts it for return
int intLoop(char *q) {
	char *returnInt;

	//invokes getString with a 9 max length. smaller than the
	//int max of over 2 billion but good enough for our purposes
	returnInt = getString(q, 9);

	return atoi(returnInt);
}

//invokes intLoop while the integer is out of bounds for specifications
int getInt(char *q, int min, int max) {
	int returnInt = intLoop(q);
	while (returnInt < min || returnInt > max) {
		printf("Input (%d) out of bounds.  Please use a number between. (%d) and (%d)\n", returnInt, min, max);
		returnInt = intLoop(q);
	}
	return returnInt;
}
