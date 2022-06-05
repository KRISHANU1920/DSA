#include<bits/stdc++.h>
using namespace std;

// Recursive function to solve the Knight Tour Problem
bool solve(vector<vector<int>> &board, int N, int x, int y, int move, int xMove[8], int yMove[8])
{
    if(move == N*N)
        return true;
    
    // Trying all the possible moves for current index
    for(int i=0; i<8; i++)
    {
        int next_x = x + xMove[i];
        int next_y = y + yMove[i];

        if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && board[next_x][next_y] == -1)
        {
            board[next_x][next_y] = move;

            if(solve(board, N, next_x, next_y, move+1, xMove, yMove))
                return true;
            
            board[next_x][next_y] = -1;  // backtracking
        }
    }
    return false;
}

// function to print the board
void printBoard(vector<vector<int>> board, int N)
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << board[x][y] << " ";
        cout << endl;
    }
}

int main()
{
    int N;
    cout << "Enter size of the board: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int> (N, -1));

    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    board[0][0] = 0;

    if(solve(board, N, 0, 0, 1, xMove, yMove))
        printBoard(board, N);
    else
        cout << "Board Doesn't exist!!" << endl;
    
    return 0;
}


/*

Time Complexity: O(8^(N^2))
Space Complexity: O(N^2)

*/