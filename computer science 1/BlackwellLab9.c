// This program uses 2 functions to convert miles to kilometers and kilometers to miles

#include <stdio.h>

double kilToMiles(int);								// function prototype for kilometer to miles conversions.  Accepts int, returne double.
double milesToKil(int);								// function prototype for miles to kilometers conversion.  Accepts int, returns double.

int main (void)
{
	int x;									// declare int for use as control variable in for loop.
	
	puts("");
	printf("%s", "Kilometers per hour converted to miles per hour: ");
	puts("");
	
	printf("%s\t%s\n","Kph", "Mph");
	
	for (x=185; x >= 0; x-=5)						// counter controlled loop is used to pass arguments into the conversion functions
	{
		printf("%i\t%.0lf\n",x,kilToMiles(x));				// kilToMiles function is called within the argument list of printf. 
	}																	// conversion function is passed control variable as an argument.
	
	puts("");
	printf("%s", "Miles per hour converted to kilometers per hour: ");
	puts("");
	printf("%s\t%s\n","Kph", "Mph");

	for (x=115; x>=0; x-=5)
	{
		printf("%i\t%.0lf\n",x,milesToKil(x));
	}
	
	return 0;
}

double kilToMiles(int kilometers)						// full kilometer to miles function definition.
{
	return kilometers*0.621371;						// returns kilometers multiplied by the appropriate conversion factor, returning
																		// a value in miles
	
}

double milesToKil(int miles)							// full miles to kilometer function defintion.
{
	return miles*1.60934;							// returns miles multiplied by the appropriate conversion factor, returning
										// a value in kilometers.
}
