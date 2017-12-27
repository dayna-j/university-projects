#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>

#define  MAX_FILE_PATH_LENGTH  320

void PrintEntryBanner()
{
    printf("\n CSC-250 Spring 2017\n Dayna Blackwell\n CSC-250 File IO Assignment\n\n");
}

void PrintExitBanner()
{
    printf("\n\n All Done...\n CSC-250 Spring 2017\n Dayna Blackwell\n\n");
}

void PrintUsage()
{
    printf("  Program Name:\n"
        "    File IO Assignment\n"
        "  Description:\n"
        "    TODO - write descriptive message for whatever this program does,\n"
        "  Return:\n"
        "    zero (0) on success\n"
        "    non-zero (error code) on failure\n"
        "  Usage:\n"
        "    FILE_IO_Assignment   -input <full pathname>  -output <full pathname>\n\n");
}

size_t StringLength(const char *s)
{
    size_t nCount = 0;
//  while the current character in the string is not equal to the null terminator
    while (s[nCount] != '\0')
    {
//  increment nCount
        nCount++;
    }
//  nCount represents the length of the string, not including the null terminator.
    return nCount;
}

//  StringCopy prototype: size_t StringCopy(char *sDest, size_t nDest, const char *sSource)
//  sDest is a pointer to an array of char.  Acts as the destination buffer for the StringCopy function.
//  nDest represents the size of the nDest array
//  sSource is a pointer to an array of char.  This is the array where characters will be copied FROM.  size_t type is returned by function call.

size_t StringCopy(char *sDest, size_t nDest, const char *sSource)
{
//  abort if sSource points to NULL
    if (sSource == NULL)
        return 0;
//  abort if sDest points to NULL
    if (sDest == NULL)
        return 0;
//  abort if sSource and sDest are equivalent
    if (sSource == sDest)
        return 0;
//  nNeeded represents the number of characters that will fill the destination buffer.  1 is added to accomidate the null terminator.
    size_t nNeeded = 1 + StringLength(sSource);
//  Test for overlap.  abort if overlap exists between sDest and sSource
    if ((sSource >= sDest) && (sSource < (sDest + nDest)))
        return 0;
//  if nDest is too small to contain the source string, abort execution
    if (nDest < nNeeded)
        return 0;
//  copies contents of sSource to sDest	
    for (; (*sDest = *sSource); sDest++, sSource++);
//  adds null terminator to the end of sDest string	
    *sDest = '\0';
//  nNeeded represents the number of characters that will fill the destination buffer.    INCLUDES NULL TERMINATOR
    return nNeeded;
}
//  longest permissible line length
#define MAX_LINE_CHARACTER_COUNT 1280
//  shortest permissible line length
#define THRESHOLD_LINE_CHARACTER_COUNT 4

//  FINDS THE SHORTEST & LONGEST STRING IN READ_FILE
//  const char * sInput is a pointer to a constant string.  will contain input file name passed in from command line
//  const char * sOutput is a pointer to a constant string.  will contain the output file name passed in from command line
void FindLongestShortestStringInFile(const char *sInput, const char *sOutput)
{
//  declare pointer to file type.  
    FILE * pFileInput;
//  direct pointer-to-file to the input file on disk.
    pFileInput = fopen(sInput, "r");

    size_t nLineCount = 0;
    size_t nShortestLine = 9999999;
    size_t nLongestLine = 0;
//  MAX_LINE_CHARACTER_COUNT is defined to be 1280
//  sShortestLine is an array of 1280 char.  Initialized to the empty string.  This array will hold the Shortest Line
    char sShortestLine[MAX_LINE_CHARACTER_COUNT] = "";
//  sLongestLine is an array of 1280 char.  Initialized to the empty string.   This array will hold the Longest Line
    char sLongestLine[MAX_LINE_CHARACTER_COUNT] = "";

//  for ;; is always true.  loop will iterate until break statement is found.
    for (;;)
    {
//      MAX_LINE_CHARACTER_COUNT is defined to be 1280
//      sBuffer is an array of 1280 characters which will hold the data read from the FILE stream by fgets function
        char sBuffer[MAX_LINE_CHARACTER_COUNT] = "";

//      fgets prototype:    char *fgets(char *readTo, int n, FILE *streamReadFrom)
//      readTo is a pointer to an array of char where the data which is read will be stored.
//      n represents the maximum number of characters to be read
//      streamReadFrom is a pointer to a FILE type which identifies the STREAM where the data is read from

//      sBuffer will hold the data read by fgets.  MAX_LINE_CHARACTER_COUNT is defined to be 1280 and represents the size of sBuffer
//      pFileInput is the FILE stream where the data is READ FROM

//      NULL pointer is encountered when EOF is encountered.  Nothing more to read, so break
//      fgets will read an entire line on each call.  The maximum line length is defined as 1280 characters.
        if (NULL == fgets(sBuffer, MAX_LINE_CHARACTER_COUNT, pFileInput))
        {
            break;
        }
//      a line is read into sBuffer.  nLineCount is incremented by 1 for each line that has been read.
        nLineCount += 1;
//      StringLength returns the number of characters copied into sBuffer.  excludes null terminator.  
//      nCurrentCount represents the length of the string contained by sBuffer
//      at this point, sBuffer will be filled with the current line

        size_t nCurrentCount = StringLength(sBuffer);
//      The THRESHOLD_LINE_CHARACTER_COUNT is the smallest permissible line length: 4
        if (nCurrentCount < THRESHOLD_LINE_CHARACTER_COUNT)
//      If the length of the current line is less than the THRESHOLD_LINE_CHARACTER_COUNT, force next iteration of for loop with continue statement        
            continue;
//      nCurrentLine represents the length of the current string in sBuffer
        size_t nCurrentLine = StringLength(sBuffer);
//      NOTE: nShortestLine is initialized to ~10,000,000. The first value of nCurrentLine will ALWAYS be less than nShortestLine
        if (nCurrentLine < nShortestLine)
        {
//      if nCurrentLine is smaller than nShortestLine, nShortestLine is assigned value of nCurrentLine
            nShortestLine = nCurrentLine;
//      new shortest line is copied into sShortestLine buffer from sBuffer
            StringCopy(sShortestLine, MAX_LINE_CHARACTER_COUNT, sBuffer);
            // printf("\n***current shortest string: %s\n\n",sShortestLine);
            printf("found shortest line candidate - Length:%zu.  Contents: %s\n", nShortestLine, sShortestLine);
        }
        if (nCurrentLine > nLongestLine)
        {
            nLongestLine = nCurrentLine;
            StringCopy(sLongestLine, MAX_LINE_CHARACTER_COUNT, sBuffer);
            printf("\n***current longest string: %s\n\n",sLongestLine);
            printf("found longest line candidate - Length:%zu.  Contents: %s\n", nLongestLine, sLongestLine);
        }
    }
    
    printf("\n read %zu lines from input path\n\n", nLineCount);

    printf(" the shortest line is %zu characters: %s\n", nShortestLine, sShortestLine);
    printf(" the longest line is %zu characters: %s\n", nLongestLine, sLongestLine);

    // ---------------------------------------------------------------
    //    <<TODO - close the input file here >>
    fclose(pFileInput);
    // ---------------------------------------------------------------
    
    // ---------------------------------------------------------------
    //    <<TODO - Open the output file here >>
    FILE * pFileOutput;
    pFileOutput = fopen(sOutput, "w");
    // ---------------------------------------------------------------

    fprintf(pFileOutput, "CSC-250 Computer Science II\n");
    fprintf(pFileOutput, "Dayna Blackwell\n");
    fprintf(pFileOutput, "File IO Assignment - find longest and shortest line in input file\n");

    // ---------------------------------------------------------------
	//    <<TODO - write 2 lines of text to the output file here >>
    //    <<TODO - Line 1 shows:   "shortest line length: " and the count of bytes for the shortest line >>
    //    <<TODO - Line 2 shows:   "shortest line: and the text of the shortest line>>
    fprintf(pFileOutput, "\nshortest line length: %zu\n", nShortestLine);
    fprintf(pFileOutput, "shortest line: %s\n\n", sShortestLine);
    // ---------------------------------------------------------------

    // ---------------------------------------------------------------
    //    <<TODO - write 2 lines of text to the output file here >>
    //    <<TODO - Line 1 shows:   "longest line length: " and the count of bytes for the longest line >>
    //    <<TODO - Line 2 shows:   "longest line: and the text of the longest line>>
    fprintf(pFileOutput, "longest line length: %zu\n", nLongestLine);
    fprintf(pFileOutput, "longest line: %s\n", sLongestLine);
    // ---------------------------------------------------------------

    // ---------------------------------------------------------------
    //    <<TODO - close the output file here >>  DONE?
    fclose(pFileOutput);
    // ---------------------------------------------------------------
}

//  argCnt represents the number of arguments passed to main from command-line.  
//  argValues is a pointer to an array of strings.  Each value is a pointer to a string representation of the arguments passed from command-line. 
//  argValues[0] contains the file name of the source code
int main(int argCnt, char *argValues[])
{
    PrintEntryBanner();

//  if less than 5 arguments are passed from the command-line, call printUsage function and terminate.
    if (argCnt < 5)
    {
        printf("\n\n argument count wrong\n\n Showing usage\n ----------------------\n");
        PrintUsage();
        return 0;
    }
//  MAX_FILE_PATH_LENGTH defined to be 320.  represents the longest possible file name for the input data file
//  sInputPath is an array of 320 char.  initialized to the empty string
//  sInputPath holds the destination character array for the input string
    char sInputPath[MAX_FILE_PATH_LENGTH] = "";
//  sOutputPath is an array of 320 char. initialized to the empty string
    char sOutputPath[MAX_FILE_PATH_LENGTH] = "";

//  _stricmp returns 0 if "-input" is contained in the 1st index position of argValues string array
    if (0 == _stricmp("-input", argValues[1]))
    {
//  if 0 was returned, call StringCopy for the input/file-READ path name.  argValues[2] contains this value.  Copied to sInputPath array.
//      copy from argValues[2] to sInputPath.  sInputPath has a maximum allowable size of 320 char.
        StringCopy(sInputPath, MAX_FILE_PATH_LENGTH, argValues[2]);
    }
//  This case handles the possibility that input and output is swapped in the command-line arguments
    else if (0 == _stricmp("-input", argValues[3]))
    {
        StringCopy(sInputPath, MAX_FILE_PATH_LENGTH, argValues[4]);
    }

    if (0 == _stricmp("-output", argValues[1]))
    {
        StringCopy(sOutputPath, MAX_FILE_PATH_LENGTH, argValues[2]);
    }
    else if (0 == _stricmp("-output", argValues[3]))
    {
        StringCopy(sOutputPath, MAX_FILE_PATH_LENGTH, argValues[4]);
    }

//  At this point, input and output file names have been copied into their respective arrays
//  if StringLength(sInputPath) returns 0, then no input path was specified in the command-line
    if (0 == StringLength(sInputPath))
    {
        printf("\n\n input path not specified\n\n Showing usage\n ----------------------\n");
//      make call to PrintUsage to show correct usage for command line-arguments
        PrintUsage();
//      ABORT PROGRAM
        return 0;
    }
//  if StringLength(sOutputPath) returns 0, then no output path was specified in the command-line
    if (0 == StringLength(sOutputPath))
    {
        printf("\n\n output path not specified\n\n Showing usage\n ----------------------\n");
//      make call to PrintUsage to show correct usage for command line-arguments
        PrintUsage();
//      ABORT PROGRAM
        return 0;
    }

//  sInputPath contains the file name that data will be READ FROM.  sOutputPath contains the file name where data will be WRITTEN TO.
    FindLongestShortestStringInFile(sInputPath, sOutputPath);

    PrintExitBanner();

    return 0;
}
