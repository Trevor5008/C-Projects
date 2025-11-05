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
#include <stdlib.h>

/**
* 2b) Load each index w/ the multiplication of its x, y
*/

void populateArray(int arr[10][10]) 
{
    int x;
    for (x = 0; x < 10; x++) {
        int y;
        for (y = 0; y < 10; y++) {
            arr[x][y] = x * y;
        }
    }
}

// 2c) Print the total of columns 3, 5 and 7
// 2d) Print the total of columns 2, 4 and 6
void printColumnTotals(int arr[][10]) 
{
    int row2 = 0, col3 = 0, row4 = 0, col5 = 0, row6 = 0, col7 = 0;

    int idx;
    // Iterates and alternates rows and columns
    for (idx = 0; idx < 10; idx++) {
        row2 += arr[1][idx];
        col3 += arr[idx][2];
        row4 += arr[3][idx];
        col5 += arr[idx][4];
        row6 += arr[5][idx];
        col7 += arr[idx][6];
    }

    printf("Columns 3, 5, 7 totals ------\n");
    printf("Column 3 Total: %d\n", col3);
    printf("Column 5 Total: %d\n", col5);
    printf("Column 7 Total: %d\n", col7);

    printf("Rows 2, 4, 6 totals ------\n");
    printf("Row 2 Total: %d\n", row2);
    printf("Row 4 Total: %d\n", row4);
    printf("Row 6 Total: %d\n", row6);
    printf("----------------------------\n");
}

// Prints Rows 2,4,6 total - Columns 3, 5, 7 total
void printSpecificDifferences(int arr[][10])
{
    int rowTotals = 0, colTotals = 0;

    int row;
    // Tally rows 2, 4, 6
    for (row = 2; row < 7; row += 2) {
        int col;
        for (col = 0; col < 10; col++) {
            rowTotals += arr[row][col];
        }
    }
  
    // Tally cols 3, 5, 7
    for (row = 0; row < 10; row++) {
        int col;
        for (col = 3; col < 8; col += 2) {
            colTotals += arr[row][col];
        }
    }

    printf("Rows 2,4,6 - Columns 3,5,7 totals = %d\n", rowTotals - colTotals);
}

// 2e) Print the difference of the total values (rows - columns)
void printTotalDifferences(int arr[][10]) 
{
    int rowTotals = 0, colTotals = 0;

    // Tally each row  
    int x, rowTotal;
    for (x = 0; x < 10; x++) {
        rowTotal = 0;
        int y;
        for (y = 0; y < 10; y++) {
            rowTotal += arr[x][y];
        }
        rowTotals += rowTotal;
        printf("Row %d total: %d\n", x, rowTotal);
    }
    printf("---------------------------\n");

    // Tally each column
    int y;
    for (y = 0; y < 10; y++) {
        int colTotal = 0;
        int x;
        for (x = 0; x < 10; x++) {
            colTotal += arr[x][y];
        }
        colTotals += colTotal;
        printf("Column %d total: %d\n", y, colTotal);
    }
    printf("-------------------------\n");

    printf("Row totals: %d\n", rowTotals);
    printf("Column totals: %d\n", colTotals);
    // Print Rows 2,4,6 totals - columns 3,5,7 differences
    printSpecificDifferences(arr);
    // Print total difference b/n all rows and all columns
    printf("Rows - Columns = %d\n", rowTotals - colTotals);
    printf("-------------------------\n");
}

// Random number generation between MIN and MAX
int generateRandomNumber() 
{
    int MIN = 1, MAX = 1000; 
    return rand() % (MAX - MIN + 1) + MIN;
}

// Use swaps to sort three numbers into ascending order
void ascending(int num1, int num2, int num3) 
{
    printf("Swapping three values into sorted position...\n");
    printf("Data Received: %5d %5d %5d\n", num1, num2, num3);
    int temp;

    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    if (num2 > num3) {
        temp = num2;
        num2 = num3;
        num3 = temp;
    } 

    if (num1 > num3) {
        temp = num1;
        num1 = num3;
        num3 = temp;
    }

    printf("Processed Data: %5d %5d %5d\n", num1, num2, num3);
    printf("--------------------------\n");
}

// 4.) Print uppercase alphabet from Z to A using ASCII values
void printAlphabetReverse() 
{
    int upperCaseZCode = 'Z', upperCaseACode = 'A';

    while(1) {
        printf("%c > ASCII value = %d\n", upperCaseZCode, upperCaseZCode);
        upperCaseZCode--;
        if (upperCaseZCode < upperCaseACode) {
            break;
        }
    }
}

// 5.) Implement division by 0, w/ error trapping using if and while()
// // make sure to use casting -> (float)int/int
void printDivisionByZero() 
{
    const int exitCode = 999;
    int firstNumber, secondNumber;

    printf("\n##### Divider Program #######\n");
    printf("Enter '999' to quit at any time\n");

    while (1) {
        // Ask for user input of 1st and 2nd number
        printf("Enter the first number: ");
        scanf("%d", &firstNumber);
        // Check for exit code
        if (firstNumber == exitCode) {
            return;
        }

        printf("Enter a second number: ");
        scanf("%d", &secondNumber);

        // Check for exit code
        if (secondNumber == exitCode) {
            return;
        }

        // Loop until user enters non-zero value
        while (secondNumber == 0) {
            // Prompt for re-entry of second number
            printf("Please re-enter the second number (cannot be zero): ");
            scanf("%d", &secondNumber);

            if (secondNumber == exitCode) {
                return;
            }
        }
        // Divide both numbers along with the division result
        float divisionResult = (float) firstNumber / secondNumber;

        printf("%d divided by %d = %.2f\n", firstNumber, secondNumber, divisionResult);
        printf("-----------------------\n");
    }
}

// 6.) Uses a while loop to display numbers from 0 to 100
// .. where "x mod 5 = 3"
void printMod5Equal3() 
{
    int start = 0, modulo = 5, res = 0;
    printf("---- n mod 5 operations -------\n");
    while (start <= 100) {
        res = start % modulo;
        if (res == 3) {
            printf("%d mod %d = %d\n", start, modulo, res);
        }
        start++;
    }
    printf("-----------------\n");
}

// 7.) Print results of two single-dimensional arrays
void printTwo1DArrays() 
{
    char *one[] = {"This ANSI C ", "at ", "is "};
    char *two[] = {"class", "FIU", "challenging && enjoyable"};

    int i;
    for (i = 0; i < 3; ++i) {
        printf("%s%s ", one[i], two[i]);
    }
    printf("\n");
}

int main() 
{
    int wernerT2DimArray[10][10];

    int num1 = generateRandomNumber();
    int num2 = generateRandomNumber();
    int num3 = generateRandomNumber();

    // Part 2 / 2D Array operations
    populateArray(wernerT2DimArray);
    printf("Results of poplating 2D array...\n");
    int x;
    for (x = 0; x < 10; x++) {
        // TESTING: printf("Row: %d ------\n", x);
        int y;
        for (y = 0; y < 10; y++) {
            printf("%3d ", wernerT2DimArray[x][y]);
        }
        printf("\n");
    }
    // Printing divider separating 2D array results
    int z; 
    for (z = 0; z < 40; ++z) {
        printf("-");
    }
    printf("\n");

    printColumnTotals(wernerT2DimArray);
    // Instructions were ambiguous, printing both specific rows - cols
    // as well as total rows - total columns
    printTotalDifferences(wernerT2DimArray);
    // Part 3 / sort 3 values
    ascending(num1, num2, num3);
    // Part 4 / print upper case alphabet in reverse
    printAlphabetReverse();
    // Part 5 / divide by zero error handling
    printDivisionByZero();
    // Part 6 / looping mod 5 = 3
    printMod5Equal3();
    // Part 7 / print parallel array contents
    printTwo1DArrays();
    return 0;
}
