// Problem Link: https://bit.ly/3KQELfy

// Recursive Approach: [TC-O(9^N) and SC-O(N)]
int solve(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid)
{
    if(j1<0 || j1>=m || j2<0 || j2>=m)
        return -1e8;
    
    if(i == n-1)
    {
        if(j1 == j2)
            return grid[n-1][j1];
        else
            return grid[n-1][j1] + grid[n-1][j2];
    }
    
    int maxi = -1e8;
    for(int dj1=-1; dj1<=1; dj1++)
    {
        for(int dj2=-1; dj2<=1; dj2++)
        {
            int value = 0;
            if(j1 == j2)
                value += grid[i][j1];
            else
                value += grid[i][j1] + grid[i][j2];
            value += solve(i+1, j1+dj1, j2+dj2, n, m, grid);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
    return solve(0, 0, m-1, n, m, grid);
}


// Memoization Approach: [TC-O(N*M) and SC- O(N) + O(N*M)]
int solve(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if(j1<0 || j1>=m || j2<0 || j2>=m)
        return -1e8;
    
    if(i == n-1)
    {
        if(j1 == j2)
            return grid[n-1][j1];
        else
            return grid[n-1][j1] + grid[n-1][j2];
    }
    
    if(dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    
    int maxi = -1e8;
    for(int dj1=-1; dj1<=1; dj1++)
    {
        for(int dj2=-1; dj2<=1; dj2++)
        {
            int value = 0;
            if(j1 == j2)
                value += grid[i][j1];
            else
                value += grid[i][j1] + grid[i][j2];
            value += solve(i+1, j1+dj1, j2+dj2, n, m, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
    return solve(0, 0, m-1, n, m, grid, dp);
}



// Tabulation and space optimization not required for interview. If interesed to learn then 
// follow this link: https://www.youtube.com/watch?v=QGfn7JeXK54&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=14