// Question Link: https://practice.geeksforgeeks.org/problems/coin-change2448/1

// Recursive Approach: [TC- >> O(2^n) ~ Exponential and SC-O(W)]
int solve(int ind, int W, int val[], int wt[])
{
    if(ind == 0)
        return (W / wt[0]) * val[0];
        
    int notTake = 0 + solve(ind-1, W, val, wt);
    int take = 0;
    if(wt[ind] <= W)
        take = val[ind] + solve(ind, W - wt[ind], val, wt);
    
    return max(take, notTake);
}

int knapSack(int N, int W, int val[], int wt[])
{
    return solve(N-1, W, val, wt);
}


// Memoization Approach: [TC-O(N*W) and SC-(O(N*W)+O(W))]
int solve(int ind, int W, int val[], int wt[], vector<vector<int>> &dp)
{
    if(ind == 0)
        return (W / wt[0]) * val[0];
    
    if(dp[ind][W] != -1)
        return dp[ind][W];
        
    int notTake = 0 + solve(ind-1, W, val, wt, dp);
    int take = 0;
    if(wt[ind] <= W)
        take = val[ind] + solve(ind, W - wt[ind], val, wt, dp);
    
    return dp[ind][W] = max(take, notTake);
}

int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int> (W+1, -1));
    return solve(N-1, W, val, wt, dp);
} 


// Tabulation Approach: [TC-O(N*W) and SC-O(N*W)]
int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int> (W+1, 0));
    
    for(int w=0; w<=W; w++)
        dp[0][w] = (w / wt[0]) * val[0];
    
    for(int ind=1; ind<N; ind++)
    {
        for(int w=0; w<=W; w++)
        {
            int notTake = 0 + dp[ind-1][w];
            int take = 0;
            if(wt[ind] <= w)
                take = val[ind] + dp[ind][w - wt[ind]];
            
            dp[ind][w] = max(take, notTake);
        }
    }
    return dp[N-1][W];
}


// Space Optimization Approach: [TC-O(N*W) and SC-O(W)]
int knapSack(int N, int W, int val[], int wt[])
{
    vector<int> prev(W+1, 0), curr(W+1, 0);
    
    for(int w=0; w<=W; w++)
        prev[w] = (w / wt[0]) * val[0];
    
    for(int ind=1; ind<N; ind++)
    {
        for(int w=0; w<=W; w++)
        {
            int notTake = 0 + prev[w];
            int take = 0;
            if(wt[ind] <= w)
                take = val[ind] + curr[w - wt[ind]];
            
            curr[w] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[W];
}


// single Array Optimization
int knapSack(int N, int W, int val[], int wt[])
{
    vector<int> prev(W+1, 0);
    
    for(int w=0; w<=W; w++)
        prev[w] = (w / wt[0]) * val[0];
    
    for(int ind=1; ind<N; ind++)
    {
        for(int w=0; w<=W; w++)
        {
            int notTake = 0 + prev[w];
            int take = 0;
            if(wt[ind] <= w)
                take = val[ind] + prev[w - wt[ind]];
            
            prev[w] = max(take, notTake);
        }
    }
    return prev[W];
}