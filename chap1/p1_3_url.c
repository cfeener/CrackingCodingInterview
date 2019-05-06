#include <stdio.h>
#include <string.h>

int main (void) {
	char * url = "Mr John Smith   ";

	int n = strlen(url);

	char * delim = " ";
	char * token = strtok(url, delim);
	printf("%s", token);
	token = strtok(NULL, delim);

	while (token != NULL) {
		printf("\%20%s", token);
		token = strtok(NULL, delim);
	}

	return 0;
}
