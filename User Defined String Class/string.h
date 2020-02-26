/* Headerfile for prog9.cc file */
//#ifndef checks whether the given token has been defined earlier in the file or in an included file.
#ifndef PROG9_H

//To define preprocessor macros.
#define PROG9_H

//Header that defines the standard input/output stream objects.
#include<iostream>

//Header to use Vectors
#include<vector>

//Header to use random. 
#include<stdlib.h> 

//Header to use Time function.
#include<time.h> 

//standard c++ library routine used for checking namespace.
using namespace std;
/*Below are Function prototypes*/
void initBoard();
void solveNQueens(const int);
bool solveNQueensUtil(vector < vector < bool > >&, int);
bool isSafe(vector < vector < bool > >&, int, int);
void printBoard(vector < vector < bool > >&);

#endif //Ends scope
