// Christian Tonnesen
// 260847409

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char north[]="NORTH",  south[]="SOUTH", east[]="EAST", west[]="WEST", goldSTR[]="GOLD", correct[]="128", separate[]="&";

// Define character arrays to match possible inputs

int  main() {
	char input[100];
	int goldpieces = -100;
	char *data = getenv("QUERY_STRING");	
	printf("Content-Type:text/html\n\n");
	printf("<html>");

// The QUERY STRING is passed to the char data pointer

	if (strstr(data, separate) == NULL) {
		sscanf(data, "inputAns=%s", input);

// If the "&" symbol is not detected, then the program assumes this is the player's first stop. Thus, there is no need to parse the gold

	} else {
		int counter = 0;
		int goldCounter = 0;
		char *tempInp = malloc(sizeof(data)+1);
		char *tempGold = malloc (sizeof(data)+1);
		for (int i =0; i < strlen(data); i++) {
			if (data[i]=='&') {
				counter++;
				continue;
			}
			if (counter==0) {
				tempInp[i]=data[i];
			} else {
				tempGold[goldCounter]=data[i];
				goldCounter++;
			}

// Two temp arrays pointers are used to store the first part of the QUERY_STRING (input) and the second (gold value)

		}
	sscanf(tempInp, "inputAns=%s", input);
	sscanf(tempGold, "gold=%d", &goldpieces);
	}		

// A sscanf pulls out the values from the strings and assigns them to their spots

	if (goldpieces == -100) goldpieces = 10;

// In the event that the goldpieces has not been modified, set it equal to 10 as this is the first room

	if (goldpieces<=0) {
		printf("<body> You Lose! Better Luck Next Time! </body>");
		printf("<h>Gold = %d</h>", goldpieces);
		return(0);
		}
	if (100<=goldpieces) {
		printf("<body> You Win! Good Job! </body>");
		printf("<h>Gold = %d</h>", goldpieces);
		return(0);
		}

// These win and lose conditions catch the player whenever they submit with the corresponding gold amount

	if (strcmp(input, north)==0) {
		printf("<a href=\"https://www.cs.mcgill.ca/~nhawar/cgi-bin/addgold.cgi?gold=%d\" >Press HERE to go North</a>", goldpieces);
	} else if (strcmp(input, south)==0) {
		printf("<a href=\"https://www.cs.mcgill.ca/~rsowa/cgi-bin/addgold.cgi?gold=%d\" >Press HERE to go South</a>", goldpieces);
	} else if (strcmp(input, east)==0)  {
		printf("<a href=\"https://www.cs.mcgill.ca/~bemili/cgi-bin/addgold.cgi?gold=%d\" >Press HERE to go East</a>", goldpieces);
	} else if (strcmp(input, west)==0)  {
		printf("<a href=\"https://www.cs.mcgill.ca/~akragl/cgi-bin/addgold.cgi?gold=%d\" >Press HERE to go West</a>", goldpieces);
	} else if (strcmp(input, goldSTR)==0) {
		printf ("<body> Your gold total is: </body>");
		printf("%d", goldpieces);
		printf("<br></br>");
                printf("<a href=\"https://www.cs.mcgill.ca/~ctonne2/cgi-bin/addgold.cgi?gold=%d\" >Press HERE to go back</a>", goldpieces); 

// An if-else ladder finds out which command the player has input by comparing the input and the declared global strings

	} else if (strcmp(input, correct) == 0) {	
		goldpieces+=10;
		printf("<body> You are correct! Accept 10 gold as a reward </body>");
		printf("<a href=\"https://www.cs.mcgill.ca/~ctonne2/cgi-bin/addgold.cgi?gold=%d\" >Press HERE to go back</a>",goldpieces);
	} else { 
		goldpieces-=5; 
		printf("<body> That was not the correct answer. Womp Womp. </body>");
		printf("<a href=\"https://www.cs.mcgill.ca/~ctonne2/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go back</a>", goldpieces);
		} 					

// In the event of a incorrect or correct answer, the appropriate amount of gold is removed and they are given a link back to the original page

	printf("</html>");

	return 0;
}	
