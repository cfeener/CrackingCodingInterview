/* Christopher Feener
 * Makes a valid string a URL. May try processing in-place.
 * Main worry is losing current robustness of program.
 */

#include <stdio.h>
#include <stdlib.h>	//For calloc() and free()
#include <string.h>	//For strlen()
#include <assert.h>	//For assert()

#define ADDED_CHARS 2

int spacesExpected(char * str) {
	int n = strlen(str);
	int true_spaces = 0;

	int i = n - 1;
	while (str[i] == ' ')
		i--;

	while (i >= 0) {
		if (str[i] == ' ')
			true_spaces++;
		i--;
	}

	return ADDED_CHARS * true_spaces;
}


char * urlify(char * str) {
	int n = strlen(str);
	int i = n - 1, spaces = 0;

	while (str[i] == ' ') {
		spaces++;
		i--;	//Iterate to last character
	}
	if (spaces != spacesExpected(str)) {	//Main error check
		printf("Wrong number of trailing spaces in initial sentence.\n");
		exit(1);
	}

	char * url = calloc(n, sizeof(char));
	int j = n - 1;
	while (i >= 0) {
		if (str[i] == ' ') {
			url[j - 2] = '%'; url[j - 1] = '2'; url[j] = '0';
			j -= 3;
		} else 
			url[j--] = str[i];
		i--;
	}

	return url;
}

int main (void) {
	char * str = "Mr John Smith    ";	//Since this has 2 real spaces, there are 4 spaces at the end.

	char * url = urlify(str);
	printf("%s\n", url);
	free(url);

	return 0;
}
