#include <stdio.h>
#include <stdlib.h>	//For calloc() and free()
#include <string.h>	//For strlen()

char * urlify(char * str) {
	int n = strlen(str);
	char * url = calloc(n, sizeof(char));

	//TODO
	return url;
}

int main (void) {
	char * str = "Mr John Smith   ";

	char * url = urlify(str);
	printf("%s\n", url);
	free(url);

	return 0;
}
