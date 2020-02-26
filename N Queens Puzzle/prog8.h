#ifndef PROG8_H //#ifndef checks whether the given token has been defined earlier in the file or in an included file.

#define PROG8_H //To define preprocessor macros.
 
#include<iostream> //Library that defines the standard input/output stream objects.

#include<vector> //Library to use Vectors

#include<stdlib.h> //Library to use random.  

#include<time.h> //Library to use Time function. 

using namespace std; //standard c++ library routine used for checking namespace.

// Function prototyping/

void initBoard();

void solveNQueens(const int);

bool solveNQueensUtil(vector < vector < bool > >&, int);

bool isSafe(vector < vector < bool > >&, int, int);

void printBoard(vector < vector < bool > >&);

#endif //Ends scope
