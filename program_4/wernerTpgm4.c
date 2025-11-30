/***************************************************************
Author    : Trevor Werner
Course    : COP 2270 Sec ANSI C Online
Professor : Michael Robinson
Program # : 4   
Purpose   : Description
            Read an input text file, copying character by character.
            Write each character into a new text file.
            Display each character to the screen, as it is being processed.
Due Date  : 11/29/2025

Certification:
I hereby certify that this work is my own and none of it is the work of any other person.

..........{ Trevor Werner }..........
*********************************************************************/
#include <stdio.h>

int main(void) 
{
    char in_name[] = "wernerTTextFileInput.txt", 
        out_name[] = "wernerTTextFileOutput.txt";
    FILE *inpFile, *outFile;
    char ch;
    int status;

    // Input file read
    inpFile = fopen(in_name, "r");
    // Output file written to
    outFile = fopen(out_name, "w");

    // fscanf for accessing file
    for (status = fscanf(inpFile, "%c", &ch); 
         status != EOF; status = fscanf(inpFile, "%c", &ch)) 
    {
        // print to screen char by char
        printf("%c", ch);
        // write to file char by char
        fprintf(outFile, "%c", ch); 
    }

    // Close input and output files
    fclose(inpFile);
    fclose(outFile);

    // Status completion notification
    printf("Copied %s to %s.\n", in_name, out_name); 
    return 0;
}
