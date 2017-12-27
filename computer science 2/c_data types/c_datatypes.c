
// AUTHOR :    Dayna Blackwell        START DATE :    01/25/2017
// c-datatypes.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

int main(void)
{
    printf("\nc_datatypes demonstration\n");
    printf("Dayna Blackwell\n");
    printf("CSC-250 Programming Assignment 01, due date: 30 Jan 2017\n");

    _Bool b = false;
    size_t nBytes = sizeof(_Bool);
    printf("\nsize of _Bool: %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    nBytes = sizeof b;
    printf("size of the variable 'b': %zu byte(s)\n", nBytes);
    printf("value of the variable 'b': %d\n", b);

    char c = 'a';
    nBytes = sizeof(char);
    printf("\nsize of char: %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    nBytes = sizeof c;
    printf("size of the variable 'c': %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    printf("value of the variable 'c': '%c' (0%02o oct)  (%d dec)  (0x%02x hex)\n", c, c, c, c);
    
    int i = 123;
    nBytes = sizeof(int);
    printf("\nsize of int: %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    nBytes = sizeof i;
    printf("size of the variable 'i': %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    printf("value of the variable 'i': %d\n", i);

    long l = 123;
    nBytes = sizeof(long);
    printf("\nsize of long: %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    nBytes = sizeof l;
    printf("size of the variable 'l': %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    printf("value of the variable 'l': %ld\n", l);

    size_t st = 123456;
    nBytes = sizeof(size_t);
    printf("\nsize of size_t: %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    nBytes = sizeof st;
    printf("size of the variable 'st': %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    printf("value of the variable 'st': %zu\n", st);

    uintptr_t uip = 123456789;
    nBytes = sizeof(uintptr_t);
    printf("\nsize of uintptr_t: %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    nBytes = sizeof uip;
    printf("size of the variable 'ip': %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    printf("value of the variable 'uip': %" PRIxPTR"\n", uip);

    long long ll = 123;
    nBytes = sizeof(long long);
    printf("\nsize of long long: %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    nBytes = sizeof ll;
    printf("size of the variable 'll': %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    printf("value of the variable 'll': %lld\n", ll);

    float f = 123.12302f;
    nBytes = sizeof(float);
    printf("\nsize of float: %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    nBytes = sizeof f;
    printf("size of the variable 'f': %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    printf("value of the variable 'f': %.7f\n", f);

    double d = 123.12345;
    nBytes = sizeof(double);
    printf("\nsize of double: %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    nBytes = sizeof d;
    printf("size of the variable 'd': %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    printf("value of the variable 'd': %.7lf\n", d);

    long double ld = 1234.123456;
    nBytes = sizeof(long double);
    printf("\nsize of long double: %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    nBytes = sizeof ld;
    printf("size of the variable 'ld': %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    printf("value of the variable 'ld': %.7Lf\n", ld);

    void *pv = (void *)0x1000200012345678;
    nBytes = sizeof(void *);
    printf("\nsize of void * pointer: %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    nBytes = sizeof pv;
    printf("size of the variable 'pv': %zu %s\n", nBytes, nBytes>1 ? "bytes" : "byte");
    printf("value of the variable 'pv': %p\n", pv);

    printf("\nProgram completion status: success\n");
    printf("Dayna Blackwell\n");

    return 0;
}

