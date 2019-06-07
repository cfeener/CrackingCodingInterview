/* Christopher Feener
 * Started 6/6/2019
 * Rotate a string (in place)
 */
#define S1 "waterbottle"
#define S2 "lewaterbott"

#include <stdio.h>
#include <stdlib.h>	//For srand()
#include <time.h>	//For time()
#include <string.h>	//For strlen()
#include <stdbool.h>	//For true/false

bool isRotatedString(char s1[], char s2[]) {
	int n = strlen(s1), n2 = strlen(s2);
	if (n != n2)
		return false;

	int i = 0;
	bool is_found = true;
	while (i < n) {
		if (s1[0] == s2[i]) {
			is_found = true;
			int j;
			for (j = 0; j < n; j++) {
				int k = (i + j) % n;
				if (s1[j] != s2[k]) {
					is_found = false;
					break;
				}
			}
			if (is_found)
				return true;
		}
		i++;
	}

	return false;
}

int main (void) {
	static char s1[] = S1;
	static char s2[] = S2;

	if (isRotatedString(s1, s2))
		printf("True, these strings are rotated from each other!\n");
	else 
		printf("False, these strings are NOT rotated from each other.\n");

	return 0;
}
