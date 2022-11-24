// /*
//  * Problem Statement :- Design n-Queens matrix having first Queen placed. Use backtracking
//  * 						to place remaining Queens to generate the final n-queen's matrix.
//  *
//  * Time Complexity  : O(n!)
//  * Space Complexity : O(n)
//  */

// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> grid;
// vector<bool> col;
// vector<bool> lrdiag;
// vector<bool> rldiag;
// int cnt = 0;

// void display()
// {
// 	for (auto itr : grid)
// 	{
// 		cout << "\t ";
// 		for (auto x : itr)
// 		{
// 			if (x)
// 			{
// 				cout << "Q ";
// 			}
// 			else
// 			{
// 				cout << "_ ";
// 			}
// 		}
// 		cout << endl;
// 	}
// 	cout << endl;
// }

// bool is_safe(int r, int c, int n)
// {
// 	if (lrdiag[r - c + n - 1] || rldiag[r + c] || col[c])
// 		return false;
// 	return true;
// }

// void n_queen(int row, int n)
// {
// 	if (row >= n)
// 	{
// 		display();
// 		cnt++;
// 		//		exit(0);
// 		return;
// 	}

// 	for (int c = 0; c < n; c++)
// 	{
// 		if (is_safe(row, c, n))
// 		{
// 			grid[row][c] = 1;
// 			col[c] = true;
// 			lrdiag[row - c + n - 1] = true;
// 			rldiag[row + c] = true;

// 			n_queen(row + 1, n);

// 			grid[row][c] = 0;
// 			col[c] = false;
// 			lrdiag[row - c + n - 1] = false;
// 			rldiag[row + c] = false;
// 		}
// 	}
// 	return;
// }

// int main()
// {
// 	int n, c;

// 	cout << "\n\t Enter size of board : ";
// 	cin >> n;
// 	grid.assign(n, vector<int>(n, 0));
// 	col.assign(n, false);
// 	lrdiag.assign(2 * n - 1, false);
// 	rldiag.assign(2 * n - 1, false);

// 	cout << "\n\t Enter the column number where the first queen is placed : ";
// 	cin >> c;
// 	c--; // 0-based indexing
// 	grid[0][c] = 1;
// 	col[c] = true;
// 	lrdiag[n - 1 - c] = true;
// 	rldiag[0 + c] = true;

// 	n_queen(1, n);
// 	if (cnt == 0)
// 	{
// 		cout << "\n\t No Solution Exist !!" << endl;
// 	}
// 	else
// 	{
// 		cout << "\n\t Total possible solutions : " << cnt << endl;
// 	}
// }

#include <bits/stdc++.h>
#define N 4
using namespace std;

/* A utility function to print solution */
void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << " " << board[i][j] << " ";
		printf("\n");
	}
}

/* A utility function to check if a queen can
   be placed on board[row][col]. Note that this
   function is called when "col" queens are
   already placed in columns from 0 to col -1.
   So we need to check only left side for
   attacking queens */
bool isSafe(int board[N][N], int row, int col)
{
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

/* A recursive utility function to solve N
   Queen problem */
bool solveNQUtil(int board[N][N], int col)
{
	/* base case: If all queens are placed
	  then return true */
	if (col >= N)
		return true;

	/* Consider this column and try placing
	   this queen in all rows one by one */
	for (int i = 0; i < N; i++)
	{
		/* Check if the queen can be placed on
		  board[i][col] */
		if (isSafe(board, i, col))
		{
			/* Place this queen in board[i][col] */
			board[i][col] = 1;

			/* recur to place rest of the queens */
			if (solveNQUtil(board, col + 1))
				return true;

			/* If placing queen in board[i][col]
			   doesn't lead to a solution, then
			   remove queen from board[i][col] */
			board[i][col] = 0; // BACKTRACK
		}
	}

	/* If the queen cannot be placed in any row in
		this column col  then return false */
	return false;
}

/* This function solves the N Queen problem using
   Backtracking. It mainly uses solveNQUtil() to
   solve the problem. It returns false if queens
   cannot be placed, otherwise, return true and
   prints placement of queens in the form of 1s.
   Please note that there may be more than one
   solutions, this function prints one  of the
   feasible solutions.*/
bool solveNQ()
{
	int board[N][N] = {{0, 0, 0, 0},
					   {0, 0, 0, 0},
					   {0, 0, 0, 0},
					   {0, 0, 0, 0}};

	if (solveNQUtil(board, 0) == false)
	{
		cout << "Solution does not exist";
		return false;
	}

	printSolution(board);
	return true;
}

// driver program to test above function
int main()
{
	solveNQ();
	return 0;
}