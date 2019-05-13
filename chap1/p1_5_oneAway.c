/* Christopher Feener
 * 5/12/2019
 * Verfies that two words have at most one different character.
 */

#define STRING1 "ple"
#define STRING2 "pale"

#include <stdio.h>
#include <string.h>	//For strlen()
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>	//For abs()
#include <ctype.h>	//For tolower()

#define ALPHA 26 	//Size of alphabet.

bool diff (char * s1, char * s2) {
	assert(s1 != NULL && s2 != NULL);

	int n1 = strlen(s1), n2 = strlen(s2);
	int freq1[ALPHA], freq2[ALPHA];
	int i;
	for (i = 0; i < ALPHA; i++)
		freq1[i] = freq2[i] = 0;

	for (i = 0; i < n1; i++)
		freq1[tolower(s1[i]) - 'a']++;

	for (i = 0; i < n2; i++)
		freq2[tolower(s2[i]) - 'a']++;

	bool isUnequal = false;
	for (i = 0; i < ALPHA; i++) {	//Traverse frequencies to make sure there is only a one letter difference (or less.)
		if (freq1[i] != freq2[i]) {	//If unequal
			if (isUnequal)		//If another inequality already exists, false
				return false;
			if (abs(freq1[i] - freq2[i]) > 1)	//Otherwise, inequality must be 1
				return false;
			isUnequal = true;
		}
	}

	return true;
}

int main (void) {
	char * s1 = STRING1;
	char * s2 = STRING2;

	if (diff(s1, s2))
		printf("True!\n");
	else 
		printf("False.\n");

	return 0;
}
