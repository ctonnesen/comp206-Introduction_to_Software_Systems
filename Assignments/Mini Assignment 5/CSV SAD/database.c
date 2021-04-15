#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char show[] = "SHOW";
char delete[] = "DELETE";
char add[] = "ADD";

void noSpaces(char* s) {
	const char* d = s;
	do {
		while (*d == ' ') {
			++d;
		}
	} while (*s++ = *d++);
}

void showStuff() {
	FILE* csv = fopen("database.csv", "rt");
	if (csv == NULL) {
		printf("\n File opening failed");
		exit(1);
	}
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
		printf("Record %d: ID=%-5s NAME:%-5s AGE:%-5d GPA:%.1f\n", counter, ID, name, age, GPA);
		counter++;
	}
	fclose(csv);
}

void deleteStuff(char givenID[]) {
	FILE* csvread = fopen("database.csv", "rt");
	if (csvread == NULL) {
		printf("\n File opening failed");
		exit(1);
	}
	FILE* csvwrite = fopen("database.tmp", "wt");
	char buffer[800];
	char* ID;
	int oneAndDone = 0;
	while (fgets(buffer, sizeof(buffer), csvread)) {
		ID = strtok(buffer, ",");
		noSpaces(ID);
		if ((strcmp(ID, givenID) == 0) && (oneAndDone == 0)) {
			oneAndDone++;
			
		}
		else {
			fputs(buffer, csvwrite);
		}
	}
	system("rm database.csv");
	system("mv database.tmp database.csv");
	fclose(csvread);
	fclose(csvwrite);
	if (oneAndDone == 0) {
		printf("Sorry, the user was not found. Nothing was deleted.\n");
		exit(1);
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
	fprintf(csvappend, "%s,%s,%d,%f", gID, gName, age, GPA);
	fclose(csvappend);
}

void main(int argc, char* argv[]) {
	if (argc == 1) {
		printf("Your did not provide any arguments. Please enter: ./database CMD OPT1 OPT2 OPT3 OPT4 \n");
		exit(1);
	}
	if (strcmp(argv[1], show) == 0) showStuff();
	else if (strcmp(argv[1], delete) == 0) {
		if (argc <= 2) {
			printf("Name of record to delete is missing\n");
			exit(1);
		}
		deleteStuff(argv[2]);
	}
	else if (strcmp(argv[1], add) == 0) {
		if (argc <= 3) {
			printf("Missing ID, Name, AGE, and GPA Arguments");
			exit(1);
		}
		addStuff(argv[2], argv[3], argv[5], argv[5]);
	}
	else printf("The command you requested in invalid. Please select from one of these: SHOW, DELETE, ADD");

}