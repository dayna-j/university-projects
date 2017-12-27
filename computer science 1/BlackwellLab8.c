// This program calculates how much a customer should be charged to board their dog at
// a dog boarding business.  It calculates the daily charge based on the weight of the dog,
// the number of days the dog will be boarded, and whether premium quality food has been chosen.
//
// There are two series of nested if-statements:  The outer if-statements sort input according 
// to days-per-month, and the inner if-statements sort by dog weight.  The rate per day to the
// customer will be determined based on which conditions are selected.
//
// After this, an additional rate is applied for cases where premium food has been selected.
// The rate for premium food is a function of the dog's weight and will increase the total
// rate per day by either 1 or 2 dollars per day.
//

#include <stdio.h>

int main(void)
{
	int dogWeight;								// integer variable holds the weight of the dog
	int daysPerMonth;							// integer variable holds the number of days per month the board will be boarded.
	int isPremium;								// isPremium is an integer variable that will act as a flag to indicate whether premium food is selected.
	double ratePerDay;							// floating point variable holds the daily rate to the customer.
	//double monthlyCharges;
	
	puts("");															// input/output section for initial values.
	printf("%s" , "How many pounds does your dog weigh?\t");
	scanf("%d", &dogWeight);
	printf("%s","How many days per month for boarding?\t");
	scanf("%d",&daysPerMonth);
	printf("%s" , "Premium food? (1 = yes or 2 = no)\t");
	scanf("%d", &isPremium);
	
	if (daysPerMonth <= 10)							// if-structure for stays of 10 days or less:
	{
		if (dogWeight < 10) {ratePerDay = 12;}				// if dog weight is less than 10lb, $12.00 per day.
		if (10 <= dogWeight < 35) {ratePerDay = 16;}			// if dog weight is greater than or equal 10lb AND less than 35lb, $16.00 per day.
		if (dogWeight >= 35) {ratePerDay = 19;}				// if dog weight is greater than or equal 35lb, $19.00 per day.
	}
	
	if (daysPerMonth >= 11)							// if-structure for stays of 11 days or more.
	{
		if (dogWeight < 10) {ratePerDay = 10;}				// if dog weight is less than 10lb, $10.00 per day.
		if (dogWeight >= 10 && dogWeight < 35) {ratePerDay = 13;}	// if dog weight is greater than or equal 10lb AND less than 35lb, $13.00 per day.
		if (dogWeight >= 35) {ratePerDay = 17;}				// if dog weight is greater than or equal 35lb, $17.00 per day.
	}
	
	if ( (isPremium == 1) && (dogWeight <= 20) ) {ratePerDay+=1;}		// add 1 dollar to the rate if premium food is chosen and dog is less than or equal 20lb
	if ( (isPremium == 1) && (dogWeight > 20) ) {ratePerDay+=2;}		// add 2 dollars to the rate if premium food is chosen and the dog is greater than 20lb.
	
	puts("");															// output section for final values
	printf("%s%d%s" , "To board a ",dogWeight," pound dog for ");
	
	printf("%d%s%s", daysPerMonth, " days",
		  ((isPremium == 1) ? " with premium food:" : ":"));		// uses a conditional statement within the printf argument to insert either "with premium
		  																// food:" or ":"
	
	puts("");
	printf("%s%.2lf","Rate per day:\t\t$",ratePerDay);
	puts("");
	printf("%s%.2lf","Monthly charges:\t$",ratePerDay*daysPerMonth);	// Total monthly charges are calculated by ratePerDay*daysPerMonth.
	puts("");
	
	return 0;
}





