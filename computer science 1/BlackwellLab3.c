#include <stdio.h>														

int main(void)															
{
	int smallest, largest, firstInt,secondInt,thirdInt;					
	
	printf("Enter the first integer:\t");								
	scanf("%d", &firstInt);
	printf("Enter the second integer:\t");
	scanf("%d", &secondInt);
	printf("Enter the third integer:\t");
	scanf("%d", &thirdInt);

	smallest = firstInt;												
	largest = firstInt;
	
	if (secondInt < smallest)											
	{
			smallest = secondInt;	
	}
	
	if (thirdInt < smallest)											
	{
			smallest = thirdInt;
	}
	
	printf("%s", "\n");													
	printf("The smallest number is:\t%d",smallest);
	printf("%s", "\n");
	
	if (secondInt > largest)											
	{
		largest = secondInt;
	}
	
	if ( thirdInt > largest)											
	{
		largest = thirdInt;	
	}
	
	printf("The largest number is:\t%d",largest);						
	printf("%s", "\n");
	
	printf("The sum of the numbers is:\t%d",							
		  firstInt+secondInt+thirdInt);
	printf("%s", "\n");
	printf("The average of the numbers is:\t%d",
		  (firstInt+secondInt+thirdInt)/3);
	printf("%s", "\n");
	printf("The product of the numbers is:\t%d",
		  (firstInt*secondInt*thirdInt));
	
	return 0;
}
