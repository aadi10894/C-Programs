#ifndef PROG4_H

#define PROG4_H

#define INFILE "/home/cs501/progs/19f/p4/prog4-in.cc"    //providing path to the input file which we will use to remove comments

#define OUTFILE "prog4-out.cc" //providing the output file name


#include <iostream> //library for input and output operations

#include <string>   //library for using strings in the program

#include <fstream>  //library for performing reading and writing operations on the file

using namespace std; //header file to include features of standard c++ library.


//Function prototyping

void close_files(ifstream& is, ofstream& os);

void process_data(ifstream& is, ofstream& os);

void open_files(ifstream& is, ofstream& os);

#endif
