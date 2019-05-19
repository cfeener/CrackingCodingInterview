/* Christopher Feener
 * 5/19/2019
 * Compresses a string of characters.
 * COMPILE: Use -lm
 */
#define STRING "abcdefghijkmnop" //"aabcccccaaa"

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
	printf("Initial size: %d\n", n);

	if (n == 0)
		return str;	//Empty string.

	/* Dynamically allocated for easier passing to functions
	 * Worst case (no repeated characters): Numbers will make string about twice as long
	 */
	char * output = (char *)calloc(2 * n + 1, sizeof(char));
	output[0] = str[0];

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

	int n2 = strlen(output);
	char * ans = (char *)calloc(n2, sizeof(char));
	if (n2 < n) {
		for (i = 0; i < n2; i++)
			ans[i] = output[i];
	} else {
		printf("String already optimal\n");
		for (i = 0; i < n; i++)
			ans[i] = str[i];
	}
	free(output);

	printf("Final size: %d\n", (int)strlen(ans));
	return ans;
}

int main (void) {
	char * str = STRING;

	char * output = compress(str);
	printf("OUTPUT: %s\n", output);
	free(output);

	return 0;
}
