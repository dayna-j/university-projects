//
// StructureAssignment.c
//
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>

#define _CRT_SECURE_NO_WARNINGS
#define  RECORD_FIELD_CHARACTER_COUNT   96
#define  MAX_RECORD_PROCESSING_COUNT    10
#define DebugPrint false

// ----------------------------
//  <<TODO>>
//    Create a struct definition here to capture the 14 fields represented
//      by the data read from the input file
//    Use the typedef form, and also include the struct tag field
// ----------------------------

typedef struct dataRecord
{
 char FirstName[RECORD_FIELD_CHARACTER_COUNT];
 char MiddleName[RECORD_FIELD_CHARACTER_COUNT];
 char LastName[RECORD_FIELD_CHARACTER_COUNT];
 char Address[RECORD_FIELD_CHARACTER_COUNT];
 char City[RECORD_FIELD_CHARACTER_COUNT];
 char State[RECORD_FIELD_CHARACTER_COUNT];
 char Zipcode[RECORD_FIELD_CHARACTER_COUNT];
 char EmailAddress[RECORD_FIELD_CHARACTER_COUNT];
 char LoginID[RECORD_FIELD_CHARACTER_COUNT];
 char Password[RECORD_FIELD_CHARACTER_COUNT];
 char SSN[RECORD_FIELD_CHARACTER_COUNT];
 char CreditCardType[RECORD_FIELD_CHARACTER_COUNT];
 char CreditCardNumber[RECORD_FIELD_CHARACTER_COUNT];
 char CreditCardExpirey[RECORD_FIELD_CHARACTER_COUNT];
}dataRecord;

void PrintEntryBanner()
{
    printf("\n CSC-250 Spring 2017\n Dayna Blackwell\n CSC-250 Working with Structures\n\n");
}

void PrintExitBanner()
{
    printf("\n\n All Done...\n CSC-250 Spring 2017\n Dayna Blackwell\n\n");
}

#define  MAX_CUSTOMER_LINE_CHARACTER_COUNT  1460

// ----------------------------
//  <<TODO>>
//    Replace the 14 arguments that receive the values from the 
//       fields captured from the file record with a single struct argument         --- !!! DONE !!!
//
//    Then refactor the codes in this function to copy the field values from        --- !!! DONE !!!
//       the file record to the appropriate field in the struct
// ----------------------------

_Bool ReadSingleRecord(FILE *pFile, dataRecord *currentRecord)
{
    char sBuffer[MAX_CUSTOMER_LINE_CHARACTER_COUNT] = "";
    if(NULL == fgets(sBuffer, MAX_CUSTOMER_LINE_CHARACTER_COUNT, pFile))
        return false;
    char *pContext = NULL;
    char *sToken = strtok_s(sBuffer, ",", &pContext);
    if(sToken == NULL) return false;
    strncpy(currentRecord->FirstName, sToken, RECORD_FIELD_CHARACTER_COUNT);
if(DebugPrint) printf(" first name: %s\n", currentRecord->FirstName);
    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    strncpy(currentRecord->MiddleName, sToken, RECORD_FIELD_CHARACTER_COUNT);
if(DebugPrint) printf(" middle name: %s\n", currentRecord->MiddleName);
    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    strncpy(currentRecord->LastName, sToken, RECORD_FIELD_CHARACTER_COUNT);
if(DebugPrint) printf(" Last Name: %s\n", currentRecord->LastName);
    sToken = strtok_s(NULL, "\"", &pContext);
    if (sToken == NULL) return false;
    strncpy(currentRecord->Address, sToken, RECORD_FIELD_CHARACTER_COUNT);
if(DebugPrint) printf(" Address: %s\n", currentRecord->Address);
    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    strncpy(currentRecord->City, sToken, RECORD_FIELD_CHARACTER_COUNT);
if(DebugPrint) printf(" City: %s\n", currentRecord->City);
    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    strncpy(currentRecord->State, sToken, RECORD_FIELD_CHARACTER_COUNT);
if(DebugPrint) printf(" State: %s\n", currentRecord->State);
    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    strncpy(currentRecord->Zipcode, sToken, RECORD_FIELD_CHARACTER_COUNT);
if(DebugPrint) printf(" Zipcode: %s\n", currentRecord->Zipcode);
    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    strncpy(currentRecord->EmailAddress, sToken, RECORD_FIELD_CHARACTER_COUNT);
if(DebugPrint) printf(" Email Address: %s\n", currentRecord->EmailAddress);
    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    strncpy(currentRecord->LoginID, sToken, RECORD_FIELD_CHARACTER_COUNT);
if(DebugPrint) printf(" Login ID: %s\n", currentRecord->LoginID);
    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    strncpy(currentRecord->Password, sToken, RECORD_FIELD_CHARACTER_COUNT);
if(DebugPrint) printf(" Password: %s\n", currentRecord->Password);
    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    strncpy(currentRecord->SSN, sToken, RECORD_FIELD_CHARACTER_COUNT);
if(DebugPrint) printf(" Password: %s\n", currentRecord->SSN);
    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    strncpy(currentRecord->CreditCardType, sToken, RECORD_FIELD_CHARACTER_COUNT);
if(DebugPrint) printf(" Credit Card Type: %s\n", currentRecord->CreditCardType);
    sToken = strtok_s(NULL, ",", &pContext);
    if (sToken == NULL) return false;
    strncpy(currentRecord->CreditCardNumber, sToken, RECORD_FIELD_CHARACTER_COUNT);
if(DebugPrint) printf(" Credit Card Number: %s\n", currentRecord->CreditCardNumber);
    sToken = strtok_s(NULL, ",\r\n", &pContext);
    if (sToken == NULL) return false;
    strncpy(currentRecord->CreditCardExpirey, sToken, RECORD_FIELD_CHARACTER_COUNT);
if(DebugPrint) printf(" Credit Card Expirey: %s\n", currentRecord->CreditCardExpirey);
    return true;
}

// ----------------------------
//  <<TODO>>
//    Replace the 14 aggregates (char arrary declarations) below with the 
//       with a single declaration of the struct that was previously defined            ---!!! DONE !!!---
//
//    Then refactor the codes below to pass the struct declaration to                   ---!!! DONE !!!---
//       the ReadSingleRecord function to be populated
//
//    Change the printf function to print the values from the struct that was           ---!!! DONE !!!---
//       populated from the parsed data recrod form the input file
// ----------------------------


void ProcessInputData(FILE *pFile, size_t nRecordCount)
{
    for (size_t nRecordNumber = 1; nRecordNumber <= nRecordCount; nRecordNumber++)
    {
        dataRecord currentRecord = {' '};
        if(DebugPrint) printf(" reading record: %zu\n",nRecordNumber);
        _Bool sts = ReadSingleRecord(pFile, &currentRecord);
        if (sts)
        {
            printf(" Record %zu:\n\t%s %s %s\n\t%s %s %s %s\n\t%s, %s, %s\n\t%s\n\t%s: %s (%s)\n", nRecordNumber,
                            currentRecord.FirstName, currentRecord.MiddleName, currentRecord.LastName,
                            currentRecord.Address, currentRecord.City, currentRecord.State, currentRecord.Zipcode, 
                            currentRecord.EmailAddress, currentRecord.LoginID, currentRecord.Password,
                            currentRecord.SSN,
                            currentRecord.CreditCardType, currentRecord.CreditCardNumber, currentRecord.CreditCardExpirey);
        }
        else
        {
            printf("\n Read Record Status: FAIL...\n");
            break;             // break on error (assuming end of file)
        }
    }
}

// usage:
//    Programming_Assignment_9  -data  ./fake_names.dat
// ------------------------------------------------------------------


// main function defined with 2 formal parameters: integer argCnt and argValues pointer to an array of strings.  
// argCnt will be equal to the number of strings pointed to by argValues.  This is the number of arguments passed in from command-line
// argValues is a pointer to an array of strings.  
// argValues[0] will hold the name of the program.
//
// Proper usage of the program requires argCnt > 2.  

int main(int argCnt, char *argValues[])                                                             
{
    PrintEntryBanner();
//  if argCnt greater than 2 AND the string held in index position 1 of argValues is equal to the string literal "-data", enter if-body
    if ((argCnt > 2) && (0 == strcmp("-data", argValues[1])))
    {
//      declare pFile.  pFile is a pointer to FILE object.
//      Opens the filename specified by the first argument and associates it with a stream accessed by file pointer.
//      rt mode: read text
        FILE *pFile = fopen(argValues[2], "rt");
//      NULL WOULD ONLY BE RETURNED IF THE SPECIFIED INPUT FILE FAILED TO BE OPENED.
//      if NULL is unequal to pFile, then the input file has been opened successfully
        if (NULL != pFile)
        {
//      pointer to the input file is passed to the ProcessInputData function. MAX_RECORD_PROCESSING_COUNT defined to be 10.
            ProcessInputData(pFile, MAX_RECORD_PROCESSING_COUNT);
            fclose(pFile);
        }
        else
        {
            printf("\n\n ERROR - failed to open input data file: %s\n\n", argValues[2]);
        }
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