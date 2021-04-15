// Christian Tonnesen
// 260847409


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void noSpaces(char* s) {
	const char* d = s;

// created a char pointer equal to input pointer. Both point to same address 

	do {
		while (*d == ' ') {
			++d;
		}
	} while ((*s++ = *d++));

// Whenever d equals a empty space, it is incremented forward, so long as s and d are equal to each other. This means that we skip over 
// all the space characters and remake our original string without pointers
// This function serves to eliminate any blank spaces in the strings

}

void showStuff() {
	FILE* csv = fopen("database.csv", "rt");
	if (csv == NULL) {
		printf("\n File opening failed");
		exit(1);
	}

// A FILE pointer is created

	char buffer[800];
	char *Gptr, *ID, *name, *cAge, *cGPA;
	int counter = 1;
	while (fgets(buffer, sizeof(buffer), csv)) {
		ID = strtok(buffer, ",");
		noSpaces(ID);
		name = (strtok(NULL, ","));
		noSpaces(name);
		cAge = (strtok(NULL, ","));
		noSpaces(cAge);
		int age = atoi(cAge);
		cGPA = (strtok(NULL, ","));
		noSpaces(cGPA);
		double GPA = strtod(cGPA, &Gptr);
	
// While fgets goes through the CSV, we use a strtok with a "," delimitter to pull out the different parts
// These are then put through our noSpaces function and assigned to the char pointer or int/double variable they belong to

		printf("Record %d: ID=%-5s NAME:%-5s AGE:%-5d GPA:%.1f\n", counter, ID, name, age, GPA);
		counter++;

// The variables are printed to the screen with right justified syntax

	}
	fclose(csv);
}

void deleteStuff(char givenID[]) {
	FILE* csvread = fopen("database.csv", "rt");
	if (csvread == NULL) {
		printf("\n File opening failed");
		exit(1);
	}

// Again, a FILE pointer is created for reading the CSV

	FILE* csvwrite = fopen("database.tmp", "wt");
	
// A FILE pointer is also created for writing to the new file

	char buffer[800];
    	char* ID;
    	int oneAndDone = 0;
    	while (fgets(buffer,sizeof(buffer),csvread)) {
        	if (oneAndDone == 0) {
            		char bcopy[800];
            		strcpy (bcopy, buffer);
            		ID = strtok(bcopy, ",");

// A new char array is made and the buffer is copied to it
// A strtok is taken of the bcopy to find the current ID

            		noSpaces(ID);
            		if (strcmp(ID, givenID) == 0) {
                	oneAndDone = 1;
                	continue;
        
// If the ID matches the provided one, then the row is skipped and the next begins. It is written directly to the tmp

			}
        	}
        	fprintf(csvwrite, "%s", buffer);
    	}
	fclose(csvread);
	fclose(csvwrite);
	system("rm database.csv");
	system("mv database.tmp database.csv");
		if (oneAndDone == 0) {
		printf("Sorry, the user was not found. Nothing was deleted.\n\n");
		exit(1);	

// The pointers are closed and old CSV deleted. There also exists a check out here to see if there was even a matching result, as seen from the oneAndDone

	}
}

void addStuff(char gID[], char gName[], char gAge[], char gGPA[]) {
	char* Gptr;
	int age = atoi(gAge);
	double GPA = strtod(gGPA, &Gptr);
	FILE* csvappend = fopen("database.csv", "at");
	if (csvappend == NULL) {
		printf("\n File opening failed");
		exit(1);
	}

// A variable of each type of value is created to match with the passed input. The appropriate actions are taken for the age and GPA, turning them to int
// and double respectively

	fprintf(csvappend, "%s,%s,%d,%.1f", gID, gName, age, GPA);
	fclose(csvappend);
}


// The variables are appended line by line and then then the file is closed

char show[] = "SHOW";
char delete[] = "DELETE";
char add[] = "ADD";

// These above global character arrays correspond to possible commands to be input

void main(int argc, char* argv[]) {
	if (argc == 1) {
		printf("Your did not provide any arguments. Please enter: ./database CMD OPT1 OPT2 OPT3 OPT4 \n\n");
		exit(1);
	}

// This if checks for the presence of any commands and terminates if nothing was passed

	if (strcmp(argv[1], show) == 0) showStuff();
	else if (strcmp(argv[1], delete) == 0) {
		if (argc <= 2) {
			printf("Name of record to delete is missing\n\n");
			exit(1);
		}
		deleteStuff(argv[2]);
	}

// The first if checks for if the command is SHOW, and if so, runs the function. Else, it checks if it corresponds to DELETE and sees if there's a
// ID to run. If not, an error terminates.

	else if (strcmp(argv[1], add) == 0) {
		if (argc <= 5) {
			printf("Missing ID, Name, AGE, and GPA Arguments\n\n");
			exit(1);
		}
		addStuff(argv[2], argv[3], argv[4], argv[5]);
	}

// A final if statement checks to see if it's equal to ADD, and if so, ensures there are 4 values to be appended to the file and calls the function

	else printf("The command you requested in invalid. Please select from one of these: SHOW, DELETE, ADD\n\n");

}

// If the input matches nothing, then the program says the input command was invalid
