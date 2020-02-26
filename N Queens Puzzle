#include "prog8.h"  // User defined header which contains function prototypes and headers


/* Initialises srand with time 0. */


void initBoard()
{
    srand(time(0));//random number generator is intialised
}


/*  This function first initiates the board with value false and then checks wheather the solution exists or not. */


void solveNQueens(const int N)
{
    vector< vector < bool > > board(N, vector < bool >(N, false)); // Vector of vector of return type bool with size N
    initBoard(); // Function call to initBoard.
    cout << "Board Size = " << N << endl; // Displays the Size of Board.

    bool queen = solveNQueensUtil(board, 0); // Function call to solveNQueensUtil.
    if (queen == true) // If true printBoard function is called.
    {
        printBoard(board); // PrintBoard function
    }
    else
	{
        cout << "There is no Solution." << endl<<endl;; 
	}
}


/* This function places the queens in correct position if at all they exist. */


bool solveNQueensUtil(vector < vector < bool > >&board, int row)
{
    int size = board.size();
    if (row == 0) // When the first row(Base condition for recursion.)
    {
        unsigned int col = rand() % board.size(); 
        if ((board.size() == 4 || board.size() == 6 || board.size() == 8) && (col == 0 ) )
            col++;
        if ((board.size() == 4 || board.size() == 6|| board.size() == 8) && (col == board.size() - 1))
            col--;
        if (isSafe(board, 0, col))
            board[0][col] = 1;
        row++;
    }
    if (row >= size) // When current row is greater or equal than the size.
        return true;
    for (unsigned int col = 0; col < board.size(); col++)
    {
        if (isSafe(board, row, col)) // To check whether the postion is safe or not.
        {
            board[row][col] = 1; // Current position assigned to 1.
            if (solveNQueensUtil(board, row + 1)) // Calling recursively.
            {
                return true;
            }
            else
                board[row][col] = 0; // If false postion set to zero.

        }
    }
    return false;
}
/*  This function checks if the queen can be placed in that particular place or not. */

bool isSafe(vector < vector < bool > >&board, int row, int col)
{
    int size = board.size();
    int i, j; 

    for (i = 0; i < size; ++i) // Row check to see if there is any queen.

    {
        if (board[row][i] != 0)
		{
            return false;
		}
    }   

    for (i = 0; i < size; ++i) //Column check to see if there is any queen.
    {
        if (board[i][col] != 0)
        {
			return false;
		}
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) //Checking upper diagonal left.
    {
        if (board[i][j] != 0)
		{
            return false;
		}
	}
    for (i = row, j = col; i >= 0 && j < size; i--, j++) //Checking upper diagonal right.
    {
        if (board[i][j] != 0)
		{
			return false;
		}
    }
    for (i = row, j = col; i < size && j < size; i++, j++) //Checking lower diagonal right.
    {
        if (board[i][j] != 0)
		{ 
           return false;
		} 
	}
    for (i = row, j = col; j >= 0 && i < size; i++, j--) //Checking lower diagonal left.
    {
        if (board[i][j] != 0)
		{
			return false;
		}
	}
    return true;
}


/* This function prints the 2D vector. */


void printBoard(vector < vector < bool > >&board)
{
    char line = '-';
    for (unsigned int row = 0; row < (board.size()); ++row)
    {
        cout << " ";
        for (unsigned int i = 0; i < (4 * board.size() - 2); ++i)
		{
            cout << line;
        }
		cout << line << endl;
        for (unsigned int i = 0; i < board.size(); ++i)
        {
			cout << "|   ";
        }
		cout << "|   "<<endl;
        for (unsigned int col = 0; col < board.size(); ++col)
        {

            if (board[row][col] == 1)
            {
                cout << "| "<<"Q " ; // Q is placed for queens position.
            }
            else
			{
                cout << "|  " <<" "; // " " if queen cannot be placed in that position.
			}
		}
        cout <<"|  "<< endl;
        for (unsigned int j = 0; j < board.size(); j++)
        {
            cout << "|   ";
        }
        cout << "|   " << endl;
    }
    cout << " ";
    for (unsigned int i = 0; i < (4 * board.size() - 2); i++)
	{
        cout << line;
    }
	cout << line << endl;
}

int main()
{
    int N;
    for(N = 1;N <= 8;N++) // Looping for N=1 to 8 cases.
    {
        solveNQueens(N); // Function call to solveNQueens.
    }

    return 0;
}
