// Recursive Approach: [TC-O(2^(M*N)) and SC-O((M-1)+(N-1))]
int solve(int i, int j)
{
    if(i==0 && j==0)
        return 1;
    
    if(i<0 || j<0)
        return 0;
    
    int up = solve(i-1, j);
    int left = solve(i, j-1);
    
    return up + left;
}

int uniquePaths(int m, int n) 
{
	return solve(m-1, n-1);
}


// Memoization Approach: [TC-O(M*N) and SC- O((M-1)+(N-1)) + O(M*N)]
int solve(int i, int j, vector<vector<int>> &dp)
{
    if(i==0 && j==0)
        return 1;
    
    if(i<0 || j<0)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int up = solve(i-1, j, dp);
    int left = solve(i, j-1, dp);
    
    return dp[i][j] = up + left;
}

int uniquePaths(int m, int n) 
{
    vector<vector<int>> dp(m, vector<int> (n, -1));
	return solve(m-1, n-1, dp);
}

// Tabulation Approach: [TC-O(M*N) and SC-O(M*N)]
int uniquePaths(int m, int n) 
{
    vector<vector<int>> dp(m, vector<int> (n, -1));
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 && j==0)
                dp[i][j] = 1;
            else
            {
                int up = 0;
                int left = 0;

                if(i > 0)
                    up = dp[i-1][j];
                if(j > 0)
                    left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }
    }
	return dp[m-1][n-1];
}




// ------------- Can STOP the discussion with the Interviewer here -------------------------






// Space Optimization Approach: [TC-O(N*M) and SC-O(N)]
int uniquePaths(int m, int n) 
{
    vector<int> prev(n, 0);
    for(int i=0; i<m; i++)
    {
        vector<int> curr(n, 0);
        for(int j=0; j<n; j++)
        {
            if(i==0 && j==0)
                curr[j] = 1;
            else
            {
                int up = 0;
                int left = 0;

                if(i > 0)
                    up = prev[j];
                if(j > 0)
                    left = curr[j-1];

                curr[j] = up + left;
            }
        }
        prev = curr;
    }
	return prev[n-1];
}



// Note: Time Complexity can be further optimized with the help of combinatorics
// Solution Link: https://www.youtube.com/watch?v=t_f0nwwdg5o&t=0s