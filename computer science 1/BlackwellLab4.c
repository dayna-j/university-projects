#include <stdio.h>							// include preprocessor directive makes stdio functions available

int main(void)								// function header for main function
{	
	int totalEarned,earnedLab,earnedQuiz,earnedTest;		// integer variables needed for final calculations 
	
	double finalGrade;						// double finalGrade holds final grade calculation
	double totalPoints = 720;					// double totalPoints used in final grade calculation
	
	int lab1,lab2,lab3,lab4,lab5,lab6,				// 12 integers to hold lab scores
		lab7,lab8,lab9,lab10,lab11,lab12;
	
	int quiz1,quiz2,quiz3,quiz4,quiz5,				// 10 integers to hold quiz scores
		quiz6,quiz7,quiz8,quiz9,quiz10;
	
	int test1,test2,test3,test4;					// 4 integers to hold test scores
	
	printf("%s","Enter the score for Assignment 1: \t");		// input/output section for labs
	scanf("%d",&lab1);
	printf("Enter the score for Assignment 2: \t");
	scanf("%d",&lab2);
	printf("Enter the score for Assignment 3: \t");
	scanf("%d",&lab3);
	printf("Enter the score for Assignment 4: \t");
	scanf("%d",&lab4);
	printf("Enter the score for Assignment 5: \t");
	scanf("%d",&lab5);
	printf("Enter the score for Assignment 6: \t");
	scanf("%d",&lab6);
	printf("Enter the score for Assignment 7: \t");
	scanf("%d",&lab7);
	printf("Enter the score for Assignment 8: \t");
	scanf("%d",&lab8);
	printf("Enter the score for Assignment 9: \t");
	scanf("%d",&lab9);
	printf("Enter the score for Assignment 10: \t");
	scanf("%d",&lab10);
	printf("Enter the score for Assignment 11: \t");
	scanf("%d",&lab11);
	printf("Enter the score for Assignment 12: \t");
	scanf("%d",&lab12);

	earnedLab = lab1+lab2+lab3+lab4+lab5				// tally all lab scores
				+lab6+lab7+lab8+lab9+lab10
				+lab11+lab12;

	printf("Enter the score for Quiz 1: \t\t");			// input/output for quiz scores
	scanf("%d",&quiz1);
	printf("Enter the score for Quiz 2: \t\t");
	scanf("%d",&quiz2);
	printf("Enter the score for Quiz 3: \t\t");
	scanf("%d",&quiz3);
	printf("Enter the score for Quiz 4: \t\t");
	scanf("%d",&quiz4);
	printf("Enter the score for Quiz 5: \t\t");
	scanf("%d",&quiz5);
	printf("Enter the score for Quiz 6: \t\t");
	scanf("%d",&quiz6);
	printf("Enter the score for Quiz 7: \t\t");
	scanf("%d",&quiz7);
	printf("Enter the score for Quiz 8: \t\t");
	scanf("%d",&quiz8);
	printf("Enter the score for Quiz 9: \t\t");
	scanf("%d",&quiz9);
	printf("Enter the score for Quiz 10: \t\t");
	scanf("%d",&quiz10);

	earnedQuiz = quiz1+quiz2+quiz3+quiz4+quiz5			// tally all quiz scores
				+quiz6+quiz7+quiz8+quiz9+quiz10;

	printf("Enter the score for Test 1: \t\t");			// input/output for tests
	scanf("%d",&test1);
	printf("Enter the score for Test 2: \t\t");
	scanf("%d",&test2);
	printf("Enter the score for Test 3: \t\t");
	scanf("%d",&test3);
	printf("Enter the score for Test 4: \t\t");
	scanf("%d",&test4);
	
	earnedTest = test1+test2+test3+test4;				// tally all test scores
	
	totalEarned = earnedLab+earnedQuiz+earnedTest;			// sum all earned points
	finalGrade = (double)totalEarned / totalPoints;			// final calculation.  divide total earned points by total possible points

	puts("");	
	printf("%s%.2f%%","The overall course grade is: ",finalGrade*100);	// output for final result

	
	return 0;
}

