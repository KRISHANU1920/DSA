// Question Link : https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

bool SolveSudoku(int grid[N][N])  
{ 
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(grid[i][j] == 0)
            {
                for(int c=1; c<=9; c++)
                {
                    if(isValid(grid, i, j, c))
                    {
                        grid[i][j] = c;
                        
                        if(SolveSudoku(grid) == true)
                            return true;
                        else
                            grid[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isValid(int grid[N][N], int row, int col, int c)
{
    for(int i=0; i<N; i++)
    {
        // checking row elements
        if(grid[row][i] == c)
            return false;
        
        // checking column elements
        if(grid[i][col] == c)
            return false;
        
        // checking it's 3x3 grid
        if(grid[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == c)
            return false;
    }
    return true;
}

//Function to print grids of the Sudoku.
void printGrid (int grid[N][N]) 
{
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cout << grid[i][j] << " ";
}

/*

Time Complexity: O(9^(N*N))
Space Complexity: O(N*N)

*/