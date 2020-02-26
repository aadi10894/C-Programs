/* Here in this program we are representing chain reactions in nuclear fission with a help of an experiment in large cubical box covered with mouse traps. 
   At the beginning of the simulation, an additional ping pong is released from top of the box which falls on the mousetrap. That mouse trap springs and 
   shoots its two ping pong balls and eventually they are likely to set off more mousetraps untill the time there are no balls in the air.*/


#include "prog5.h" 


//The following function prints the Total simulation time, max no of balls in air and percentage of sprung straps in the end.


void print_stat(const vector< vector<bool> >&traps, const unsigned &maxNoBallsInAir, const unsigned &clock)
{
	double totalStrapsSprung = 0;
	double percentage;
	cout<<endl;
	cout<<"Total simulation time = "<<clock<<endl;
	cout<<"Max no of balls in air = "<<maxNoBallsInAir<<endl;
	for(unsigned int p = 0; p < traps.size(); p++)
	{
		for(unsigned int q = 0; q < traps[p].size(); q++)
		{
			if(traps[p][q] == false)
			{
				totalStrapsSprung += 1;
			}
		}
	}
	percentage = (((totalStrapsSprung) / (GRID_SIZE * GRID_SIZE)) * 100);
	cout<<"Percent of sprung traps = "<<percentage<<endl;
}


// The following function is used to print the grid after every 10 cycles. It is also called at the beginning and ending of the simulation.
// Thus it represents boolean values  ie. true by 'X' and false by '.'  


void print_grid(const vector< vector<bool> > &traps, const unsigned &clock, const unsigned &noBallsInAir)
{
	cout<<endl;
	cout<<"clock = "<<clock<<" : "<<"noBallsInAir =  "<<noBallsInAir<<endl<<endl;
	for(unsigned int p = 0; p < traps.size(); p++)
	{
		for(unsigned int q = 0; q < traps[p].size(); q++)
		{
			if(traps[p][q] == true)
			{
				cout<<"X ";
			}
			else
			{
				cout<<". ";
			}
		}
		cout<<endl;
	}
}


// The following routine is called to update vector ballCycles for a ball. 
/* It searches for the first value 0 in the vector and when it finds , it removes that element from the vector and replaces it with simulation 
   cycle values and thus gets out of the loop. */

 
void update_cycles(vector<unsigned> &ballCycles)
{
	for(unsigned int i = 0; i < ballCycles.size(); i++)
	{
		if(ballCycles[i] == 0)
		{
			ballCycles.erase(ballCycles.begin() + i, ballCycles.begin() + i + 1);
			ballCycles.insert(ballCycles.begin() + i, (rand() % (high - low + 1) + low));
			ballCycles.insert(ballCycles.begin() + i + 1, (rand() % (high - low + 1) + low));
			break;
		}
	}
}


// The following routine checks for every value in the vector ballCycles. 

/* If the value is not 0 then it decrements the value and if the value is 0, it computes random number to choose random mouse trap and checks 
   if the mousetrap is sprung or not. */ 

/* If it is not sprung then it calls update_cycles routine and sets the chosen mouse trap to boolean value false and if it is sprung then it 
   removes the element 0 from the vector. */


unsigned release_balls(vector< vector<bool> >&traps, vector<unsigned> &ballCycles)
{
	unsigned int row, col;


	//loop for subtracting the cycle by 1 if value is not 0

	
	for(unsigned int i = 0; i < ballCycles.size(); i++)
	{
		if(ballCycles[i] > 0)
		{
			ballCycles[i] -= 1;
		}
	}
	simulationClock += 1; //incrementing the simulation cycle


	//checking the value for 0, if value is 0 it calls update_cycles routine and if not 0 then it removes the element from the vector.

	
	for(unsigned int j = 0; j < ballCycles.size(); j++)
	{
		if(ballCycles[j] == 0)
		{
			row = (rand() % GRID_SIZE);
			col = (rand() % GRID_SIZE);
			if(traps[row][col] == true)
			{
				update_cycles(ballCycles);
				traps[row][col] = false;
			}
			else
			{
				ballCycles.erase(ballCycles.begin() + j, ballCycles.begin() + j + 1);
			}
		}
	}	
	return ballCycles.size();  //returning the total number of balls in the air
}


//This routing sets the srand function to time(0) and also inserts boolean value true into a multidimensional vector of GRID size 25. 
//It also displays the grid for the clock 0 and  inserts the value 1 into the vector ballCycles as the simulation cycle for the first ball.

 
void init_sim(vector< vector<bool> >&traps, vector <unsigned> &ballCycles)
{
	srand(time(0)); //defining srand for time(0)


	//inserting boolean value true in multidimmensional vector


	for(unsigned int i = 0; i < GRID_SIZE; i++)
	{
		vector<bool> temp;
		for(unsigned int u = 0; u < GRID_SIZE; u++)
		{
			temp.push_back(true);
		}
		traps.push_back(temp);
	}
	ballCycles.push_back(1); //inserting the cycle 1 for the first ball in vector ballCycles.
}


/*The main function basically initilizes two vectors ie. one called traps which is a multidimmensional vector of size 25 and the other ballCycles for
  storing all the simulation cycles. This function also calls the print_stat function at the last */
  
  
int main()
{
	vector< vector<bool> >traps;  //defining multidimmensional vector
	vector<unsigned> ballCycles;  //defining vector for storing simulation cycles
	init_sim(traps, ballCycles);  
	print_grid(traps, simulationClock, 0);


	//this calls release_balls for each simulation and we also called the print_grid routine inside this loop


	while(ballCycles.size())
	{
		noBallsInAir = release_balls(traps, ballCycles);
		(noBallsInAir > maxBallsInAir) ? maxBallsInAir = noBallsInAir : maxBallsInAir = maxBallsInAir;
		if((simulationClock % PRN_CYCLES) == 0 || noBallsInAir == 0)
		{
			print_grid(traps, simulationClock, noBallsInAir);
		}
	}
	print_stat(traps, maxBallsInAir, simulationClock); //calls the print_stat for printing simulation clock, max no of balls in air and percentage of straps sprung
}
