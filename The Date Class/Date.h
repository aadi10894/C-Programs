#ifndef DATE_H

#define DATE_H 

#include <iostream> 	// Library for input output operations

#include <string>   	// Library for using string in program

#include <fstream>  	// Library for making use of istream and ostream operations

#include <vector>    	// Library for making use of vector in our program

using namespace std; 	// Header file to include features of standard c++ library

const string MONTH = "January"; 	// Defining default month value

const int DAY = 1;			// Defining default day value

const int YEAR = 2000;			// Defining default year value


// Vector of months to check of the month of a Date object is valid or not


const vector<string> months{"January","February","March","April","May","June","July","August","September","October","November","December"};

string intToString(const int& n); 	//Function prototyping


// Declaring date class and its member function protototyping


class Date
{
	private:
		string month;
		int day;
		int year;
		bool isValidMonth() const; 	// To check whether a month is valid
		int daysInMonth(const string& m) const; 	// To get the number of days in a month
		bool isLeapYear() const; 	// For checking that a year is a leap year
	
	public:
		Date(const string& m = MONTH, const int& d = DAY, const int& y = YEAR); 	// Class constructor
		void setMonth( const string& m); 	// Setting the month of date object
		void setDay( const int& d);		// Setting the day of the date object
		void setYear( const int& y);		// Setting the year of the date object
		string getMonth() const;		// We are using get() for getting the month of date object
		int getDay() const;			// We are using get() for getting the day if the date object
		int getYear() const;			// We are using get() for getting the year of the date object
		void Month();			  // Convert month of by changing first letter to uppercase and the rest to lowercase 
		bool isValidDate() const;		// Check whether the date is valid
		string toString() const;		// Convert date to the format of dd-mm-yyyy
		friend istream& operator >> (istream& is, Date& d);	// Operator overloading function to overload the operator >>
		friend ostream& operator << (ostream& os, const Date& d);// Operator overloading function to overload the operator <<
};



#endif
