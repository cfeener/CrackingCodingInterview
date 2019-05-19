/* Christopher Feener
 * 5/12/2019
 * Verifies that two words have at most one different character.
 * NOTE: This was originally intended to process words, and 
 * 	later incorporated the ability for full sentences.
 */

#define STRING1 "b....a324l654	e.... 45"
#define STRING2 "pale"

#include <stdio.h>
#include <string.h>	//For strlen()
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>	//For abs()
#include <ctype.h>	//For tolower()

#define ALPHA 26 	//Size of alphabet.

bool oneAway (char * s1, char * s2) {
	assert(s1 != NULL && s2 != NULL);

	int n1 = strlen(s1), n2 = strlen(s2);
	int non_letter1 = 0, non_letter2 = 0;	//Used for offsetting length of strings due to punctuation.
	int freq1[ALPHA], freq2[ALPHA];
	int matches = 0;
	int i;
	for (i = 0; i < ALPHA; i++)
		freq1[i] = freq2[i] = 0;

	for (i = 0; i < n1; i++) {	//Count letter frequency in 1st string
		if (!isalpha(s1[i]))	//Count spaces and punctuation to ignore
			non_letter1++;
		freq1[tolower(s1[i]) - 'a']++;
	}

	for (i = 0; i < n2; i++) {	//Count frequency in 2nd string
		if (!isalpha(s2[i]))
			non_letter2++;
		freq2[tolower(s2[i]) - 'a']++;
	}

	for (i = 0; i < ALPHA; i++) {	//Count matches
		if ((freq1[i] != 0) && (freq1[i] == freq2[i]))	//Must be a non-zero match
			matches += freq1[i];	//Increase by letters that match! (Not entries that match.)
	}

	if ((abs((n1 - non_letter1) - matches) > 1) 
		|| (abs((n2 - non_letter2) - matches) > 1))
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
