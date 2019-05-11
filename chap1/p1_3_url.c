#include <stdio.h>
#include <stdlib.h>	//For calloc() and free()
#include <string.h>	//For strlen()
#include <assert.h>	//For assert()

char * urlify(char * str) {
	int n = strlen(str);
	char * url = calloc(n, sizeof(char));

	int i = n - 1;
	while (str[i] == ' ')
		i--;	//Iterate to last character

	int j = n - 1;
	while (i >= 0) {
		if (str[i] == ' ') {
			assert(j > 2);
			url[j - 2] = '%'; url[j - 1] = '2'; url[j] = '0';
			j -= 3;
		} else {
			url[j--] = str[i];
		}
		i--;
	}

	return url;
}

int main (void) {
	char * str = "Mr John Smith    ";

	char * url = urlify(str);
	printf("%s\n", url);
	free(url);

	return 0;
}
