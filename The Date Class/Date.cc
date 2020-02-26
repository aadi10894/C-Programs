	 

		 /*******************************************************************************
	 	 * 																				*
		 *																				*
	 	 *          Aadithya Gopalakrishna Bharadwaj, Z1862641, Assignment - 6			*
	 	 *																				*
	 	 *          CSCI - 501, Fall 2019, The Date Class								*
	 	 *									        									*
	 	 *									        									*
	 	 *******************************************************************************/


/* In this program we are going to implement the date class, we are going to ensure that we have functions which determine the number    of days based on the month provided by the user input. The driver program for this is named "prog6.cc" and it is present in the 
   location < /home/turing/cs501/progs/19f/p6 >. */


/* There is a main() routine that tests the member function of the Date class with several dates. Some of these dates are generated by   the class constructors and some of them are entered from stdin. We print out the date in form of dd-mmm-yyyy, using the return        value of printdate(). The implementation of printdate() is included in driver program "prog6.cc" */


/* For this program we are not linking any file, we are compiling the code using the following code:
 			Make N=6
   We execute the code using the following command
   			Make execute N=6
*/


#include "Date.h" // Including the header file in our file


// Class constructor to set month, day and year to values passed and if not passed set to default values.


Date::Date(const string& m, const int& d, const int& y)
{
	month = m;	
	day = d;
	year = y;
	Month();	
}


// Function to set the month in the date object


void Date::setMonth(const string& m)
{
	month = m;
	Month();	
}

// Function to set the day in the date object


void Date::setDay(const int& d)
{
	day = d;
}


// Function to set the year in the date object


void Date::setYear(const int& y)
{
	year = y;
}


// Function to return the month in the date object


string Date::getMonth() const
{
	return month;	
}


// Function to return the day in the date object


int Date::getDay() const
{
	return day;	
}


// Function to return the year in the date object


int Date::getYear() const
{
	return year;	
}


// Function to convert the first letter of the month in the date object to uppercase and the rest to lower case.


void Date::Month()
{
	for(unsigned int j = 0; j < month.length(); j++)
	{
		if(j == 0)
		{
			month[j] = toupper(month[j]);
		}
		else
		{
			month[j] = tolower(month[j]);
		}
	}	
}


/* Function to check a date is valid or not by checking each component indivisually. i.e. for month (isValidMonth()) to determine that   it is a valid month, year (by checking that it is greater than 1 and days by checking the day component has a valid value between     the month range */


bool Date::isValidDate() const
{
	bool isValidDateResult;
	int noOfDays = daysInMonth(month);
	
	//checking if the year is valid
	
	if(year >= 1 && isValidMonth() && (day >= 1 && day <= noOfDays))
	{
		isValidDateResult = true;
	}
	else
	{
		isValidDateResult = false;
	}
	return isValidDateResult;
}



// Function to check whether a month is valid by checking the month in the vector of months


bool Date::isValidMonth() const
{
	bool flag = false;
	for(unsigned int i = 0; i < months.size(); i++)
	{
		if(months[i] == month)
		{
			flag = true;
			break;
		}
	}
	return flag;
}


// Function to get the number of months in the month component of date object 


int Date::daysInMonth(const string& m) const
{
	bool isLeapYearResult;
	int noOfDaysInMonth;

	// In the following steps we check if it is leap year or not and how many days are there in the month
	
	if(m == "February")
	{
		isLeapYearResult = isLeapYear(); // Calling isLeapYear function to get correct number of days in february month
		(isLeapYearResult) ? noOfDaysInMonth = 29 : noOfDaysInMonth = 28; 	
	}
	else if(m == "September" || m == "April" || m == "June" || m == "November")
	{
		noOfDaysInMonth = 30;
	}
	else
	{
		noOfDaysInMonth = 31;
	}
	return noOfDaysInMonth;
}


// Function to check whether the year is a leap year

bool Date::isLeapYear() const
{
	bool isLeapYearResult;
	if((year % 4) == 0)
	{
		if((year % 100) == 0)
		{
			if((year % 400) == 0)
			{
				isLeapYearResult = true;
			}
			else
			{
				isLeapYearResult = false;
			}
		}
		else
		{
			isLeapYearResult = true;
		}
	}
	else
	{
		isLeapYearResult = false;	
	}
	return isLeapYearResult;
}


// Function to convert the month component of the date object to the format dd-mm-yyyy


string Date::toString() const
{
	return intToString(day) + "-" + month.substr(0,3) + "-" + intToString(year);	
}

// Funtion to convert the integer to string and return the string value

string intToString(const int& n)
{
	return to_string(n);
}


/*This function overloads tbe extraction operator >>. It reads the individual date components from stream is to the date object d,      where date can be entered in the form month day year or month day, year. Once it reads the value from istream it assigns to the 
  Date objet components. */


istream& operator >> (istream& is, Date& d)
{
	string line;
	string Mon;
	string DayAndYear;

	// Getting the value from the is stream
	
	getline(is, line);
	for(unsigned int i = 0; i < line.length(); i++)
	{
		if(isalpha(line[i]))
		{
			Mon += line[i];
		}
		else if(isdigit(line[i]))
		{
			DayAndYear += line[i];	
		}
	}
	d.month = Mon; // Setting the month component of date object to month from the is stream.
	try
	{
		d.day = stoi(DayAndYear.substr(0,2)); // Setting the day component of date object to day from the is stream.
		d.year = stoi(DayAndYear.substr(2, DayAndYear.length())); // Setting the year component of date object to year from the is stream.
	}
	catch(const invalid_argument& a){}
	return is;
}


/* This function overloads the insertion operator <<. It gets the individual components from the date object and to the stream os in     the form month day, year */


ostream& operator << (ostream& os, const Date& d)
{
	string dateValue;
	dateValue = d.month + " " + to_string(d.day) + ", " + to_string(d.year);
	os<<dateValue;
	return os;		
}
