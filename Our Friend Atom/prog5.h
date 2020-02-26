#ifndef PROG5_H

#define PROG5_H

#include <iostream> //Library for input output operations

#include <string>  //Library for using string in the program

#include <vector> //Library for making use of vector in our program

#include <cstdlib> //Library for making use of random number generator

#include <ctime>  //this header file contains definitions to get and manipulate date and time information.

using namespace std; //Header file to include features of standard c++ library.

const unsigned int GRID_SIZE = 625; //Defined grid size i.e displayed as row * coloumn

const int low = 1;	//Random interval for each ball ie minimum value

const int high = 4;   //Random interval for each ball ie maximum value

int noBallsInAir = 1;     //Defined for the first ball in the air

int simulationClock = 0;  //Defining simulation clock which is incremented for each cycle

int maxBallsInAir = 0;  //Defined max balls in the air

const int PRN_CYCLES = 10;	//PRN_CYCLES is used to print the output after every 10 cycles


//Function Prototyping


void print_stat(const vector< vector<bool> >&traps, const unsigned &maxNoBallsInAir, const unsigned &clock);

void print_grid(const vector< vector<bool> > &traps, const unsigned &clock, const unsigned &noBallsInAir);

unsigned release_balls(vector< vector<bool> >&traps, vector<unsigned> &ballCycles);

void init_sim(vector< vector<bool> >&traps, vector <unsigned> &ballCycles);

void update_cycles(vector<unsigned> &ballCycles);

#endif