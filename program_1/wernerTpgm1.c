/*************************************************
Author   : Trevor Werner
Course   : COP 2270-U01 (85009) Sec C Prog for Engineers MoWe 12:30 - 1:45
URL      : http://ocelot.aul.fiu.edu/~userName
Professor: Michael Robinson
Program  : Program Number, Purpose/Description
           A brief description of the program
Due Date : 10/04/2025

I certify that this work is my own alone.


    ..........{ Trevor Werner }..........
**************************************************/
#include <stdio.h>
#include <stdlib.h>

// Displays each result for operands 1-10
void numericalComputations() {
    int maximumNumber = 10;
    // Modulo
    printf("Modulo operations from 1-10 ------------\n");
    printf("10 %% 1 = %d\n", maximumNumber % 1);
    printf("10 %% 2 = %d\n", maximumNumber % 2);
    printf("10 %% 3 = %d\n", maximumNumber % 3);
    printf("10 %% 4 = %d\n", maximumNumber % 4);
    printf("10 %% 5 = %d\n", maximumNumber % 5);
    printf("10 %% 6 = %d\n", maximumNumber % 6);
    printf("10 %% 7 = %d\n", maximumNumber % 7);
    printf("10 %% 8 = %d\n", maximumNumber % 8);
    printf("10 %% 9 = %d\n", maximumNumber % 9);
    printf("10 %% 10 = %d\n", maximumNumber % 10);
    // Subtraction
    printf("Subtraction operations from 1-10 -----------\n");
    printf("10 - 1 = %d\t", maximumNumber - 1);
    printf("10 - 2 = %d\t", maximumNumber - 2);
    printf("10 - 3 = %d\t", maximumNumber - 3);
    printf("10 - 4 = %d\t", maximumNumber - 4);
    printf("10 - 5 = %d\t", maximumNumber - 5);
    printf("10 - 6 = %d\t", maximumNumber - 6);
    printf("10 - 7 = %d\t", maximumNumber - 7);
    printf("10 - 8 = %d\t", maximumNumber - 8);
    printf("10 - 9 = %d\t", maximumNumber - 9);
    printf("10 - 10 = %d\t\n", maximumNumber - 10);
    // Addition
    printf("Addition operations from 1-10 -----------\n");
    printf("10 + 1 = %d\n", maximumNumber + 1);
    printf("10 + 2 = %d\n", maximumNumber + 2);
    printf("10 + 3 = %d\n", maximumNumber + 3);
    printf("10 + 4 = %d\n", maximumNumber + 4);
    printf("10 + 5 = %d\n", maximumNumber + 5);
    printf("10 + 6 = %d\n", maximumNumber + 6);
    printf("10 + 7 = %d\n", maximumNumber + 7);
    printf("10 + 8 = %d\n", maximumNumber + 8);
    printf("10 + 9 = %d\n", maximumNumber + 9);
    printf("10 + 10 = %d\n", maximumNumber + 10);
    // Multiplication
    printf("Multiplication operations from 1-10 -----------\n");
    printf("10 * 1 = %d\t", maximumNumber * 1);
    printf("10 * 2 = %d\t", maximumNumber * 2);
    printf("10 * 3 = %d\t", maximumNumber * 3);
    printf("10 * 4 = %d\t", maximumNumber * 4);
    printf("10 * 5 = %d\t", maximumNumber * 5);
    printf("10 * 6 = %d\t", maximumNumber * 6);
    printf("10 * 7 = %d\t", maximumNumber * 7);
    printf("10 * 8 = %d\t", maximumNumber * 8);
    printf("10 * 9 = %d\t", maximumNumber * 9);
    printf("10 * 10 = %d\t\n", maximumNumber * 10);
    // Division
    printf("Division operations from 1-10 -----------\n");
    printf("10 / 1 = %d\n", maximumNumber / 1);
    printf("10 / 2 = %d\n", maximumNumber / 2);
    printf("10 / 3 = %d\n", maximumNumber / 3);
    printf("10 / 4 = %d\n", maximumNumber / 4);
    printf("10 / 5 = %d\n", maximumNumber / 5);
    printf("10 / 6 = %d\n", maximumNumber / 6);
    printf("10 / 7 = %d\n", maximumNumber / 7);
    printf("10 / 8 = %d\n", maximumNumber / 8);
    printf("10 / 9 = %d\n", maximumNumber / 9);
    printf("10 / 10 = %d\n", maximumNumber / 10);

    // For loop version
    printf("Arithmetic operations using for loop (values 1-10) -------\n");
    for (int i = 1; i <= maximumNumber; i++) {
        // Modulo
        printf("10 %% %i = %d\n", i, maximumNumber % i);
        // Subtraction
        printf("10 - %i = %d\t", i, maximumNumber - i);
        // Addition
        printf("10 + %i = %d\n", i, maximumNumber + i);
        // Multiplication
        printf("10 * %i = %d\t", i, maximumNumber * i);
        // Division
        printf("10 / %i = %d\n", i, maximumNumber / i);
    }
    // While loop version
    int i = 1;
    printf("Arithmetic operations using while loop (values 1-10) -------\n");
    while (i <= maximumNumber) {
        // Modulo
        printf("10 %% %i = %d\n", i, maximumNumber % i);
        // Subtraction
        printf("10 - %i = %d\n", i, maximumNumber - i);
        // Addition
        printf("10 + %i = %d\n", i, maximumNumber + i);
        // Multiplication
        printf("10 * %i = %d\n", i, maximumNumber * i);
        // Division
        printf("10 / %i = %d\n", i, maximumNumber / i);
        i++;
    }
}

// 3.) Determines the sum of values 1 to 100
void sumOfNumbers() {
    int N = 100;
    printf("The sum of values from 1 to 100 = %d\n", (1 + N) * (N / 2));
    // Loop version
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    printf("The sum of values from 1 to 100 using a loop: %d\n", sum);
}

// 4.) Print personal information
void myInfo(char name[], char major[], float credits_taken,
            float credits_current, char class_name[]) {
    printf("Hi my name is %s.\n", name);
    printf("My major is %s.\n", major);
    printf("I have completed %.2f credits.\n", credits_taken);
    printf("I am taking %.2f credits.\n", credits_current);
    printf("This class's name is %s.\n", class_name);
}

int main() {
    char name[] = "Trevor";
    char major[] = "Data Science";
    float credits_taken = 129.00;
    float credits_current = 10.00;
    char class_name[] = "Secure C";

    srand(RAND_MAX);
    float random = rand();
    printf("%.2f", random);
    // numericalComputations();
    // sumOfNumbers();
    // myInfo(name, major, credits_taken, credits_current, class_name);
    return 0;
}
