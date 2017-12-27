#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
Implement the logic for a currency dispensing station for a hypothetical companies pay station, 
where the teller accepts as input a worker’s pay request on payday for an amount due, expressed
in whole penny amounts, and prints a tally note to the bank teller, with the amounts of each
currency item, such that the total amount requested can be tendered in the fewest number of currency units.
*/

// global variable definitions for entry&exit banners
const char *assignmentID = "#4: TallyNoteCalculator";                           // pointer to a constant string.
const char *classId = "CSC-250 Computer Science II Spring 2017";                // pointer to a constant string.
const char *programmerName = "Dayna J. Blackwell";                              // pointer to a constant string.
const char *dueDate = "Monday, February 27, 2017";                              // pointer to a constant string.
const char *sCompletionStatus = NULL;

// function prototypes
void printEntryBanner(const char *sAssignID, const char *sClassID, const char *sDate, const char *sDeveloper);
void printExitBanner(const char *sAssignID, const char *sComplete);
void printUsage(int argCount);
_Bool validateAmountDue(char* sCurrentAmount);
char* computeTallyNote(char *, size_t, size_t);
int main(int argc, char *argv[]);

// function definitions
void printEntryBanner(const char *sAssignID, const char *sClassID, const char *sDate, const char *sDeveloper)
{
    printf("\n--------------------------------------------------------------------------\n"
    "Project: %s\n"
    "Class: %s\n"
    "Due Date: %s\n"
    "Student: %s"
    "\n--------------------------------------------------------------------------\n"
    ,assignmentID, classId, dueDate, programmerName);
}

void printExitBanner(const char * sAssignID, const char * sComplete)
{
    printf(
    "\n--------------------------------------------------------------------------\n"
    "Project: %s\n"
    "Completion Status: %s"
    "\n--------------------------------------------------------------------------"
     ,assignmentID, sCompletionStatus);
}

void printUsage(int argCount)
{
// argCount-1 is used because the program is stored in the 0th index position.  1 must be deducted to compensate for that entry.
    printf("\nInvalid argument count: found: %d. Expected at least 1.\n"
    "\nProgram will terminate.\n", (argCount-1));

    sCompletionStatus = "Failed. Bad arguments!";
    printf("\nCompletion status: %s", sCompletionStatus);
}

_Bool validateAmountDue(char* sCurrentAmount)
{
    int CurrentLen = strlen(sCurrentAmount);
    for(int n=0; n<CurrentLen; n++)
    {
        if(!isdigit(sCurrentAmount[n]))
            return false;
    }
    return true;
}

char* computeTallyNote(char* charBuffer, size_t bufSize, size_t validInput)
{
    int adjuster = 0;
    int addBuffer = 0;
    addBuffer += snprintf(charBuffer+addBuffer, bufSize, "\n*************************************\n");
    addBuffer += snprintf((charBuffer+addBuffer), bufSize, "Tally complete:\n");
    addBuffer += snprintf((charBuffer+addBuffer), bufSize, "\nAmount Due: %zd pennies, tendered as:\n\n",validInput);
    
   if(validInput>= 1200)
    {
        adjuster = validInput/1200;
        validInput = validInput-(adjuster*1200);
        addBuffer += snprintf((charBuffer+addBuffer), bufSize, "  %d 5 Pound Notes\n",adjuster);
        adjuster = 0;
    }
   else addBuffer += snprintf((charBuffer+addBuffer), bufSize, "  0 5 Pound Notes\n");
   if(validInput>=240)
   {
        adjuster = validInput/240;
        validInput = validInput-(adjuster*240);
        addBuffer += snprintf((charBuffer+addBuffer), bufSize, "  %d 1 Pound Notes\n",adjuster);
        adjuster = 0;
   }
   else addBuffer += snprintf((charBuffer+addBuffer), bufSize, "  0 1 Pound Notes\n");
   if(validInput>=60)
   {
        adjuster = validInput/60;
        validInput = validInput-(adjuster*60);
        addBuffer+= snprintf((charBuffer+addBuffer), bufSize, "  %d Crown Coins\n",adjuster);
        adjuster = 0;
   }
   else addBuffer += snprintf((charBuffer+addBuffer), bufSize, "  0 Crown Coins\n");
   if(validInput>=30)
   {
        adjuster = validInput/30;
        validInput = validInput-(adjuster*30);
        addBuffer += snprintf((charBuffer+addBuffer), bufSize, "  %d Half Crown Coins\n",adjuster);
        adjuster = 0;
   }
   else addBuffer += snprintf((charBuffer+addBuffer), bufSize, "  0 Half Crown Coins\n");
   if(validInput>=12)
   {
        adjuster = validInput/12;
        validInput = validInput-(adjuster*12);
        addBuffer += snprintf((charBuffer+addBuffer), bufSize, "  %d Shilling Coins\n",adjuster);
        adjuster = 0;
   }
   else addBuffer += snprintf((charBuffer+addBuffer), bufSize, "  0 Shilling Coins\n");
   if(validInput>=6)
   {
        adjuster = validInput/6;
        validInput = validInput-(adjuster*6);
        addBuffer += snprintf((charBuffer+addBuffer), bufSize, "  %d SixPence Coin\n",adjuster);
        adjuster = 0;
   } 
   else addBuffer += snprintf((charBuffer+addBuffer), bufSize, "  0 SixPence Coins\n");
   if(validInput>=1)
   {
        adjuster = validInput/1;
        validInput = validInput-(adjuster*1);
        addBuffer += snprintf((charBuffer+addBuffer), bufSize, "  %d Penny Coins\n",adjuster);
        adjuster = 0;
   }
   else addBuffer += snprintf((charBuffer+addBuffer), bufSize, "  0 Penny Coins\n");

   addBuffer += snprintf((charBuffer+addBuffer) , bufSize, "*************************************");
   sCompletionStatus = "Execution complete.  Conversion Successful.";
   return charBuffer;    
}

int main(int argc, char *argv[])
{
    #define MESSAGE_SIZE 350
    char charBuffer[MESSAGE_SIZE];
    printEntryBanner(assignmentID, classId, dueDate, programmerName);
// If command-line argument count is less than 1, printUsage is called and program terminates.  Invalid input.
    if(argc<=1)
    {
// argument count from command-line is passed to printUsage function.
        printUsage(argc);
        return 0;
    }
// while n is smaller than the number of arguments passed from command-line, attempt to validate the input.
    for(size_t n = 1; n<(size_t)argc; n++)
    {
// Remember that argv is an array of strings.
// sAmount due is a pointer to a string.  It is passed into the ValidateAmountDue function.  
        char* sAmountDue = argv[n];
        if(!validateAmountDue(sAmountDue))
        {
            printf("\nInput could not be validated!\n"
                    "Pass integer values only\n");
            
            sCompletionStatus = "Failed. Bad arguments!";
//            printf("\nCompletion status: %s\n", sCompletionStatus);
        }
        else
        {
// If command-line input CAN be validated (is integer valued), then the validated value of ascii-to-int function is assigned to validatedAmount size_t variable.
// validatedAmount contains the integer representation held at the current argv index position
            size_t validatedAmount = atoi(sAmountDue);
            puts(computeTallyNote(charBuffer, MESSAGE_SIZE, validatedAmount));
        }
    }
    printExitBanner(assignmentID, sCompletionStatus);
    return 0;
}