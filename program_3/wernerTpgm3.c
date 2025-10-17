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
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h> // used for seeding srand

// 2.) 
//  a) Create a two dimensional array of 10 rows by 10 columns, using x for rows and y for columns
//    under the name: your lastName First letters of your firstName and 2DimArray 
//    example: robinsonM2DimArray
//  b) Load each index with the multiplication of its x and y location
//  c) Add all the values in columns 3, 5, and 7, and print the total
//  d) Add all the values in rows 2, 4, and 6, and print the total
//  e) Subtract the total values (rows-columns), and print the difference.

// 3) Worth 1.25 points
//      From the main function pass 3 numbers of your choice, to a function 
// 	 named ascending that will print these numbers in ascending order.
//
//      Example if you pass (98, 234, 6)
//                      print 6 98 234
//
//      Do NOT use any built-in sort ANSI C funtion.
//
//      You must do the swaping steps as recorderd in video 20
//
// 4) Worth 1.50 points
//      Using a while(1) loop, print the upper case alphabeth and its corresponding ascii values,
//      from Z to A
//      Note: You must terminate/stop/break this loop once you process the last letter (A)
//
//
//   5) Worth 2.00 points
//      Implement division by 0, with error trapping, using if and while() commands,
//      make sure to use "casting" e.i. float result = (float)int/int;
//
//      How:
//      Create two new variables, and int name firstNumber and an int named secondNumber. 
//      Using a while loop, read 2 numbers from the user.
//      Using the if statement, test that the second number in not zero, if it is inform
//      the user of the error, and ask for a correct second number.
//      if the second number is NOT a zero, do the division, display all numbers and the
//      computation using labels, the result MUST have 2 decimal places,
//
//      example: "The first number 10 divided by the second number 5 is 2.00"
//
//      To exit this while loop the user MUST enter the value 999 for the first 
// 	 or the second number ***ONLY***
//
//
//   6) Worth 1.00 point
//      Using a loop of your choice, display all numbers from 0 to 100 where "x mod 5 = 3".  
//
//      Loop x is the loop number, that when doing x mod 5, the answer is 3
//
//
//      Remember x starts as 0, and in the last loop, x MUST the 100. 
//
//
//   7) Worth 2.00 points
//      Having the following TWO, ONE dimensions arrays:
//
//      one[0] = "This ANSI C ";   two[0] = "class";
//      one[1] = "at ";            two[1] = "FIU";
//      one[2] = "is ";            two[2] = "challenging && enjoyable";
//
// 	    print the results using a parallel array, made with these two one dim arrays
#include <stdbool.h>

bool isLeapYear(int year) {
    int divisibleBy4 = year % 4 == 0;
    int divisibleBy100 = year % 100 == 0;
    int divisibleBy400 = year % 400 == 0;

    if (divisibleBy4 && divisibleBy100 && divisibleBy400) {
        return true;
    } else if (divisibleBy4 && divisibleBy100) {
        return false;
    } else if (divisibleBy4) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int isSpace, isVowel;
    for (int i = 1900; i <= 2050; i++) {
        bool is_leap_year = isLeapYear(i);
        printf("%i is%s a leap year\n", i, is_leap_year ? "" : " not");
    }
}
