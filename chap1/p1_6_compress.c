/* Christopher Feener
 * 5/19/2019
 * Compresses a string of characters.
 * COMPILE: Use -lm
 */
#define STRING "aabcccccaaa"

#include <stdio.h>
#include <string.h>	//For strlen()
#include <stdlib.h>	//For calloc()
#include <math.h>	//For ceil()

void insertDigit(int temp_count, char * output) {
	int size = (int)((ceil(log10(temp_count)) + 1) * sizeof(char));
	char digits[size];
	sprintf(digits, "%d", temp_count);
	strcat(output, digits);
}

void insertChar(char ins, char * output) {
	char new_char[2];
	sprintf(new_char, "%c", ins);
	strcat(output, new_char);
}

char * compress (char * str) {
	int n = strlen(str);
	char * output = (char *)calloc(n, sizeof(char));

	if (n > 0)
		output[0] = str[0];
	else return output;	//Empty string.

	int i, j = 0, temp_count = 1;
	for (i = 1; i < n; i++) {
		if (str[i] == str[j])	//Count repeating characters
			temp_count++;
		else {
			insertDigit(temp_count, output);	//Insert count of repeated characters
			insertChar(str[i], output);	//Insert new character
			j = i;	//Take note of position of new character
			temp_count = 1;	//Reset count of repeated characters
		}
	}
	insertDigit(temp_count, output);	//Insert count of final sequence

	return output;
}

int main (void) {
	char * str = STRING;

	char * output = compress(str);
	printf("%s\n", output);
	free(output);

	return 0;
}
