/*************************************************
Author   : Trevor Werner
Course   : COP 2270-U01 (85009) Sec C Prog for Engineers MoWe 12:30 - 1:45
URL      : http://ocelot.aul.fiu.edu/~userName
Professor: Michael Robinson
Program  : 3
    Purpose of this program is to practice the following concepts:
    * Multidimensional Arrays
    * Swapping/Sorting 
    * ASCII Codes
    * Endless while loop
    * Modules
    * Parallel Arrays

Due Date : 10/14/2025

I certify that this work is my own alone.

    ..........{ Trevor Werner }..........
**************************************************/
#include <stdio.h>
#include <time.h>  // seed for rand generation
#include <stdlib.h>


// Constants
#define MIN 1
#define MAX 1000

/**
* 2b) Load each index w/ the multiplication of its x, y
*/

void populateArray(int arr[10][10]) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            arr[x][y] = x * y;
        }
    }
}

// 2c) Print the total of columns 3, 5 and 7
// 2d) Print the total of columns 2, 4 and 6
void printColumnTotals(int arr[][10]) {
    int col2 = 0, col3 = 0, col4 = 0, col5 = 0, col6 = 0, col7 = 0;

    for (int row = 0; row < 10; row++) {
        col2 += arr[row][1];
        col3 += arr[row][2];
        col4 += arr[row][3];
        col5 += arr[row][4];
        col6 += arr[row][5];
        col7 += arr[row][6];
    }

    printf("Columns 3, 5, 7 totals ------\n");
    printf("Column 3 Total: %d\n", col3);
    printf("Column 5 Total: %d\n", col5);
    printf("Column 7 Total: %d\n", col7);

    printf("Columns 2, 4, 6 totals ------\n");
    printf("Column 2 Total: %d\n", col2);
    printf("Column 4 Total: %d\n", col4);
    printf("Column 6 Total: %d\n", col6);
}

// 2e) Print the difference of the total values (rows - columns)
void printDifferences(int arr[][10]) {
    int rowTotals = 0, colTotals = 0;

    // Tally each row  
    for (int x = 0; x < 10; x++) {
        int rowTotal = 0;
        for (int y = 0; y < 10; y++) {
            rowTotal += arr[x][y];
        }
        rowTotals += rowTotal;
        printf("Row %d total: %d\n", x, rowTotal);
    }

    // Tally each column
    for (int y = 0; y < 10; y++) {
        int colTotal = 0;
        for (int x = 0; x < 10; x++) {
            colTotal += arr[x][y];
        }
        colTotals += colTotal;
        printf("Column %d total: %d\n", y, colTotal);
    }

    printf("Row totals: %d\n", rowTotals);
    printf("Column totals: %d\n", colTotals);
    // Print total difference b/n all rows and all columns
    printf("Rows - Columns = %d\n", rowTotals - colTotals);
}

// Random number generation between MIN and MAX
int generateRandomNumber() {
    return rand() % (MAX - MIN + 1) + MIN;
}

// Use swaps to sort three numbers into ascending order
void ascending(int num1, int num2, int num3) {
    printf("Data Received: %5d %5d %5d\n", num1, num2, num3);
    int temp;

    while (1) {
        if (num1 > num2) {
            temp = num1;
            num1 = num2;
            num2 = temp;
        }
        if (num2 > num3) {
            temp = num2;
            num2 = num3;
            num3 = temp;
        } else {
            break;
        }
    }

    printf("Processed Data: %5d %5d %5d\n", num1, num2, num3);
}

// 4.) Print uppercase alphabet from Z to A using ASCII values
void printAlphabetReverse() {
    int upperCaseZCode = 'Z';
    int upperCaseACode = 'A';
    while(1) {
        printf("%c\n", upperCaseZCode);
        upperCaseZCode--;
        if (upperCaseZCode < upperCaseACode) {
            break;
        }
    }
}

int main() {
    int wernerT2DimArray[10][10];
    int el;

    // Seed random number
    srand(time(NULL));

    int num1 = generateRandomNumber();
    int num2 = generateRandomNumber();
    int num3 = generateRandomNumber();

    populateArray(wernerT2DimArray);
    for (int x = 0; x < 10; x++) {
        printf("Row: %i ------\n", x);
        for (int y = 0; y < 10; y++) {
            printf("%i ", wernerT2DimArray[x][y]);
        }
        printf("\n");
    }
    printColumnTotals(wernerT2DimArray);
    printDifferences(wernerT2DimArray);
    ascending(num1, num2, num3);
    printAlphabetReverse();
    return 0;
}
