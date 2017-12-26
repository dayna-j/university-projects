// This program uses a switch to call one of two different functions.  The first function uses a for-loop to print a string 4 times
// The second function counts down the numbers 0 - 10 in reverse order, followed by the string "Blastoff!" once 0 has been reached.

#include <stdio.h>
void printName(void);													// function prototype for printName function.  void return type, no parameters.
void countDown(void);													// function prototype for countDown function.  void return type, no parameters.

int main (void)
{
	int menu = 0;														// menu integer variable will serve as input to a switch that will call one of 
																		// two functions.
	puts("");
	printf("%s\n","What would you like to do?");						// output section for function choices.
	printf("\t%s\n","1. Print my name");
	printf("\t%s\n","2. Count down to 10");
	puts("");
	
	do
	{																	// A do-while loop is used for input exception handling.  when menu is equal to
																		// a valid input option
	printf("%s","Choice: ");											// then execution can continue
	scanf("%d", &menu);
	}
	while ( (menu != 1) && (menu != 2) );
	
	puts("");
	
	switch(menu)														// menu is input to the switch, and depending on its value, some function is called.
	{
		case 1:
		printName();													// when menu is equal 1, printName is called
		break;
		
		case 2:
		countDown();													// when menu is equal 2, countDown is called
		break;
	}
	return 0;
}

void printName(void)
{
	int x;
	for (x=1; x <= 4; x++)												// for loop is used to print a string 4 times
	{
	printf("%s\n","Hi, my name is Dayna");
	}
}

void countDown(void)
{
	int i;
	for (i=10; i >= 0; i--)												// for loop is used to print the numbers 0,10 in reverse order of magnitude
	{
		printf("%d\n",i);
		if (i==0) {printf("%s","Blastoff!");}							// when the control variable is equal 0, a string is printed.
	}
}
