// Recursive Approach: [TC-O(K^N) and SC-O(N)]
int solve(int n, vector<int> &heights, int k)
{
    if(n == 0)
        return 0;
    
    int minSteps = INT_MAX;
    for(int j=1; j<=k; j++)
    {
        if(n-j >= 0)
        {
            int jump = solve(n-j, heights, k) + abs(heights[n] - heights[n-j])
            minSteps = min(jump, minSteps);
        }
    }
    return minSteps;
}

int frogJump(int n, vector<int> &heights, int k)
{
    return solve(n-1, heights, k);
}


// Memoization Approach: [TC-O(N*K) and SC-(O(N)+O(N))]
int solve(int n, vector<int> &heights, int k, vector<int> &dp)
{
    if(n == 0)
        return 0;
    
    if(dp[n] != -1)
        return dp[n];

    int minSteps = INT_MAX;
    for(int j=1; j<=k; j++)
    {
        if(n-j >= 0)
        {
            int jump = solve(n-j, heights, k, dp) + abs(heights[n] - heights[n-j])
            minSteps = min(jump, minSteps);
        }
    }
    return dp[n] = minSteps;
}

int frogJump(int n, vector<int> &heights, int k)
{
    vector<int> dp(n, -1);
    return solve(n-1, heights, k, dp);
}


// Tabulation Approach: [TC-O(N*K) and SC-O(N)]
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    
    for(int i=1; i<n; i++)
    {
        int minSteps = INT_MAX;
        for(int j=1; j<=k; j++)
        {
            if(i-j >= 0)
            {
                int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                minSteps = min(jump, minSteps);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}


/* 

Space Optimization Approach: 

    Here Space optimization cannot be done for O(1). We can only optimize uptp O(K) 
    but that to if (N == K), i.e. worst case scenario Space complexity will be O(N) again. 
    So no use of space optimization.

*/
