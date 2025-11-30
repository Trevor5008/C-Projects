/***************************************************************
Author    : Trevor Werner
Course    : COP 2270 Sec ANSI C Online
Professor : Michael Robinson
Program # : 4   
Purpose   : Description
            Create a binary output file named numbers.bin containing
            formatted lines with name, odd/even numbers forwards and backwards.
            Display each character to the screen as it is being written.
Due Date  : 11/29/2025

Certification:
I hereby certify that this work is my own and none of it is the work of any other person.

..........{ Trevor Werner }..........
*********************************************************************/
#include <stdio.h>

#define MIN 0
#define MAX 25
/* Write a sequence of integers to binary file and echo as readable text */
void writeSequence(FILE *fp, const char *label, int start, int end, int step)
{
    int i;
    fwrite("-", sizeof(char), 1, fp);
    printf("-");
    fwrite(" ", sizeof(char), 1, fp);
    printf(" ");

    // Write and print label
    for (i = 0; label[i] != '\0'; i++)
    {
        fwrite(&label[i], sizeof(char), 1, fp);
        printf("%c", label[i]);
    }
    // step indicates fwd/bkwd direction
    if (step > 0) {
        for (i = start; i <= end; i += step) {
            /* Write raw binary bytes of each int */
            fwrite(&i, sizeof(char), 1, fp);
            /* Echo readable integer to screen */
            printf("%d ", i);
        }
    } else {
        for (i = start; i >= end; i += step) {
            fwrite(&i, sizeof(int), 1, fp);
            printf("%d ", i);
        } 
    }
    fwrite("\n", sizeof(char), 1, fp);
    printf("\n");
}

int main(void)
{
    FILE *binaryp = fopen("numbers.bin", "wb");
    char name[] = "Trevor Werner";

    /* 1) Full name as ASCII text (just once, not binary) */
    int i;
    int len = sizeof(name);

    fwrite("-", sizeof(char), 1, binaryp);
    printf("-");
    fwrite(" ", sizeof(char), 1, binaryp);
    printf(" ");

    for (i = 0; name[i] != '\0'; i++)
    {
        fwrite(&name[i], sizeof(char), 1, binaryp);
        printf("%c", name[i]);
    }

    fwrite("\n", sizeof(char), 1, binaryp);
    printf("\n"); /* end w/ newline */
        
    /* 2–4) Forwards */
    writeSequence(binaryp, "odd numbers forwards: ", 1, 25, 2);
    writeSequence(binaryp, "even numbers forwards: ", 0, 24, 2);
    writeSequence(binaryp, "all numbers forwards: ", 0, 25, 1);

    /* 5) Blank line (text version only) */
    fwrite("\n", sizeof(char), 1, binaryp);
    printf("\n");

    /* 6–8) Backwards */
    writeSequence(binaryp, "odd numbers backwards: ", 25, 1, -2);
    writeSequence(binaryp, "even numbers backwards: ", 24, 0, -2);
    writeSequence(binaryp, "all numbers backwards: ", 25, 0, -1);

    fclose(binaryp);
    return 0;
}
