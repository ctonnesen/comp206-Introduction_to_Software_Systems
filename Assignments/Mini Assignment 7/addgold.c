#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
	char matchForm[] = "inputAns";
	char matchMoney[] = "<form";
	char buffer [900];
	FILE* index = fopen("../index.html", "rt");
	if (index == NULL) {
		printf("\n File opening failed");
		exit(1);
	}
	
// Character arrays are defined for later matching and a pointer of type FILE is created
	
	int goldpieces;
	char *data = getenv("QUERY_STRING");
	sscanf(data, "gold=%d", &goldpieces);

// The QUERY_STRING is pulled from the website URL and parses the gold variable at the end	

	printf("Content-Type:text/html\n\n");
	while (fgets(buffer, sizeof(buffer), index)) {
		if (strstr(buffer, matchForm) != NULL) {
			printf("<form action=\"answer.cgi\" method =\"get\">");
		}else{

// If the current line of the index.html matches the "<form" character array, it is specially inserted to avoid a double cgi-bin/cgi-bin

		printf("%s", buffer);
		}
		if (strstr(buffer,matchMoney) != NULL) {
			printf ("<input type=\"hidden\" name=\"gold\" value=\"%d\">", goldpieces);
		}

// If the line containing the "inputAns" is found, then the hidden field line is printed next
	
		memset(buffer,0,sizeof(buffer));
	}
	fclose(index);
return 0;
}
