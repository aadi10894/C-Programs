#ifndef PROG7_H // #ifndef checks whether the given token has been defined earlier in the file or in an included file.

#define PROG7_H // To define preprocessor macros.

#include <iostream> // Header that defines the standard input/output stream objects.

#include <string> // This header introduces string types, character traits and a set of converting functions.

#include <algorithm> // The header <algorithm> defines a collection of functions especially designed to be used on ranges of elements.

#include <stack> // To use stack we need to include this header

#include <cctype> // This header declares a set of functions to classify and transform individual characters.

#include <iomanip> // To use setw and setprecision functions this header file is to be included

using namespace std; // Standard c++ library routine used for checking namespace.

// Function prototyping

void process_token(string & str, stack < double > & S);

void printResult(const stack < double > & S);

void emptyStack(stack < double > & s);

bool isValidOperator(const char & );

double operation(const char & c,const double & x,const double & y);

double popStack(stack < double > & S);

bool floatPoint(const string & str, int i);

bool unarySign(const string & str,const int i);

string getNumber(string & str, stack < double > & S,const int i);

#endif //Ends scope
