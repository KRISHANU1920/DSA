// Question Link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// Recursive Approach: [TC-O(2^N) and SC-O(N)]
int solve(int ind, int W, int wt[], int val[])
{
    if(ind == 0)
    {
        if(wt[0] <= W)
            return val[0];
        else
            return 0;
    }
    
    int notTake = 0 + solve(ind-1, W, wt, val);
    int take = INT_MIN;
    if(wt[ind] <= W)
        take = val[ind] + solve(ind-1, W-wt[ind], wt, val);
    
    return max(take, notTake);
    
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
    return solve(n-1, W, wt, val);
}


// Memoization Approach: [TC-O(N*W) and SC-(O(N*W)+O(N))]
int solve(int ind, int W, int wt[], int val[], vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        if(wt[0] <= W)
            return val[0];
        else
            return 0;
    }
    
    if(dp[ind][W] != -1)
        return dp[ind][W];
    
    int notTake = 0 + solve(ind-1, W, wt, val, dp);
    int take = INT_MIN;
    if(wt[ind] <= W)
        take = val[ind] + solve(ind-1, W-wt[ind], wt, val, dp);
    
    return dp[ind][W] = max(take, notTake);
    
}

int knapSack(int W, int wt[], int val[], int n) 
{
    vector<vector<int>> dp(n, vector<int> (W+1, -1));
    return solve(n-1, W, wt, val, dp);
}

// Tabulation Approach: [TC-O(N*maxW) and SC-O(N*maxW)]
int knapSack(int maxW, int wt[], int val[], int n) 
{
    vector<vector<int>> dp(n, vector<int> (maxW+1, 0));
    
    for(int W=wt[0]; W<=maxW; W++)
        dp[0][W] = val[0];
    
    for(int ind=1; ind<n; ind++)
    {
        for(int W=0; W <= maxW; W++)
        {
            int notTake = 0 + dp[ind-1][W];
            int take = INT_MIN;
            if(wt[ind] <= W)
                take = val[ind] + dp[ind-1][W-wt[ind]];
            
            dp[ind][W] = max(take, notTake);
        }
    }
    return dp[n-1][maxW];
}


// Space Optimization Approach: [TC-O(N*maxW) and SC-O(maxW)]
int knapSack(int maxW, int wt[], int val[], int n) 
{
    vector<int> prev(maxW+1, 0), curr(maxW+1, 0);
    
    for(int W=wt[0]; W<=maxW; W++)
        prev[W] = val[0];
    
    for(int ind=1; ind<n; ind++)
    {
        for(int W=0; W <= maxW; W++)
        {
            int notTake = 0 + prev[W];
            int take = INT_MIN;
            if(wt[ind] <= W)
                take = val[ind] + prev[W-wt[ind]];
            
            curr[W] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[maxW];
}


// Single Array Space Optimization: [TC-O(N*maxW) and SC-O(maxW)]
int knapSack(int maxW, int wt[], int val[], int n) 
{
    vector<int> prev(maxW+1, 0);
    
    for(int W=wt[0]; W<=maxW; W++)
        prev[W] = val[0];
    
    for(int ind=1; ind<n; ind++)
    {
        for(int W=maxW; W >= 0; W--)
        {
            int notTake = 0 + prev[W];
            int take = INT_MIN;
            if(wt[ind] <= W)
                take = val[ind] + prev[W-wt[ind]];
            
            prev[W] = max(take, notTake);
        }
    }
    return prev[maxW];
}