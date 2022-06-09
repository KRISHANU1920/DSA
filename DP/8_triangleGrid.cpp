// Recursive Approach: [TC-O(2^(N^2))) and SC-O(N)]
int solve(int i, int j, vector<vector<int>> &triangle, int n)
{
    if(i == n-1)
        return triangle[n-1][j];
    
    int down = triangle[i][j] + solve(i+1, j, triangle, n);
    int diag = triangle[i][j] + solve(i+1, j+1, triangle, n);
    
    return min(down, diag);
}

int minimumPathSum(vector<vector<int>>& triangle, int n)
{
	return solve(0, 0, triangle, n);
}


// Memoization Approach: [TC-O(N^2) and SC- O(N) + O(N*N)]
int solve(int i, int j, vector<vector<int>> &triangle, int n, 
          vector<vector<int>> &dp)
{
    if(i == n-1)
        return triangle[n-1][j];
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int down = triangle[i][j] + solve(i+1, j, triangle, n, dp);
    int diag = triangle[i][j] + solve(i+1, j+1, triangle, n, dp);
    
    return dp[i][j] = min(down, diag);
}

int minimumPathSum(vector<vector<int>>& triangle, int n)
{
    vector<vector<int>> dp(n, vector<int> (n, -1));
	return solve(0, 0, triangle, n, dp);
}

// Tabulation Approach: [TC-O(N*N) and SC-O(N*N)]
int minimumPathSum(vector<vector<int>>& triangle, int n)
{
    vector<vector<int>> dp(n, vector<int> (n, -1));
	
    for(int j=0; j<n; j++)
        dp[n-1][j] = triangle[n-1][j];
    
    for(int i=n-2; i>=0; i--)
    {
        for(int j=i; j>=0; j--)
        {
            int down = triangle[i][j] + dp[i+1][j];
            int diag = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, diag);
        }
    }
    return dp[0][0];
}



// Space Optimization Approach: [TC-O(N*N) and SC-O(N)]
int minimumPathSum(vector<vector<int>>& triangle, int n)
{
    vector<int> next(n, 0);
	
    for(int j=0; j<n; j++)
        next[j] = triangle[n-1][j];
    
    for(int i=n-2; i>=0; i--)
    {
        vector<int> curr(n, 0);
        for(int j=i; j>=0; j--)
        {
            int down = triangle[i][j] + next[j];
            int diag = triangle[i][j] + next[j+1];
            curr[j] = min(down, diag);
        }
        next = curr;
    }
    return next[0];
}