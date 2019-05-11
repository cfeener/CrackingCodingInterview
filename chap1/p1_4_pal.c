/* Christopher Feener
 * This is a palindrome checking function for CtCI problem 1.4
 */

#define STRING "Madam, I'm Adam!"

#include <stdio.h>
#include <stdbool.h>	//For general boolean types and functions
#include <ctype.h>	//For tolower()
#include <string.h>	//For strlen()

#define ALPHA 26

bool hasPalindrome (char * str) {
	int freq[ALPHA], i;
	for (i = 0; i < ALPHA; i++)
		freq[i] = 0;

	int n = strlen(str);
	for (i = 0; i < n; i++) {
		freq[tolower(str[i]) - 'a']++;
	}

	bool is_middle = false;
	for (i = 0; i < ALPHA; i++) {
		if (freq[i] % 2 == 1) {	//Odd number of frequency means this could be a middle character, but there may only be 1.
			if (!is_middle)
				is_middle = true;
			else return false;	//If the middle is already taken, symmetry is destroyed.
		} else
			;	//Do nothing;
	}
	return true;
}

int main (void) {
	char * str = STRING;

	if (hasPalindrome(str))
		printf("Has a palindrome!\n");
	else printf("Does NOT have a palindrome.\n");

	return 0;
}
