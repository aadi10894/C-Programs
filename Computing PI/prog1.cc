#include "prog1.h" // Including header file prog1.h.


//The following function would take the input from user and it will perform the number of iterations specified by the user as per the formula specified by mathematician Leibniz and return the result//

double add_terms(int value)
{
	double m = 3; // We are assigning value 3 to m because we know that the first term after 1 we are going to subtract is 1/3
	double a = 1;
	int i = 1;
	bool flag = true; // Since we alternatively add and subtract according to formula, so it is simple if we can assign a flag value and reverse it for each run.

	//The following while loop runs the number of iterations specified by the user. I have ensured the if construct inside the while loop either subtracts the fraction or adds the fraction based on the flag value.// 

	while (i < value)
	{
		if(flag)
		{
			a = a - ( 1 / m);
			i++;
		}
		else
		{
			a = a + (1 / m);
			i++;
		}
		flag = !flag; //The reason I am using flag here is so we can reverse the value of flag and hence we are alternatively adding and subtracting the fractions, so that the Leibniz's formula is implemented.

		m = m + 2; // Reason why we are adding two is because we know that the next term we are subtracting or adding will increase by value 2.
	}
	return 4 * a; //I am multipliying it by 4 as we need to get the value of pi.
}

int main()
{
	int number = 0;
	double result = 0;
	cout<<"Please enter a number: "<<endl;
	cin>>number;
	
	//The following if construct is to validate if the user input is in the range or not.
	
	if(number > 0)
	{
		result = add_terms(number);
		cout<<"Final result is: \t "<<result<<endl;
	}
	else
	{
		cout<<"Invalid input"<<endl;
	}
	return 0;
}
