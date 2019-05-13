/* Christopher Feener
 * 5/12/2019
 * Verfies that two words have at most one different character.
 */

#define STRING1 "This will be awesome!"
#define STRING2 "This will be awesome!"

#include <stdio.h>
#include <string.h>	//For strlen()
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>	//For abs()
#include <ctype.h>	//For tolower()

#define ALPHA 26 	//Size of alphabet.

bool oneAway (char * s1, char * s2) {
	assert(s1 != NULL && s2 != NULL);

	int n1 = strlen(s1), n2 = strlen(s2), matches = 0;
	int freq1[ALPHA], freq2[ALPHA];
	int i;
	for (i = 0; i < ALPHA; i++)
		freq1[i] = freq2[i] = 0;

	for (i = 0; i < n1; i++)
		freq1[tolower(s1[i]) - 'a']++;

	for (i = 0; i < n2; i++)
		freq2[tolower(s2[i]) - 'a']++;

	for (i = 0; i < ALPHA; i++) {	//Count matches
		if ((freq1[i] != 0) && (freq1[i] == freq2[i]))	//Must be a non-zero match
			matches++;
	}

	if ((abs(n1 - matches) > 1) || (abs(n2 - matches) > 1))
		return false;	//If more than one letter was not a match, false

	return true;
}

int main (void) {
	char * s1 = STRING1;
	char * s2 = STRING2;

	if (oneAway(s1, s2))
		printf("True!\n");
	else 
		printf("False.\n");

	return 0;
}
