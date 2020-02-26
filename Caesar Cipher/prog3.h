#ifndef PROG3_H

#define PROG3_H

#define FIRSTFILE "/home/cs501/progs/19f/p3/prog3.d1"    // Location of first file

#define SECONDFILE "/home/cs501/progs/19f/p3/prog3.d2"   // Location of Second file

#include<iostream>  // Library for input and output operations
 
#include<string> // Library for using string

#include<fstream> // Library for reading and writing operations in file

using namespace std; // Header file to include features of c++ standard library.

//function prototyping

int new_position(const char& c, const int& shift, const string& key);

string enocdeCaesarCipher(string str, const int& shift, const string& key);

void process_infile(const int& shift, const string& key);

//defining a const of alphabets which is used to get the character index also to get the value at index after shifting.

const string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

#endif

