/*************************************************
Author   : Trevor Werner
Course   : COP 2270-U01 (85009) Sec C Prog for Engineers MoWe 12:30 - 1:45
Professor: Michael Robinson
Program  : 4
Purpose:  Purpose of this program is to practice the following concepts:
    - Read an input text file, copying character by character
    - Write each character into a new text file
    - Display each character to the screen, as it is being processed

Due Date : ????

I certify that this work is my own alone.

    ..........{ Trevor Werner }..........
**************************************************/
#include <stdio.h>

int main(void) 
{
    char in_name[] = "wernerTTextFileInput.txt", 
        out_name[] = "wernerTTextFileOutput.txt";
    FILE *inpFile, *outFile;
    char ch;
    int status;

    inpFile = fopen(in_name, "r");
    outFile = fopen(out_name, "w");

    for (status = fscanf(inpFile, "%c", &ch); 
         status != EOF; status = fscanf(inpFile, "%c", &ch)) {
        printf("%c", ch);
        fprintf(outFile, "%c", ch); 
    }

    fclose(inpFile);
    fclose(outFile);

    printf("Copied %s to %s.\n", in_name, out_name); 
    return 0;
}
