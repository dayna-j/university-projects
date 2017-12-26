/*
Program uses a counter-controlled for loop to calculate the average grade for some student.
accum variable accumulates total earned points.  accum is divided by the total number of grades
to produce an average. 

A set of if and else-if selection statements selects an appropriate letter grade for the
grade average.
 
*/


#include <stdio.h>

int main(void)
{
	float accum = 0;													// floating point type used to collect total earned points
	float grade = 0;													// floating point type used to temporarily hold user input
	float myGrade;														// float type used to hold final grade average
	unsigned int counter;												// unsigned int used in for-loop
	unsigned int numGrades;
	
	puts("");
	printf("%s", "How many grade items would you like to enter?\t");	
	scanf("%u", &numGrades);
	puts("");
	
	for (counter = 1; counter <= numGrades; ++counter)					// counter controlled for loop.   compares counter variable to numGrades.
	{
		printf("%s%u: ", "Enter the grade for grade item number ", counter);	
		scanf("%f",&grade);
		accum = accum + grade;											// add current grade to accumulator
	}
	
	puts("");
	printf("%s%.2f%%","Average grade: ", (accum/numGrades));			// divide earned points by number of grade items.  Print average with precision of 2.
	puts("");
	
	myGrade = (accum/numGrades);										// assign final grade average to myGrade

	if (myGrade >= 90)
	{
		printf("%s","Letter grade: A");
	}
	else if (myGrade >= 80)
	{
		printf("%s","Letter grade: B");
	}
	else if (myGrade >= 70)
	{
		printf("%s","Letter grade: C");
	}
	else if (myGrade >= 60)
	{
		printf("%s","Letter grade: D");
	}
	return 0;
}	
