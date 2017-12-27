// Program uses a counter controlled for-loop to receive 10 integer values.  Defines an int value called 'largest'
// to be compared against each input value..  If the current input value is greater than the current largest value, it becomes
// the new value assigned to 'largest'.

#include <stdio.h>						// Include preproc. directive makes stdio functions available. 

// Begin main
int main(void)															
{
	unsigned int counter;					// counter for counter controlled for-loop.
	unsigned int number;					// unsigned int value used to temporarily hold the numbers for comparison.
	unsigned int largest =0;				// int largest is initialized to 0 and will be hold the largest value input by user.
	
	puts("\n");
	for (counter = 1; counter <=10; ++counter)		// for-loop iterates through 10 values, 1 - 10.  counter is incremented by 1 on each pass.
	{
		printf("%s%u: ", "Enter number ", counter);	// basic input section for user values.
		scanf("%u", &number);
		
		if (number > largest)				// tests whether current input value is larger than current largest value.
		{
			largest = number;			// if true, current input value is assigned to largest.
		}
	}

	printf("\n%s%u","The largest number is: ", largest);	// prints final result.
	return 0;	
}
