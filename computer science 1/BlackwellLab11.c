#include <stdio.h>
#define SIZE 6

void numericToLetter(int numeric);
void numericSort(int grade[]);
float averageGrade(int grade[]);

int main(void)
{
	int gradeArray[SIZE];					// declare array of SIZE = 6 many integers.
	int grade;						// int variable holds current grade input by user until it is stored in the array
	int x;							// for loop control variable
	int average;
	
	for (x=0; x<SIZE;x++)
	{
		do
		{
		printf("%s%d%s","Enter grade ", x+1, ": ");	// input for each grade
		scanf("%d",&grade);						 
		}
		while(grade > 100 || grade < 0);		// input range exception handling
		gradeArray[x] = grade;				// stores current value of grade in gradeArray.
	}
	
	numericSort(gradeArray);				// After all grades are entered, pass array to sorting function.
	printf("\n%s\n","Sorted grades:");
	
	for (x=0; x<SIZE;x++)
	{
		numericToLetter(gradeArray[x]);			// prints each element in the sorted array.
	}
	average = averageGrade(gradeArray);
	return 0;
}


void numericSort(int grade[])
{
	int pass;						// passes counter
	int hold;						// holds temporary value for sorting algorithm
	int i;
	for (pass = 1; pass<SIZE; pass++ )
	{
		for(i=0; i < SIZE-1; i++)
		{
			if(grade[i] > grade[i+1])
			{
				hold = grade[i];
				grade[i] = grade[i+1];
				grade[i+1] = hold;
			}
		}
	}
}

void numericToLetter(int numeric)
{
	if(numeric >= 90 && numeric <= 100)
	{
		printf("%d%s\n", numeric, " - A");
	}
	else if(numeric >=80 && numeric < 90)
	{
		printf("%d%s\n", numeric, " - B");
	}
	else if(numeric >=70 && numeric < 80)
	{
		printf("%d%s\n", numeric, " - C");
	}
	else if(numeric >=60 && numeric < 70)
	{
		printf("%d%s\n", numeric, " - D");
	}
	else {printf("%d%s\n", numeric, " - F");}
}

float averageGrade(int grade[])
{
	float accum =0;						// accumulates the total grade points
	int i;																
	int gradeAvg=0;														
	int numGrades = 6;													
	
	for (i=0; i<numGrades;i++)
	{
		accum = accum+grade[i];
	}
	gradeAvg = accum/numGrades;
	printf("\n%s%.2f%%","Average Grade: ",accum/numGrades);
	return gradeAvg;
}
