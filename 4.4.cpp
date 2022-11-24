#include <bits/stdc++.h>
using namespace std;
#define N 4;
bool isSafe(vector < vector<int> board, int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    for (i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
}

bool solveNQUtil(vector < vector<int> board, int col)
{
    if (col >= N)
    {
        return true;
    }
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}