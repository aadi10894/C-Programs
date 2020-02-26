/* Here in this program we are looking for perfect numbers in the range from 1 - 9999. Once a perfect number is found we are displaying its divisors along
   with it in the form of n = d1 + d2 + d3 .... dN, where n is the perfect number and d1 - dN are list of divisors.*/
   
   #include "prog2.h"
	string divisorsList; //I am declaring this variable so that we can store the list of divisors as strings.
	unsigned int overall; //The variable "overall" is stores the sum all of the divisors and check with the number passed to see whether they match or not.



    //The following function is used to generate a list of divisors
	void divisors(const unsigned int divisor)
	{
		divisorsList.append(" + " + to_string(divisor)); //Here we are appending the divisor to the string
	}

	// The following function takes the input number one after another and returns true if the number passed is a perfect number or false otherwise.
	
	bool isPerfect(const unsigned int number)
	{
		divisorsList = "";
		overall = 0;
		for(unsigned int i = 1; i < number; i++){
			if((number % i) == 0){
				divisors(i);
				total += i;
			}
		}

		return (number == total) ? true : false; //returns true if the number passed is a perfect number else it returns false
	}		


	int main()
	{
		bool result; //variable to store the result of isPerfect function.
		
		/*This loop iterates from 1 - finalValue (defined a constant in the header file{In this case it is 9999}). Everytime it passes the value of i to the isPerfect function
		and gets the result i.e. true or false and displays its divisors if the number is a perfect Number*/
		for(unsigned int i = 1; i <= finalValue; i++){ 
			result = isPerfect(i);
			if(result){
				cout<<i<<" = "<<divisorsList.erase(0,2)<<endl; //here we are printing the list of divisors from the variable divisorsList.
			}
		}
	}
