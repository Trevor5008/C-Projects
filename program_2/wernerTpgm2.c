/*************************************************
Author   : Trevor Werner
Course   : COP 2270-U01 (85009) Sec C Prog for Engineers MoWe 12:30 - 1:45
URL      : http://ocelot.aul.fiu.edu/~userName
Professor: Michael Robinson
Program  : 2
    Purpose of this program is to practice the following concepts:
    * functions
    * if, else if, else conditionals
    * for loops
    * printf statements
    * primitive types
    * single dimension arrays
    * String class, char x[], with functions
    * ASCII values

Due Date : 10/14/2025

I certify that this work is my own alone.

    ..........{ Trevor Werner }..........
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h> // used for seeding srand

// 2c.) Create a single dimensional array containing ONE index,
//  which will have ONE string w/ your full name as follows:
//      "first name $ middle name % last name and One space"
//

double processAbsoluteValues(double val) { return fabs(val); }

double processRoundValues(double val) { return round(val); }

double processCeilingValues(double val) { return ceil(val); }

double processFlooringValues(double val) { return floor(val); }

double processMinimumValues(double val1, double val2) {
    return fmin(val1, val2);
}

double processMaximumValues(double val1, double val2) {
    return fmax(val1, val2);
}

// Helper functions for trig operations
// Cosine
double processCosineValue(double x) {
    return cos(x);
}

// Sine
double processSineValue(double x) {
    return sin(x);
}

// Tangent
double processTangentValue(double x) {
    return tan(x);
}

// Main trig function invocation function
void processTrigFunctionValues(double x) { 
    // Output each trig value (cosine, sine, tangent)
    printf("The cosine of %.2f is %.2f\n", x, processCosineValue(x));
    printf("The sin of %.2f is %.2f\n", x, processSineValue(x));
    printf("The tangent of %.2f is %.2f\n", x, processTangentValue(x));
}

// Input exponent value (double) and returns Euler's constant raised to the
// provided value (Ex. e^2.0 s/equal 7.389056099) 
double processExponentialValues(double power) { return exp(power); }

// Input value, returns log of value base e
double processLogValues(double x) { return log(x); }

// Input base value and exponent, returns the product
double processPowerValues(double base, double exp) { return pow(base, exp); }

// Input value, returns square root
double processSquareRootValues(double x) { return sqrt(x); }

// Input min and max integer values, returns random value inclusive of range
int processRandomValues(int min, int max) { 
    return rand() % (max - min + 1) + min; 
}

// Helper functions for string parsing
int processIsVowel(char c) {
    int lowercase_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    int uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    return lowercase_vowel || uppercase_vowel;
}

int processIsSymbol(char c) {
    return (c == '%' || c == '$');;
}

int processIsSpace(char c) {
    return c == ' ';
}

// Invokes processIsVowel, processIsSpace and processIsSymbol
int processIsConsonant(char c) {
    return (!processIsVowel(c) && !processIsSymbol(c) && !processIsSpace(c));
}

// Iterates over name input value, conditionally prints character category 
void myName(char name[]) {
    size_t length = strlen(name); 
    int lowercase_vowel, uppercase_vowel, symbol, space;
    char c;
    for (int i = 0; i < length; i++) {
        c = name[i];
        if (processIsVowel(c)) {
            printf("character [%c] located at position %i is a vowel\n", c, i);
        } else if (processIsSymbol(c)) {
            printf("character [%c] located at position %i is a symbol\n", c, i);
        } else if (processIsSpace(c)) {
            printf("character [%c] located at position %i is a space\n", c, i);
        } else {
            printf("character [%c] located at position %i is a consonant\n", c, i);
        } 
    }
}

void pyramid(char fullName[]) {
    // Casting string length to an integer 
    int length = (int)strlen(fullName);
    int left = 0;
    int right = length - 1;
    int s;
    // Trim left and right chars on each iteration
    while (right >= left) {
        for (s = 0; s < left; s++) {
            printf(" ");
        }
        
        // Surround each line w/ opening and closing brackets
        printf("%d [", length);
        for (int i = left; i <= right; i++) {
            printf("%c", fullName[i]);
        }
        printf("%c\n", ']');
        // trim left and right chars after each iteration
        left++;
        right--;
        length-=2;
    }
    // Final line needs leading spaces
    for (s = 0; s < left; s++) {
        printf(" ");
    }
    // Final empty brackets line
    printf("0 []\n");
}

// Prints my name in a variety of cases
void parsing(char fullName[]) {
    size_t length = strlen(fullName);
    // Print name in uppercase
    printf("My name in all uppercase: ");
    for (int i = 0; i < length; i++) {
        printf("%c", toupper(fullName[i]));
    }
    printf("\n");
    // Print name in lowercase
    printf("My name in all lowercase: ");
    for (int i = 0; i < length; i++) {
        printf("%c", tolower(fullName[i]));
    }
    printf("\n");
    // Print name w/out spaces
    printf("My name w/out spaces: ");
    for (int i = 0; i < length; i++) {
        if (fullName[i] != ' ') {
            printf("%c", fullName[i]);
        }
    }
    printf("\n");
    // Print name w/ all vowels in uppercase, and consonants in lower
    printf("My name in alternating case: ");
    int isVowel, isConsonant;
    char c;
    for (int i = 0; i < length; i++) {
        c = fullName[i];
        isVowel = processIsVowel(c);
        isConsonant = processIsConsonant(c);
        if (isVowel) {
            printf("%c", toupper(c));
        } else if (isConsonant) {
            printf("%c", tolower(c));
        } else {
            printf("%c", c);
        }
    }
    printf("\n");
    // Print name backwards
    printf("My name backwards: ");
    for (int i = length -1; i >= 0; i--) {
        printf("%c", fullName[i]);
    }
    printf("\n");
    // Print name in ascii values;
    printf("My name in ASCII: ");
    for (int i = 0; i < length; i++) {
        c = fullName[i];
        printf("%d", c);
    }
    printf("\n");
}

int main() {
    int i = 7;
    int j = 9;
    double x = 72.5;
    double y = -0.34;

    // Seeds rand() w/ current time
    srand(time(NULL));

    char fullName[] = "Trevor $ Carlton % Werner ";

    printf("My name is %s\n", fullName);

    printf("-------- Part 2 ----\n");
    printf("The absolute value of %.2f: %.2f\n", y, processAbsoluteValues(y));
    printf("The rounded value of %.2f: %.2f\n", x, processRoundValues(x));
    printf("The ceiling of value of %.2f: %.2f\n", x, processCeilingValues(x));
    printf("The floor of value of %.2f: %.2f\n", x, processFlooringValues(x));
    printf("The minimum value between %.2f and %.2f: %.2f\n", x, y,
           processMinimumValues(x, y));
    printf("The maximum value between %.2f and %.2f: %.2f\n", x, y,
           processMaximumValues(x, y));
    printf("-------- Part 3 ----\n");
    printf("The trig values for %.2f\n", x);
    processTrigFunctionValues(x);
    printf("e raised to the %dth power is: %.2f\n", i, processExponentialValues(i));
    printf("The natural log of %d is: %.2f\n", j, processLogValues(j));
    printf("%d raised to the %dth power is: %.2f\n", i, j, processPowerValues(i, j));
    printf("The square root of %d is: %.2f\n", i, processSquareRootValues(i));
    printf("A random value between %i and %i is: %i\n", 1, 10, processRandomValues(1, 10));

    printf("-------- Part 4 ----\n");
    myName(fullName);

    printf("-------- Part 5 ----\n");
    pyramid(fullName);
    printf("-------- Part 6 ----\n");
    parsing(fullName);
    return 0;
}
