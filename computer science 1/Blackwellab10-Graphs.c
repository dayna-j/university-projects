// Uses a series of switches and function calls to print a collection of asterix graphs, whose lengths correspond to integers less than 50.

#include <stdio.h>

void asterixGraph(int numAsterix);						// function prototype for asterixGraph function.  returns nothing.  
																		// accepts integer as argument

int main(void)
{
	int x;									// control variable for for loop
	int graphOne;								// graphOne - graphFive variables hold the lengths of each respective asterix graph
	int graphTwo;
	int graphThree;
	int graphFour;
	int graphFive;

	puts("");
	for (x = 1; x < 6; x++)							// for-loop feeds values 1 - 5 into switch.  
	{
		printf("%s%i%s", "How long is chart ", x, " ? ");
		switch (x)							// switch takes numbers 1-5 as cases.  each case provides user input and 
										// input exception handling.
		{
			case 1:
			scanf("%i", &graphOne);
			while (graphOne > 50)					// while-loop ensures out-of-range values are rejected as valid input
			{
				printf("%s%i%s", "How long is chart ", x, " ? ");
				scanf("%i", &graphOne);
			}
			continue;

			case 2:
			scanf("%i", &graphTwo);
			while (graphTwo > 50)
			{
				printf("%s%i%s", "How long is chart ", x, " ? ");
				scanf("%i", &graphTwo);
			}
			continue;

			case 3:
			scanf("%i", &graphThree);
			while (graphThree > 50)
			{
				printf("%s%i%s", "How long is chart ", x, " ? ");
				scanf("%i", &graphThree);
			}
			continue;

			case 4:
			scanf("%i", &graphFour);
			while (graphFour > 50)
			{
				printf("%s%i%s", "How long is chart ", x, " ? ");
				scanf("%i", &graphFour);
			}
			continue;

			case 5:
			scanf("%i", &graphFive);
			while (graphFive > 50)
			{
				printf("%s%i%s", "How long is chart ", x, " ? ");					
				scanf("%i", &graphFive);
			}
			continue;
		}													

	}				

	puts("");

	for (x = 1; x < 6; x++)							// outer for-loop iterates nums 1-5.  
	{
		printf("%i%s",x,".  ");						// prints numbered list:  1.  , 2.  ,  3.  , etc!
				
		switch (x)							// for loop control variable is input to switch.  Each case corresponds
										// to one of 5 function calls to the 
		{								// asterixGraph function.  
			case 1:
			printf("%i|",graphOne);
			asterixGraph(graphOne);					// calls asterixGraph function with graphOne as an argument
			break;
					
			case 2:
			printf("%i|",graphTwo);
			asterixGraph(graphTwo);
			break;
					
			case 3:
			printf("%i|",graphThree);
			asterixGraph(graphThree);
			break;
				
			case 4:
			printf("%i|",graphFour);
			asterixGraph(graphFour);
			break;
					
			case 5:
			printf("%i|",graphFive);
			asterixGraph(graphFive);
			break;
			}
		puts("");
	}

}


void asterixGraph(int numAsterix)						// function definition of asterixGraph function
{
	int i;
	for (i = 1; i <= numAsterix; i++)					// for values of the control variable less-than-or-equal the length of each graph
	{
		printf("%s","*");						// prints a number of asterix equal to the each respective graph length
	}
}
