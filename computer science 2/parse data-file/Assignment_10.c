
//
// Assignment_10.cpp 

// Important Note:
// --------------------------------
//  Memory is a system resource.
//    Allocation of memory, 
//    just as an allocation of a file, is handled via runtime calls 
//    that interact with the host operating system. System resournces must be managed.
//    If your application request a system resoruce, that resource must be returned 
//    to the system when your application has no further use for that system resoruce
//  
//  Memory is a system resource.
//    To request memory from the system at runtime, we use the malloc function. 
//    When we are through with that allocation, we relinquish ownership using the free function
//
//  Memory is a system resource. 
//    For ever call to malloc in your program, you program should have an 
//    accompanying free call to release the memory when it is not longer needed
//
//  Memory is a system resource. 
//    Count the number if times your program will execute the malloc function.
//    Then count the number of times your program will execute the free function on the value returned by the malloc call.
//    Those counts **MUST** be the same, never more and never less
//


#define _CRT_SECURE_NO_WARNINGS


#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>


#define DebugPrint false

void ShowUsage()
{
    printf("  Application Usage:\n"
           "       ./Assignment_10   -count <items>  -data <path>\n"
           "  where:\n"
           "       <items> is the number or records to read from the input path\n"
           "       <path> file pathname to the input data - comma separated data format\n\n");
}

// 
typedef struct _CustomerRec
{
    char *sFirstName;
    char *sMiddleName;
    char *sLastName;
    char *sAddress;
    char *sCity;
    char *sState;
    char *sZipcode;
    char *sEmailAddress;
    char *sLoginID;
    char *sPassword;
    char *sSSN;
    char *sCreditCardType;
    char *sCreditCardNumber;
    char *sCreditCardExpirey;
// initialize a struct _CustomerRec object named CustomerRecord
} CustomerRecord;

const char *g_szAuthor = "Dayna Blackwell";
const char *g_szAssignment = "Working with Dynamic Memory Part II";

void PrintEntryBanner()
{
    printf("\n CSC-250 Spring 2017\n %s\n CSC-250 %s\n\n", g_szAuthor, g_szAssignment);
}

void PrintExitBanner()
{
    printf("\n\n All Done...\n CSC-250 Spring 2017\n %s\n\n", g_szAuthor);
}

#define  MAX_CUSTOMER_LINE_CHARACTER_COUNT  1460

// defines 2 parameters:  pointer to a file stream and a pointer to a CustomerRecord-struct
_Bool ReadSingleRecord(FILE *pFile, CustomerRecord *pRec)
{
//  sBuffer is an array of 1460 char.  1460 is the maximum character counter per line of input    
    char sBuffer[MAX_CUSTOMER_LINE_CHARACTER_COUNT] = "";

//  fgets prototype:  char * fgets ( char * str, int num, FILE * stream )
//  returns pointer to char.  Reads characters from FILE stream, stores them in str string.  Reads num-1 chars.  Automatically appends ascii-NUlL to the end.
    if (NULL == fgets(sBuffer, MAX_CUSTOMER_LINE_CHARACTER_COUNT, pFile))
//  false is returned ONLY IF an error occurs
        return false;
//  pointer to char initialized to null pointer    
    char *pContext = NULL;

//  char strtok_s(sToken, strDelimiter, context)
//  sToken will be the 'tokenized' version of sBuffer.  strDelimiter is the token to search for.  ',' , in this case.  
//  context stores position information between calls to strlok_s
//  strtok_s Returns a pointer to the next token found in sToken

//  sToken is a pointer to character type which points to the next token found.
//  sBuffer is a character array for the current 1460 character "line" of input
//  "," is the token to search for.  
//  &pContext is the address of pContext.  Allows pass-by-reference for changing data "in place"
//  pContext is used to store position between calls.
//
//  EACH CALL TO strtok_s MODIFIES sBuffer BY INSERTING AN ASCII-NULL CHARACTER AFTER THE TOKEN RETURNED BY THAT CALL.
//  The strncpy function will use these ascii-nulls to find the end of the current data record.

//  sToken is a pointer to a string.  strTok_s returns a pointer to the current token. sToken will point to the current token and the token will be NULL ter    minated
    
    char *sToken = strtok_s(sBuffer, ",", &pContext);
    if (sToken == NULL) return false;
//  determine length of the token and allocate sufficient storage to store a string of that length, keeping in mind that the null terminator must be stored too    
    pRec->sFirstName = malloc(strlen(sToken)+1);
    strncpy(pRec->sFirstName, sToken, (strlen(sToken)+1));
    if (DebugPrint) printf(" first name: %s\n", pRec->sFirstName);

    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    pRec->sMiddleName = malloc(strlen(sToken)+1);
    strncpy(pRec->sMiddleName, sToken, (strlen(sToken)+1));
    if (DebugPrint) printf(" middle name: %s\n", pRec->sMiddleName);

    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    pRec->sLastName = malloc(strlen(sToken)+1);
    strncpy(pRec->sLastName, sToken, (strlen(sToken)+1));
    if (DebugPrint) printf(" Last Name: %s\n", pRec->sLastName);

    sToken = strtok_s(NULL, "\"", &pContext);
    if (sToken == NULL) return false;
    pRec->sAddress = malloc(strlen(sToken)+1);
    strncpy(pRec->sAddress, sToken, (strlen(sToken)+1));
    if (DebugPrint) printf(" Address: %s\n", pRec->sAddress);

    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    pRec->sCity = malloc(strlen(sToken)+1);
    strncpy(pRec->sCity, sToken, (strlen(sToken)+1));
    if (DebugPrint) printf(" City: %s\n", pRec->sCity);

    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    pRec->sState = malloc(strlen(sToken)+1);
    strncpy(pRec->sState, sToken, (strlen(sToken)+1));
    if (DebugPrint) printf(" State: %s\n", pRec->sState);

    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    pRec->sZipcode = malloc(strlen(sToken)+1);
    strncpy(pRec->sZipcode, sToken, (strlen(sToken)+1));
    if (DebugPrint) printf(" Zipcode: %s\n", pRec->sZipcode);

    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    pRec->sEmailAddress = malloc(strlen(sToken)+1);
    strncpy(pRec->sEmailAddress, sToken, (strlen(sToken)+1));
    if (DebugPrint) printf(" Email Address: %s\n", pRec->sEmailAddress);

    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    pRec->sLoginID = malloc(strlen(sToken)+1);
    strncpy(pRec->sLoginID, sToken, (strlen(sToken)+1));
    if (DebugPrint) printf(" Login ID: %s\n", pRec->sLoginID);

    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    pRec->sPassword = malloc(strlen(sToken)+1);
    strncpy(pRec->sPassword, sToken, (strlen(sToken)+1));
    if (DebugPrint) printf(" Password: %s\n", pRec->sPassword);

    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    pRec->sSSN = malloc(strlen(sToken)+1);
    strncpy(pRec->sSSN, sToken, (strlen(sToken)+1));
    if (DebugPrint) printf(" SSN: %s\n", pRec->sSSN);

    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    pRec->sCreditCardType = malloc(strlen(sToken)+1);
    strncpy(pRec->sCreditCardType, sToken, (strlen(sToken)+1));
    if (DebugPrint) printf(" Credit Card Type: %s\n", pRec->sCreditCardType);

    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    pRec->sCreditCardNumber = malloc(strlen(sToken)+1);
    strncpy(pRec->sCreditCardNumber, sToken, (strlen(sToken)+1));
    if (DebugPrint) printf(" Credit Card Number: %s\n", pRec->sCreditCardNumber);

    sToken = strtok_s(NULL, ",\r\n", &pContext);
    if (sToken == NULL) return false;
    pRec->sCreditCardExpirey = malloc(strlen(sToken)+1);
    strncpy(pRec->sCreditCardExpirey, sToken, (strlen(sToken)+1));
    if (DebugPrint) printf(" Credit Card Expirey: %s\n", pRec->sCreditCardExpirey);

    return true;
}

// iterate over the input data file, 1 record at a time
// dynamically allocate a CustomerRecord and call ReadSingleRecord 
// to populate the struct from the current record in the file
// If ReadSingleRecord returns success, capture the dynamic allocated record,
// else free it and return 

//  pFile is a pointer to a file stream.  nRecordCount is how many struct are needed.  *customerRecords[] is an array of pointers-to-CustomerRecord-structs

void ProcessInputData(FILE *pFile, size_t nRecordCount, CustomerRecord *customerRecords[])
{
//  a static, constant CustomerRecord type struct named emptyRecord is initialized to NULL
    static const CustomerRecord emptyRecord = {NULL};

//  FOR LOOP is used to iterate over the structs/records.  nRecordCount corresponds to the number of structs in the array of pointers to struct
    for (size_t nRecordNumber = 0; nRecordNumber < nRecordCount; nRecordNumber++)
    {
//  pRec is a pointer to a CustomerRecord struct.  It is initialized to NULL, which is considered to be "best practice"
        CustomerRecord *pRec = NULL;
//  pRec will point to memory dynamically allocated for the struct
        pRec = malloc(sizeof(CustomerRecord));

        malloc(sizeof(CustomerRecord));
        if (NULL == pRec)
        {
            printf("\n Customer Record Allocation failed...\n");
            return;
        }
        
        *pRec = emptyRecord; // little trick using struct copy to initialize the contents to known values
//  DebugPrint defined to be boolean false        
        if (DebugPrint) printf(" reading record: %zu\n", nRecordNumber + 1);

//  ReadSingleRecord funct is where the file stream is accessed and data is transferred from the input file into a memory buffer        
//  ReadSingleRecord returns true when successfull and false otherwise.  sts will be either true or false...
        _Bool sts = ReadSingleRecord(pFile, pRec);
//  Remember, pRec points to the struct.  WE NEED TO USE customerRecords[] ARRAY HERE!!!
        if (sts)
//  if sts is true, ReadSingleRecord was successful.  Data has been stored and a struct-pointer must be stored in the customerRecords array. . .
        {
//  so the VALUES of the array must be the addresses to the struct records
            customerRecords[0] = pRec;
            customerRecords++;
        }
        else if(!sts)
        {
            free(pRec);
            pRec = NULL;
        }
    }
}

// iterate over the recordset, check each entry, 
// if entry is valid, print the contents to the console
// ----------------------------------------------------------------
void DumpCustomerRecordSet(size_t nRecordCount, CustomerRecord *recSet[])
{
    for (size_t n = 0; n < nRecordCount; n++)
    {
        if(NULL == recSet[n])       // do not attempt to dereference NULL pointer (skip uninitialized records in set)
            continue;

        printf(" Record %zu:\n\t%s %s %s\n\t%s %s %s %s\n\t%s, %s, %s\n\t%s\n\t%s: %s (%s)\n", n + 1,
            recSet[n]->sFirstName, recSet[n]->sMiddleName, recSet[n]->sLastName,
            recSet[n]->sAddress, recSet[n]->sCity, recSet[n]->sState, recSet[n]->sZipcode,
            recSet[n]->sEmailAddress, recSet[n]->sLoginID, recSet[n]->sPassword,
            recSet[n]->sSSN,
            recSet[n]->sCreditCardType, recSet[n]->sCreditCardNumber, recSet[n]->sCreditCardExpirey);
    }
}

// iterate over the recordset, check each entry, 
// if any have an allocation, free the contents of that allocation,
// then free the allocation
// ----------------------------------------------------------------

//  nRecords is the number of pointers in the array of pointer-to-structs.  recSet is the array of structs, passed as pointer to pointer
void ReleaseCustomerRecordSet(size_t nRecords, CustomerRecord **recSet)
{
    
    for (size_t n = 0; n < nRecords; n++)
    {
        if(recSet[n])
        {
            free(recSet[n]->sFirstName);
            recSet[n]->sFirstName = NULL;
            free(recSet[n]->sMiddleName);
            recSet[n]->sMiddleName = NULL;
            free(recSet[n]->sLastName);
            recSet[n]->sLastName = NULL;
            free(recSet[n]->sAddress);
            recSet[n]->sAddress = NULL;
            free(recSet[n]->sCity);
            recSet[n]->sCity = NULL;
            free(recSet[n]->sState);
            recSet[n]->sState = NULL;
            free(recSet[n]->sZipcode);
            recSet[n]->sZipcode = NULL;
            free(recSet[n]->sEmailAddress);
            recSet[n]->sEmailAddress = NULL;
            free(recSet[n]->sLoginID);
            recSet[n]->sLoginID = NULL;
            free(recSet[n]->sPassword);
            recSet[n]->sPassword = NULL;
            free(recSet[n]->sSSN);
            recSet[n]->sSSN = NULL;
            free(recSet[n]->sCreditCardType);
            recSet[n]->sCreditCardType = NULL;
            free(recSet[n]->sCreditCardNumber);
            recSet[n]->sCreditCardNumber = NULL;
            free(recSet[n]->sCreditCardExpirey);
            recSet[n]->sCreditCardExpirey = NULL;
            
            free(recSet[n]);
            recSet[n] = NULL;
        }
    }
}


// iterate over the recordset, check each entry, 
// return false if any have allocation (i.e. are not NULL)
// ----------------------------------------------------------------
_Bool AllCleaned(size_t nRecords, CustomerRecord **recSet)
{
    if(NULL == recSet)
        return true;
    for (size_t n = 0; n < nRecords; n++)
    {
        if(recSet[n])
            return false;
    }
    return true;
}


// iterate over the recordset, check each entry, 
// compute count of non NULL entries
// ----------------------------------------------------------------
size_t CountOfAllocatedRecords(size_t nRecords, CustomerRecord *recSet[])
{
    size_t nAllocatedRecords =0;
    while ( (recSet[nAllocatedRecords] ) && (nAllocatedRecords <nRecords) ) nAllocatedRecords++;

    return nAllocatedRecords;
}


// usage: there will be 5 elements in argValues array
//    Programming_Assignment_10  -count n  -data  ./fake_names.dat
// ------------------------------------------------------------------

//	argValues is an array of pointer of char.  Each pointer points to a string.  argCnt represents the number of string-pointers in argValues[] array
int main(int argCnt, char *argValues[])
{
    PrintEntryBanner();
//  customerRecordSet is a pointer to a pointer to a CustomerRecord-struct.  CustomerRecordSet will function as an ARRAY OF POINTER-TO-STRUCT OBJECTS
    CustomerRecord **customerRecordSet = NULL;

//  argCnt needs to be greater than 4.  strcmp tests input flags '-data' and '-count'
    if ((argCnt > 4) && (0 == strcmp("-data", argValues[3])) && (0 == strcmp("-count", argValues[1])))
    {
//  int atoi (const char * str)     accepts a pointer to a string as parameter.  returns integer interpretation of the input argument
//  nRecProcessCount is a size_t type.  atoi converts from ascii to integer.  nRecProcessCount will hold the int representation of the number following -count
//  
//  nRecProcessCount will be the size_t type representation of the integer passed to argValues[2]
        size_t nRecProcessCount = atoi(argValues[2]);
//  cannot process 0 records or more than 500 records.  Error is printed.
        if ( (nRecProcessCount == 0) || (nRecProcessCount > 500))
        {
            printf("\n ERROR --  Invalid record count: %s\n\n", argValues[2]);
            return 0;
        }
//  argValues[4] will contain the path to the fake_names.dat file
        char *pInputFilePath = argValues[4];
//  pFile is a pointer to a file stream.  fopen returns a pointer to a file stream.  pInputFilePath will contain the path to fake_names.dat
        FILE *pFile = fopen(pInputFilePath, "rt");
//  if pFile is NOT NULL
        if (NULL != pFile)
        {
            size_t nAllocationBytes = 0;
//  sizeof CustomerRecord returns size of the STRUCT POINTER .Multiplying by nRecProcessCount gives the number of bytes needed for n-many struct pointers            
            nAllocationBytes = sizeof(CustomerRecord*)*nRecProcessCount;
//          **customerRecordSet is used to allocate the memory for the array of pointers-to-struct
            customerRecordSet = malloc(nAllocationBytes);

//  will equal NULL only if malloc failed to allocate memory
            if (NULL == customerRecordSet)
            {
                printf("\n ERROR --  Failed to allocate customer record set\n\n");
            }
            else
            {
//  all array values are initialized to NULL.
                for (size_t n = 0; n<nRecProcessCount; n++)                           // record set is now allocated (a dynamic array of pointers to CustomerRecord)
                    customerRecordSet[n] = NULL;                            // initialize the array so we don't have any invalid pointers hanging around
//  
                printf("\n Processing %zu records from data file:%s\n\n", nRecProcessCount, pInputFilePath);

//  void ProcessInputData(FILE *pFile, size_t nRecordCount, CustomerRecord *customerRecords[])
//  accepts 3 arguments.  pFile is a pointer to a file stream.  nRecordCount will refer to the number of structs needed.
//  CustomerRecord *customerRecords[] is an array of pointers-to-CustomerRecord-structs
//
                ProcessInputData(pFile, nRecProcessCount, customerRecordSet);         // populate the array with dynamic records, populated with file data
//
//  CountOfAllocatedRecords has 2 formal parameters.  nRecProcessCount is the number of structs.  customerRecordSet is an array of pointers-to-struct
//  returns the number of structs in the array
                size_t nRecordsInSet = CountOfAllocatedRecords(nRecProcessCount, customerRecordSet);
                printf("Found %zu records in dynamic allocated record set\n", nRecordsInSet);
                
                printf("\n Dump Record Set to console\n------------------------------\n");

//  DumpCustomerRecordSet prints the dynamic records to console.
//  Accepts 2 parameters:  nRecProcessCount, customerRecordSet.
//  nRecProcessCount is how many elements are in the struct-array.  customerRecordSet is the array of pointer-to-struct 's

                DumpCustomerRecordSet(nRecProcessCount, customerRecordSet);           // dump contents of the dynamic array of records to the console
                // printf("\ntest: BEFORE MEMORY RELEASE 1\n");
                ReleaseCustomerRecordSet(nRecProcessCount, customerRecordSet);        // all done with the records, free the memory
                // printf("\ntest: AFTER MEMORY RELEASE 1\n");
                // printf("\ntest: BEFORE MEMORY RELEASE 2\n");
                ReleaseCustomerRecordSet(nRecProcessCount, customerRecordSet);        // try again - see that free on an empty set works as expected
                // printf("\ntest: AFTER MEMORY RELEASE 2\n");

                if (AllCleaned(nRecProcessCount, customerRecordSet))                  // if all of the memory for all of the records has been reclaimed
                {
                    free(customerRecordSet);                                // then we can free the record set
                    customerRecordSet = NULL;
                }
                else
                {
                    printf("\n ERROR --  cannot free customer record set - arrary entries still allocated\n\n");
                }
            }
            fclose(pFile);
        }
        else
        {
            printf("\n\n ERROR - failed to open input data file: %s\n\n", pInputFilePath);
        }
    }
    else
    {
        printf("\n\n ERROR - invalid command line arguments\n");
        ShowUsage();
    }
    PrintExitBanner();

    return 0;
}


// NOTES ABOUT strtok_s

// strtok_s modifies the currently copied data record. It replaces the ',' delimiter with '\0' ascii-null
// it's important to remember that the delimiters are being ***replaced***
//
// If str != NULL, the call is treated as the FIRST CALL TO strtok_s FOR THIS PARTICULAR STRING. 
// The function searches for the first character which is NOT CONTAINED IN THE DELIMITER.
// From that point forward, strtok_s searches for the delimiter.  After the delimiter is found, it is ***replaced by ascii-null***
// That "segment" of the string is now considered a "token."  
// The address to the NEXT INDEX POSITION after the ascii-null that was just inserted is stored in 'pContext' for subsequent calls
//
//
// !!!! If str == NULL, then the call will be treated as a SUBSEQUENT CALL to strtok_s  !!!!
// The function will continue where it left off and attempt to tokenize the string.  Function will use pContext to find the correct address