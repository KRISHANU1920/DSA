// Recursive Approach: [TC-O(2^N) and SC-O(N)]
int solve(int n, vector<int> &heights)
{
    if(n == 0)
        return 0;
    
    int left = solve(n-1, heights) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    
    if(n > 1)
        right = solve(n-2, heights) + abs(heights[n] - heights[n-2]);
    
    return min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    return solve(n-1, heights);
}


// Memoization Approach: [TC-O(N) and SC-(O(N)+O(N))]
int solve(int n, vector<int> &heights, vector<int> &dp)
{
    if(n == 0)
        return 0;
    
    if(dp[n] != -1)
        return dp[n];
    
    int left = solve(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    
    if(n > 1)
        right = solve(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
    
    return dp[n] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return solve(n-1, heights, dp);
}


// Tabulation Approach: [TC-O(N) and SC-O(N)]
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    
    for(int i=1; i<n; i++)
    {
        int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        
        if(i>1)
            ss = dp[i-2] + abs(heights[i] - heights[i-2]);
        
        dp[i] = min(fs, ss;
    }
    return dp[n-1];
}


// Space Optimization Approach: [TC-O(N) and SC-O(1)]
int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 = 0;
    
    for(int i=1; i<n; i++)
    {
        int fs = prev1 + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        
        if(i>1)
            ss = prev2 + abs(heights[i] - heights[i-2]);
        
        int curr = min(fs, ss);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}