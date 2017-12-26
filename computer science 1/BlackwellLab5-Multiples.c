// Program uses 2 counter-controlled for loops in order to print the first 5 multiples of each of the first 10 integers.
// Outer for-loop iterates by row.  Inner for-loop iterates by column.

#include <stdio.h>											// include preproc. directive makes contents of stdio available to this file.

int main(void)
{
	unsigned int rowCounter;								// row counter for counter controlled for-loop
	unsigned int colCounter;								// column counter for counter controlled for-loop
	
	puts("");
	printf("%s","Number\t1st\t2nd\t3rd\t4th\t5th");			// outputs header.
	puts("");
	
	for (rowCounter = 1; rowCounter <=10; ++rowCounter)		// for loop iterates through values 1 to 10, incrementing by 1 on each pass.
	{
		printf("%u",rowCounter);							// rowCounter is used to print each of the first 10 integer values.
	
		for (colCounter = 1; colCounter <=5; ++colCounter)	// for loop interates through the values 1 - 5.
		{
			printf("\t%u",rowCounter*colCounter);			// Each initial row value is multipled by the numbers 1 - 5 in turn, forming the first 5 multiples
		}													// and the columns of the output table.
		
		puts("");
	}
	return 0;
}
