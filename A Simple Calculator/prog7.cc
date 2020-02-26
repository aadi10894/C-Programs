// Here including the header file for making use of the contants and function declarations.

		 
#include"prog7.h" 


/* Here process_token checks each token charachter by charachter and takes necessary actions based on the charachter value. */


void process_token(string & str, stack < double > & S)
{
	int string_length = str.length(); // Str_len stores the length of the string
	for (int i = 0; i < string_length; i++) // String is parsed
	{
		if (isdigit(str[i])) // To check if string charcter contains digit or not if true following is executed.
		{
			string str2;
			str2 = getNumber(str, S, i); // Function call to getNumber function.
			if (str == str2) // Checking if the strings are same.
			{
				i = string_length;
			}	
			else
			{
				str = str2;
			}	
		string_length = str.length(); // Value of str_len is changed.
		i = -1;
		} 
		else if (isValidOperator(str[i])) // To check if the character is valid operator or not.
		{
			if (!unarySign(str, i)) // To check if operator is unary or not. 
			{
				double d = operation(str[i], popStack(S), popStack(S)); // If the operator is binary rest is executed.
				S.push(d); // The value is pushed into stack.
			} 
			else // If the operator is unary rest is executed.
			{
				string str4;
				str4 = getNumber(str, S, i); // Function call to getNumber.
				if (str == str4) // If the returned string is same or not.
				{
				i = string_length;
				}
				else
				{	
					str = str4; // If both are not same.str is set to str4
				}
				string_length = str.length(); // str_len is assigned with length of the new string.
				i = -1;
      			}
    		} 
		else if (floatPoint(str, i)) //If the character of string is a valid floatpoint rest statements are executed. 
    		{
      			string str2;
      			str2 = getNumber(str, S, i); //Function call to getNumber.
      			if (str == str2) // If the returned string is same as the string passed.
	  		{
				i = string_length;
	 		}	
      			else
	  		{  
        			str = str2;
      		}
	  		string_length = str.length(); // str_len is set with the length of the string returned by getNumber
      			i = -1;
    		} 
		else if (str[i] == '=') // If the character encountered here is = then printResult is called.
    		{
      			printResult(S);
    		} 
		else if (str[i] == 'c') // If the character is c then rest statements are executed.
    		{
      			emptyStack(S); // Function call
      			str = str.substr(i + 1, str.length()); // To remove character  c from it.
      			string_length = str.length();
      			i = -1;
    		} 
		else // If any other character is found.
    		{
      			cerr << "Error: character " << "'" << str[i] << "' is invalid" << endl; /* Error message is displayed on the                                                                                                     console */      					    break;
    		}
  	}

}


/* Checks if stack S is empty, and if it’s, it prints out an error message on stderr to indicate the error. Otherwise, it prints out
   the top number in S on stdout by exactly two digits after the decimal point. */
   
   
void printResult(const stack < double > & S) 
{
	if (S.size() == 0) //If stack is empty
  	{
    		cerr << "Error: stack is empty as stack size is zero \n" << endl; // Error message is displayed
  	} 
  	else 
  	{
    		cout << setw(12) << fixed << setprecision(2) << S.top() << endl; //The top element of stack is printed.
  	}
}


/* This function is used to remove all the elements from the stack and empty it. Pops the top element from stack S and continue 
   by popping the top element until S becomes empty. */


void emptyStack(stack < double > & S) 
{
	if (S.size() == 0) // If stack is empty.
  	{
    		cerr << "Error: Stack  empty" << endl; // Displays the error message on the console
  	}	 
  	else
	{
    		while (!S.empty()) // If the stack isn't empty then it clears the content in the stack
  		{
    			S.pop();
  		}
	}	
}


/* This function is used to check of the operator is an valid operator. Checks if the character c is one of the four valid
   operators in { +, -, *, / }. */
   

bool isValidOperator(const char & c) 
{
  	if (c == '+' || c == '-' || c == '*' || c == '/') // Checks if the argument is valid operator or not
  	{
    		return true;
  	}
  	else
  	{
    		return false;
  	}
}


/*  Applies the operator c on the numbers x and y and returns the resulting number to the calling routine */


double operation(const char & c, const double & x, const double & y) 
{
	  double temp;
 	  if (c == '+') // If operator is +
  	  {
		temp = x + y;
  	  }
	  else if (c == '-') // If operator is -
  	  { 
   		temp = x - y;
   	  }
	  else if (c == '*') // If operator is *
  	  {
		temp = x * y;
  	  }
	  else if (c == '/') // If operator is /
  	  {
		temp = x / y;
  	  }
	  else
	  {
		  cerr <<"\n Error: Wrong input"<<endl;
	  }
  	  return temp;
}


/* Checks if stack S is empty, and if it’s, it prints out an error message on stderr to indicate the error. 
   Otherwise, it removes and returns the number at the top of S to the calling routine */


double popStack(stack < double > & S) 
{
 	if (S.empty()) // If stack is empty
  	{
    		cerr << "Error: Stack is empty for pop operation" << endl; // Error message is displayed on the console
	} 
  	else if (!S.empty()) // If stack is not empty
  	{
    		double temp = S.top(); /* Stores the top of the stack element in a temp variable and deltes it from the stack and then                                                                            returns the value in the temp variable */
    		S.pop();
    		return temp;
  	}
  	return 0.00;
}


/* Checks if the character c in position i in token is a valid decimal point, which is considered valid if it’s not the last 
   character in token and the character follows it is a digit. */


bool floatPoint(const string & str, int i) 
{
	int string_length = str.length();
  	if (str[i] == '.' && isdigit(str[i + 1]) && (i != string_length - 1))
  	{
    		return true;
  	}
  	else
  	{
    		return false;
  	}
}


/* Checks if the character c in position i in token is a valid unary –/+ sign, which is considered valid if it’s not the last 
   character in the token and the character follows it is either a digit or a decimal point. */


bool unarySign(const string & str, const int i) 
{
	int string_length = str.length();
  	if ((i != string_length - 1) && ((isdigit(str[i + 1])) || str[i + 1] == '.'))
  	{ 
		return true;
  	}  
  	return false;
}


/* This function takes the argument which is valid floating point number only and using strtod it converts string to a double. */

double getNumber(const char &c, string & str, stack < double > & S, const int i) 
{
 	int a = 0;
  	int string_length = str.length();
  	char *k;
  	for (int b = i; b < string_length && ((isdigit(str[b])) || str[b] == '.'); b++) // Checks if there are more than one decimal points                                                                                                                        in the string */
  	{
    		if (str[b] == '.')
      		a++;
  	}
  	if (a > 1) //To check if there are more than one decimal points
  	{
			cerr << "Error: number '" << str << "' is invalid" << endl;
			return "";
  	} 
  	else 
  	{
    		double d = strtod(str.c_str(), & k); // String is converted into double and the concatinated string is stored in k                                                                                              which is a c style string */
    		S.push(d); // Converted to c++ style string and pushed to stack.
    	    string str1 = k;
    		return str1;
  	}
}

int main() 
{
	string str; // String declaration
  	stack < double > S; // Stack declaration
  	while (cin >> str) 
  	{
    		process_token(str, S); // Function call 
  	}
  	return 0;
}
