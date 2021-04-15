#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char north[] = "NORTH", south[] = "SOUTH", east[] = "EAST", west[] = "WEST", gold[] = "GOLD", correct[] = "128";

int  main() {
	char input[100];
	char* data = getenv("QUERY_STRING");
	sscanf(data, "?inputAns=%s", input);

	printf("Content-Type:text/html\n\n");
	printf("<html>");

	if (strcmp(input, north) == 0) {
		printf("<a href=\"https://www.cs.mcgill.ca/~nhawar\">Press HERE to go North</a>");
	}
	else if (strcmp(input, south) == 0) {
		printf("<a href=\"https://www.cs.mcgill.ca/~rsowa\">Press HERE to go South</a>");
	}
	else if (strcmp(input, east) == 0) {
		printf("<a href=\"https://www.cs.mcgill.ca/~bemili\">Press HERE to go East</a>");
	}
	else if (strcmp(input, west) == 0) {
		printf("<a href=\"https://www.cs.mcgill.ca/~akragl\">Press HERE to go West</a>");
	}
	else if (strcmp(input, gold) == 0)  printf("<body> Hey There </body>");

}
