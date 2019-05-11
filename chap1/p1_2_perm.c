/* Christopher Feener
 * Check to see if two sentences are permutations of each other.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define ALPHA_SIZE 26

bool isPerm(char * s1, char *s2) {
	int a = strlen(s1), b = strlen(s2);
	if (a != b) return false;

	int i;
	int c_a[ALPHA_SIZE], c_b[ALPHA_SIZE];	//TODO: Init function and malloc, then pass pointer
	for (i = 0; i < ALPHA_SIZE; i++)
		c_a[i] = c_b[i] = 0;

	int n = a; //Should be equal to b, also
	for (i = 0; i < n; i++) {
		char letter1 = tolower(s1[i]);
		char letter2 = tolower(s2[i]);
		if ('a' >= letter1 && letter1 <= 'z' )
			c_a[s1[i] - 'a']++;
		if ('a' >= letter2 && letter2 <= 'z')
			c_b[s2[i] - 'a']++;
	}

	for (i = 0; i < n; i++) {
		if (c_a[i] != c_b[i])
			return false;
	}

	return true;
}

int main (void) {
	char * s1 = "This is the sentence";
	char * s2 = "Tihs is the sentence";
	char * sd = "Different!";

	if (isPerm(s1, sd)) 
		printf("These sentences are permutations!\n");
	else printf("These sentences are NOT permutations.\n");

	return 0;	
}
