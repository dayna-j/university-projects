
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// macro definition allows MAX_ALLOWED_ARGS to be substituted for integer value 32.  Represents the maximum number of arguments that can be passed from command line.
#define MAX_ALLOWED_ARGS 32
// Function prototype for main.  2 formal parameters: integer-type argc and pointer-to-array-of-char type argv
int main(int argc, char *argv[]);
// sCompletionStatus is a pointer to char assigned to NULL.  
char *sCompletionStatus = NULL;
// Remember that a string in C is just an array of characters.  The sHeader pointer can be used just as the array variable would be.
char *sHeader = "CSC-250 Programming Assignment 3\n Due Date: 13 Feb 2017\n Dayna Blackwell";
// function definition for SwapPair: 3 formal parameters: 2 size_t type and array of integer type.  Function exchanges 2 array values.  *(data+nLeftItem)
void SwapPair(size_t nLeftItem, size_t nRightItem, int *data)
{
    int temp = *(data+nLeftItem);
    *(data+nLeftItem) = *(data+nRightItem);
    *(data+nRightItem) = temp;
}
// function definition for SortNumberSet.  Integer sorting algorithm.  2 formal parameters: size_t type nItems and array-of-integer type
void SortNumberSet(size_t nItems, int *values)
{
    for (size_t m = 0; m < nItems - 1; m++)
    {
        for (size_t n = m + 1; n < nItems; n++)
        {
            if (*(values+n) < *(values+m)) SwapPair(m, n, values);
        }
    }
}

// isSorted function prototype.  2 formal parameters: sizea-t type represents the total number of integers that were sorted.  values is the array of int to be sorted
// returns a Boolean true/false
_Bool IsSorted(size_t nItems, int *values)
{
// size_t type n is used for control condition.  So long as n is less than the total number of items in the integer array, continue iterating
    for (size_t n = 1; n < nItems; n++)
    {
// If the previous value is greater than the current, the list must not be sorted.  return false. *(values+(n-1)) , *(values+n)
        if (*(values+(n-1)) > *(values+n)) return false;
    }
// otherwise return true
    return true;
}
// PrintInputSet funct prints unsorted list of integers that were read in from the command-line.  returns nothing.  
// 3 formal parameters: pointer to a constant string, size_t type, array of integers
void PrintInputSet(const char *context, size_t nItems, int *values)
{
    printf(" input set(%s): ", context);
    for (size_t n = 0; n < nItems; n++)
    {
        printf("%s%d", n==0?"":", ", *(values+n));
    }
    printf("\n");
}
// main takes 2 arguments from the execution environment. argc: argument count and *argv[] argument vector: pointer to an array of char
int main(int argc, char *argv[])
{
    printf(" %s\n\n", sHeader);
// argc of less than 2 indicates no arguments were passed from command line.  1 is deducted from argc to compensate for the program name in the 0th index position of argv
    if ((argc < 2) || ((argc-1) > MAX_ALLOWED_ARGS))
    {
        printf("\n invalid argument count. found: %d, expected at least 1 and no more than: %d\n", argc-1, MAX_ALLOWED_ARGS);
        sCompletionStatus = "bad arguments";
    }
// else is entered when appropriate commandline argument condition is met
    else
    {
// nSortItemCount will be used as input to our sorting algorithm.  Contains an int representing the number of integer values to be sorted.  deduct 1 for program name.
        int nSortItemCount = argc - 1;
// Prints a message telling us how many integers will be sorted.
        printf(" processing %d items from the command line\n\n", nSortItemCount);
// declare an array of 32 integers
        int values[MAX_ALLOWED_ARGS];
// size_t type is used as control variable.  control condition: n must be less than the argument count from command-line.  increment n each pass.

// For loop converts string representation of integers-to-be-sorted into integer representations
        for (size_t n = 1; n < (size_t)argc; n++)
        {
// control variable initialized to 1.  values[n-1] accesses the 0th index position.  atoi converts the string interpretation of an integer into an int-type
// converts all strings in argv index position n>=1 to integer type and store in values int array.
            values[n - 1] = atoi(argv[n]);
        }

// Here, PrintInputSet funct prints the list of integers-to-be-sorted just as they were passed in from command-line.
// "before sort" is passed to satisfy the pointer-to-string type declared as "context" in funct prototype
// nSortItemCount represents the number of integers to be sorted.  Values is the array of up to 32 integers.
        PrintInputSet("before sort", nSortItemCount, values);
// bSorted is a _Bool type variable that holds the return value of the IsSorted function.  IsSorted returns true if sorted.  IsSorted returns false if not sorted.
        _Bool bSorted = IsSorted(nSortItemCount, values);
// (!bSorted) is checking to see if the input list is already sorted or not.  If it is NOT sorted, the body of the if-structure will be entered.
        if (!bSorted)
        {
// if not sorted, call sorting algorithm
            SortNumberSet(nSortItemCount, values);
            printf(" sort complete\n");
// Print sorted list
            PrintInputSet("after sort", nSortItemCount, values);
// if IsSorted returns true, update completion status to reflect success            
            if (IsSorted(nSortItemCount, values))
            {
                sCompletionStatus = "all good - data from command line successfully sorted";
            }
// if IsSorted returns false, update completion status to reflect failure
            else
            {
                sCompletionStatus = "sort failed on data from command line";
            }
        }
// else of outer decision-structure will be entered if the input list was already sorted when entered at the command-line.
        else
        {
            sCompletionStatus = "data from command line is sorted, nothing to do";
        }
    }

    printf("\n %s\n Completion Status: %s\n\n", sHeader, sCompletionStatus);
    return 0;
}
