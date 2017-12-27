//
//
// This program calculates the total amount that a rental car company should charge its customers.  
// The user will enter the number of days the car will be rented, and how many miles the car will be driven.
//  
// A fixed rate of $15.00 is charged to all customers.  The rate for the miles driven is variable, depending on whether
// the car was driven for less than 200 miles, effectively giving a slight discount on rentals greater than 200 miles.
//
//  A simple if-else structure determines which rate should be applied.
//
// The total cost to the customer is broken down into 3 components:  tax, some multiple of the daily rate and a charge based on the number of miles driven.
// 
//

#include <stdio.h>

int main(void)
{
	int days = 0;							// integer value.  Number of days for rental.
	double milesDriven = 0;						// floating point value holds the miles driven for the rental.
	double salesTax = 0.06;						// floating point value holds the current sales tax percentage in decimal form.
	double dailyRate = 15.00;					// floating point value holds the fixed daily rate.
	double dailyTotal = 0;						// floating point value holds the product (days*dailyRate).
	double milesCharge = 0;						// floating point value holds the cost component based on miles driven.
	double taxCharge = 0;						// floating point value holds the sales tax assessed.
	double subTotal = 0;						// floating point value holds the sum (dailyTotal + milesCharge)
	double totalCost = 0;						// floating point value holds the final cost to the customer, which is the sum (subTotal+taxCharge)
	
									// input/output for user values
	puts("");
	printf("%s", "Enter the number of days the car was rented:\t");
	scanf("%d", &days);
	printf("%s", "Enter the number of miles the car was driven:\t");
	scanf("%lf", &milesDriven);
	puts("");
	
	dailyTotal = days*dailyRate;					// This line satisfies the requirement that "the amount charged per 
									// day for renting a car should only appear in one calculation."
	if ( milesDriven < 200)						// if else structure multiples milesDriven by .4 for rentals less than 200mi, .35 if greater than or equal 200.
	{
		milesCharge = 0.40*milesDriven;
	}
	else
	{
		milesCharge = 0.35*milesDriven;
	}
	
	subTotal = dailyTotal + milesCharge;				// Values to be used in final program output:  subTotal holds the sum of fixed daily charges and 
									// variable miles charge.
	
	taxCharge = salesTax*(dailyTotal + milesCharge);		// holds the sales tax assessed to the customer
	totalCost = (subTotal + taxCharge);				// holds the total cost to the customer.  Consists of the sum of subTotal and taxCharge
	
	printf("%s%.2lf","Subtotal:\t\t\t\t\t$",subTotal);		// output section for final values
	puts("");
	printf("%s%.2lf","Tax Amount:\t\t\t\t\t$",taxCharge );
	puts("");
	printf("%s%.2lf","Total:\t\t\t\t\t\t$",totalCost);
	puts("");
	
	return 0;
}
