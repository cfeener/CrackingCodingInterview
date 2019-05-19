/* Christopher Feener
 * 5/19/2019
 * Compresses a string of characters.
 * COMPILE: Use -lm and -g tags
 */
#define STRING "aabcccccaaa"

#include <stdio.h>
#include <string.h>	//For strlen()
#include <stdlib.h>	//For calloc()
#include <math.h>	//For ceil()

char * compress (char * str) {
	int n = strlen(str);
	char * output = (char *)calloc(n, sizeof(char));

	if (n > 0)
		output[0] = str[0];
	else return output;	//Empty string.

	int i, j = 0, temp_count = 1;
	for (i = 1; i < n; i++) {
		if (str[i] == str[j]) {
			temp_count++;
		} else {
			int size = (int)((ceil(log10(temp_count)) + 1) * sizeof(char));
			char digits[size];
			sprintf(digits, "%d", temp_count);
			strcat(output, digits);

			char new_char[2];
			sprintf(new_char, "%c", str[i]);
			strcat(output, new_char);
			j = i;
			temp_count = 1;
		}
	}

	return output;
}

int main (void) {
	char * str = STRING;

	char * output = compress(str);
	printf("%s\n", output);
	free(output);

	return 0;
}
