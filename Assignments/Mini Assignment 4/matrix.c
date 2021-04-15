// Christian Tonnesen
// 260847409


#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void fillMatrix(int matrix[ROWS][COLS]) {
	for (int i=0;i<ROWS;i++) {
		for (int j=0;j<COLS;j++) {
			srand(clock());
			
			// The seed of the random function is set to change with the clock, so there should be no overlap between matrices 

			int random = rand() % 100 + 1;
			matrix[i][j] = random;
			
			// The for loops iterate through the matrix and fill with random numbers
		}
	}				
}

void printMatrix(int matrix[ROWS][COLS]) {
	for (int i=0;i<ROWS;i++) {
	printf ("{");
		for (int j=0;j<COLS;j++) {
			if (j != 4) {
			printf("%d, ", matrix[i][j]);
			
			// The for loops index through the matrix and print the int at the indexed position with a comma and space	
			
			}else{
			printf("%d", matrix[i][j]);
			}

			// If it's the final number in the row, then it just prints the integer with no space
			
		}		
	printf ("}\n");
		}				
printf("\n\n");
}

void transposeMatrix(int matrix[ROWS][COLS]) {
	int temp = 0;
	for (int i=0;i<ROWS;i++) {
		for (int j=0;j<i;j++) {

		// The for loops iterate through the bottom half of the matrix, with indexing stopping right before you cross the diagonal line		
 		
		temp = *(*(matrix+i)+j);
		*(*(matrix+i)+j) = *(*(matrix+j)+i); 
		*(*(matrix+j)+i) = temp;	
		
		// The integer at the indexed position is saved in a temp, then the int is exhanged with its transposed number. The transpose position is then provided the int at the original position 	

		}	
	}
}

void multiplyMatrix(int m1[2][COLS], int m2[ROWS][COLS], int resultMatrix[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j =0; j < COLS; j++) {
			resultMatrix[i][j]=0;
		}
	}

	// A for loop goes through the result matrix and sets it to 0 in all positions

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < COLS; j++) {
			for (int k = 0; k < ROWS; k++) {	
				resultMatrix[i][j]+=m1[i][k]*m2[k][j];
			
				// The triple for loops go through the array and place the product of the two matrices in the result matrix position. The third for loop is what allows for the matrix multiplication through going across matrix1 row and down matrix2 column
			
			}
		}	
	}
}

int  main (int argc, char *argv[])  {
	int matrix[ROWS][COLS];

	fillMatrix(matrix);

	printMatrix(matrix);

	transposeMatrix(matrix);

	printMatrix(matrix);

	int matrix2[2][COLS]={0,1,2,3,4,5,6,7,8,9};

	int matrixResult[ROWS][COLS];

	multiplyMatrix(matrix2, matrix, matrixResult);

	printMatrix(matrixResult);

return 0;
}
