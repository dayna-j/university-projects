#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// returns size_t object.  accepts pointer to a constant character as parameter.
// count the number of characters in the string s (not including the string NUL terminator)
void PrintEntryBanner(void);
void PrintExitBanner(void);

size_t StringLength(const char *s)
{
    size_t nCount = 0;
//  if the pointer points to NULL, return 0.  Failure
    if (NULL == s) return 0;
//  while pointer is non-void..
    while (*s) 
    {
//  increment the pointer by 1.  Increment nCount by 1.
        s += 1;
        nCount +=1;
    }
    //printf("Length of string: %d\n", nCount);
//  return the length of the string.  NOT INCLUDING NUL TERMINATOR '\0'
    return nCount;
}

// ---- EXPANDED STRING CONCATENATION FUNCTION DEFINITION ----
//  Formal parameter list (5 parameters):
//  char sDest, size_t nDest, const char *sSource1, char cSep, const char *sSource2
//  Destination buffer, size of the destination buffer, pointer-to-const string source1, string separator char, pointer-to-const string source2
size_t strcat_EX(char *sDest, size_t nDest, const char *sSource1, char cSeparator, const char *sSource2)
{
//  if sDest points to NULL, return 0
    if (sDest == NULL)		
        return 0;
//  if sSource1 points to NULL, return 0    
    if (sSource1 == NULL)
        return 0;
//  if sSource1 points to NULL, return 0    
    if (sSource2 == NULL)
        return 0;
//  if cSeparator points to NUL terminator character.
    if ('\0' == cSeparator) 
        return 0;		

//  nNeeded represents the length of the 2 source strings, plus the separator character.

//  declare size_t type and store the return value of the StringLength function.  Returns length of source1.  
    size_t nNeeded = StringLength(sSource1);    
//  add space to accomidate the seperator character between source1 and source2
    nNeeded += sizeof cSeparator;
//  add space to accomidate source2
    nNeeded += StringLength(sSource2);
//  add 1 to accomidate the null terminator
    nNeeded++;
//  if the length of the 2 source strings plus the separator character IS GREATER THAN the destination buffer
    if (nNeeded > nDest)			 
    {
        printf("nNeeded: %zd > nDest: %zd\n",nNeeded,nDest);
//  error - destination buffer not large enough to receive the two strings + separator + terminator
        return nNeeded;
    }
//  validate constraint 1 - source 1 allocation can be same as dest, otherwise the two buffers cannot overlap
//  sDest is a pointer to a constant char.  sDest is the DESTINATION BUFFER.  nDest is the SIZE OF THE DESTINATION BUFFER.
//  sSource1 is the first string to be concatenated.  sDest is the destination buffer.  nDest is the SIZE of the destination buffer.
// 
//  sSource1 holds the address of the first character in source1 string.  sDest holds the address of the first character in destination buffer.  nDest is length of //  the destination buffer

//  if address of first char in sSource1 is GREATER THAN the address of the first char in sDest
//  AND address of first char in sSource1 is LESS THAN the sum of the address of the first char in destination buffer and the length of the destination buffer
	if ((sSource1 > sDest) && (sSource1 < (sDest + nDest)))
    {
//  error - sSource1 string overlaps sDest
        printf("%s\n","Overlap case: sSource1 overlaps sDest");
        return 0;
    }


//  validate constraint 2 - source 2 and destination buffers cannot overlap
	if ((sSource2 > sDest) && (sSource2 < (sDest + nDest)))
    {
//  error - sSource2 string overlaps sDest
        printf("%s\n","Overlap case: sSource2 overlaps sDest");
        return 0;
    }

//  copy source 1 contents to the destination buffer if and only if destination and source 1 ARE NOT THE SAME.
    if (sSource1 != sDest)
    {
        printf("%s\n","sSource1 != sDest case");
//  Copy sSource1 to sDest memory buffer.  
        while(*sSource1)
        {
            *sDest++ = *sSource1++;
        }
//  Adds the cSeparator character
        *sDest++ = cSeparator;
//  Copy sSource2 to sDest
        while(*sSource2)
        {
            *sDest++ = *sSource2++;
        }
//  Append '\0' to sDest memory buffer
        *sDest = '\0';
    }
    
//  If the address of the string identified by sSource1 IS THE SAME as the address of the sDest string
    if (sSource1 == sDest)
    {
//  THEN the operation of the strcat_EX function is concatenate+concatenate
//  The separator character is appended to sDest(remember sDest == sSource1), then sSource2 is appended to the resultant sDest (sDest = sDest + cSep + sSource2)
//  So, first append cSeparator to sDest THEN append sSource2 to sDest
        printf("%s\n","sSource1 == sDest case");
//  pointer moved to the end of sSource1
        sDest += StringLength(sSource1);
//  Append cSeparator character to sDest
        *sDest++ = cSeparator;
//  Append sSource2 to destination buffer
        while (*sSource2)
        {
            *sDest++ = *sSource2++;
        }
//  Append '\0' to sDest memory buffer
        *sDest = '\0';
    }		
//  nNeeded is the length of the destination string, plus 1 for the terminating character.
    return nNeeded;
}

void PrintEntryBanner(void)
{
    printf("\n CSC-250 Spring 2017\n Dayna J. Blackwell\n Working With Strings - Part 2\n\n");
}

void PrintExitBanner(void)
{
    printf("\n\n All Done...\n CSC-250 Spring 2017\n Dayna J. Blackwell\n\n");
}


#define LONG_STRING_BUFFER_SIZE  500
#define SHORT_STRING_BUFFER_SIZE  5

void Test1(void)
{
//  Copy sSource1 to sDest.  Append cSeparator to sDest.  Append sSource2 to sDest.
//  Expected behavior: "Now is the time for+The quick brown fox to jump over the lazy dog's back""
//  !!!--PASSED--!!!

    printf("\n\nTest1\n");
//  allocate memory for an array of 500 char
    char sDest[LONG_STRING_BUFFER_SIZE];
    static const char *sSource1 = "Now is the time for";
    static const char *sSource2 = "The quick brown fox to jump over the lazy dog's back";
    static char cSeparator = '+';
//  result of concatenation operation will be:  "Now is the time for+The quick brown fox to jump over the lazy dog's back"  73 characters including NUL '\0'
    size_t nUsed = strcat_EX(sDest, sizeof sDest, sSource1, cSeparator, sSource2);
    printf("the size of the destination is: %zu\n", sizeof sDest);
    printf("the concatenated resultant is: '%s'\n", sDest);
    printf("the count of the concatenated resultant is: %zu\n", nUsed);
}

void Test2(void)
{
//  Case where sDest == sSource1.  
//  Append cSeparator to sDest.  Append sSource2 to sDest.
//  Expected behavior: "Now is the time for+The quick brown fox to jump over the lazy dog's back"   73 characters including NUL '\0'
//  This is the "special case where sDest is the same as sSource1"  You can see this in the parameter list where sDest is used in 2 places.
//  So overlap exists, but it must be allowed.

//  !!!--PASSED--!!!
    printf("\nTest2\n");
    char sDest[LONG_STRING_BUFFER_SIZE] = "Now is the time for";
    static const char *sSource2 = "The quick brown fox to jump over the lazy dog's back";
    static char cSeparator = '+';
    size_t nUsed = strcat_EX(sDest, sizeof sDest, sDest, cSeparator, sSource2);
    printf("the size of the destination is: %zu\n", sizeof sDest);
    printf("the concatenated resultant is: '%s'\n", sDest);
    printf("the count of the concatenated resultant is: %zu\n", nUsed);
}

void Test3(void)
{
//  Case where sDest < nNeeded, sDest != sSource1 && sDest != sSource2
// 
//  When nDest < nNeeded, sDest is left unchanged
//  Expected behavior: sDest left unchanged--"not changed - allocation too small"    35 characters including NUL '\0'
//  !!!--PASSED--!!!

    printf("\nTest3\n");
//  size of sDest will be 35, including the null terminator "\0"
    char sDest[] = "not changed - allocation too small";
    static const char *sSource1 = "Now is the time for";
    static const char *sSource2 = "The quick brown fox to jump over the lazy dog's back";
    static char cSeparator = '+';
//  nUsed holds the value of nNeeded, which is returned by the strcat_EX function
    size_t nUsed = strcat_EX(sDest, sizeof sDest, sSource1, cSeparator, sSource2);
    printf("the size of the destination is: %zu\n", sizeof sDest);
    printf("the concatenated resultant is: '%s'\n", sDest);
    printf("Allocation size needed to complete the copy/concatenate operation: %zu",nUsed);
    //printf("the count of the concatenated resultant is: %zu\n", nUsed);
}

void Test4(void)
{
//  OVERLAP CASE
//  sSource1 != to sDest.  sSource overlaps with sDest.  MUST BE REJECTED!
//  sDest+1 used for sSource1.  
//  Expected Behavior:  return 0;  Leave sDest unchanged.
    printf("\n\nTest4\n");
    char sDest[500] = "not changed - source 1 overlap";
    static const char *sSource2 = "The quick brown fox to jump over the lazy dog's back";
    static char cSeparator = '+';
//  (sDest+1) is used in place of sSource1.  So sDest+1 will overlap sDest and overwrite all but first character.
    size_t nUsed = strcat_EX(sDest, sizeof sDest, sDest + 1, cSeparator, sSource2);
    printf("the size of the destination is: %zu\n", sizeof sDest);
    printf("the concatenated resultant is: '%s'\n", sDest);
    printf("the count of the concatenated resultant is: %zu\n", nUsed);  
}

void Test5(void)
{
//  OVERLAP CASE where sSource2 OVERLAPS THE DESTINATION BUFFER.  MUST REJECT CASE. 
//  sDest+1 is used for sSource2.  So, sSource2 overlaps sDest.  Only the first char in sDest buffer is not overlapping.
//  Expected behavior:  return 0.  sDest buffer remains unchanged.
//  !!!--CASE 5: PASSED--!!!
    printf("\n\nTest5\n");
    char sDest[500] = "not changed - source 2 overlap";
    static const char *sSource1 = "Now is the time for";
    static char cSeparator = '+';
//  sSource2 overlaps sDest; sDest+1 used as sSource2.  Must reject
    size_t nUsed = strcat_EX(sDest, sizeof sDest, sSource1, cSeparator, sDest + 1);
    printf("the size of the destination is: %zu\n", sizeof sDest);
    printf("the concatenated resultant is: '%s'\n", sDest);
    printf("the count of the concatenated resultant is: %zu\n", nUsed);

}

void Test6(void)
{
//  OVERLAP CASE
//  
//  
    printf("\n\nTest6\n");
    char sDest[500] = "not changed - source 2 overlap";
    // printf("sDest address: %d",&sDest);
    static const char *sSource1 = "";
    // printf("%s\n",sSource1);
    // printf("sSource1 address: %d",&sSource1);
    static char cSeparator = '+';
    static const char *sSource2 = "";
    // printf("%s\n",sSource2);
    // printf("sSource2 address: %d",&sSource2);
    size_t nUsed = strcat_EX(sDest, sizeof sDest, sSource1, cSeparator, sSource2);
    printf("the size of the destination is: %zu\n", sizeof sDest);
    printf("the concatenated resultant is: '%s'\n", sDest);
    printf("the count of the concatenated resultant is: %zu\n", nUsed);
}

void Test7(void)
{
//  Reject case:  sDest assigned NULL.  Returns 0.
//  Expected behavior: 'null'
//  !!!--PASSED--!!!

    printf("\n\nTest7\n");
//  sDest is a pointer to char type.  assigned NULL.  
    char *sDest = NULL;
    size_t nDest = 100;
    static const char *sSource1 = "";
    static char cSeparator = '+';
    static const char *sSource2 = "";

    size_t nUsed = strcat_EX(NULL, nDest, sSource1, cSeparator, sSource2);
    printf("the size of the destination is: %zu\n", nDest);
    printf("the concatenated resultant is: '%s'\n", sDest);
    printf("the count of the concatenated resultant is: %zu\n", nUsed);
}

void Test8(void)
{
// Test case 8 will be rejected because cSeparator is NUL
// All cases that are rejected are required to leave the destination buffer unchanged, and return 0
// !!!--PASSED--!!!

    printf("\n\nTest8\n");
    char sDest[LONG_STRING_BUFFER_SIZE] = "not changed - separator is NUL";
    static const char *sSource2 = "The quick brown fox to jump over the lazy dog's back";
    static char cSeparator = '\0';

    size_t nUsed = strcat_EX(sDest, sizeof sDest, sDest, cSeparator, sSource2);
    printf("the size of the destination is: %zu\n", sizeof sDest);
    printf("the concatenated resultant is: '%s'\n", sDest);
    printf("the count of the concatenated resultant is: %zu\n", nUsed);
}

typedef void( * TpfnTestCase )(void);
static const TpfnTestCase TestSuiteSet[] = { Test1, Test2, Test3, Test4, Test5, Test6, Test7, Test8, NULL };

void TestSuite(void)
{
    static const char *sBanner = "**************************************************************";
    size_t nTestCases = sizeof(TestSuiteSet) / sizeof(TestSuiteSet[0]);
    printf("starting test suite - %zu cases\n%s\n", nTestCases, sBanner);

    // iterate over the test case set, execute each
    // end of set when we find NULL sentinel value
    for (const TpfnTestCase *pTestCase = TestSuiteSet; *pTestCase; pTestCase++)
    {
        (*pTestCase)();
    }
    printf("\n\n%s\ntest suite complete\n", sBanner);
}


int main(void)
{
    PrintEntryBanner();
    TestSuite();
    PrintExitBanner();
    return 0;
}
