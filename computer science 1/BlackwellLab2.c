/* 
    Write a program that asks the user to enter two numbers, obtains them 
    from the user and prints their sum, difference, product, quotient
    and remainder in that order.

Ex.
Enter the first integer: 	20
Enter the second integer: 	11

The sum is: 			31
The difference is: 		9
The product is: 		220
The quotient is: 		1
The remainder is: 		9
*/

#include <stdio.h>

int main(void)
{
	int firstInt;
	int secondInt;
	
	printf("\n");
	printf("Enter the first integer:\t");
	scanf("%d", &firstInt);	
	printf("Enter the second integer:\t");
	scanf("%d", &secondInt);
	printf("\n");
	
	printf("The sum is:\t\t%d\n" , firstInt + secondInt);
	printf("The difference is:\t%d\n" , firstInt - secondInt);
	printf("The product is:\t\t%d\n" , firstInt * secondInt);
	printf("The quotient is:\t%d\n" , firstInt / secondInt);
	printf("The remainder is:\t%d\n" , firstInt % secondInt);
	return 0;
	
}
