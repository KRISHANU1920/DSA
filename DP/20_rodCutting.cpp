// Question Link: https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/

// Recursive Approach: [TC- >> O(2^N) ~ Exponential and SC-O(N)]
int solve(int ind, int n, int price[])
{
    if(ind == 0)
    {
        return n * price[0];
    }
    
    int notTake = 0 + solve(ind-1, n, price);
    int take = 0;
    int rodLen = ind + 1;
    if(rodLen <= n)
        take = price[ind] + solve(ind, n-rodLen, price);
    
    return max(take, notTake);
}

int cutRod(int price[], int n) 
{
    return solve(n-1, n, price);
}


// Memoization Approach: [TC-O(N*N) and SC-(O(N*N)+O(N))]
int solve(int ind, int n, int price[], vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        return n * price[0];
    }
    
    if(dp[ind][n] != -1)
        return dp[ind][n];
        
    int notTake = 0 + solve(ind-1, n, price, dp);
    int take = 0;
    int rodLen = ind + 1;
    if(rodLen <= n)
        take = price[ind] + solve(ind, n-rodLen, price, dp);
    
    return dp[ind][n] = max(take, notTake);
}

int cutRod(int price[], int n) 
{
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return solve(n-1, n, price, dp);
} 


// Tabulation Approach: [TC-O(N*N) and SC-O(N*N)]
int cutRod(int price[], int n) 
{
    vector<vector<int>> dp(n, vector<int> (n+1, 0));
    
    for(int len=0; len<=n; len++)
        dp[0][len] = len * price[0];
    
    for(int ind=1; ind<n; ind++)
    {
        for(int len=0; len<=n; len++)
        {
            int notTake = 0 + dp[ind-1][len];
            int take = 0;
            int rodLen = ind + 1;
            if(rodLen <= len)
                take = price[ind] + dp[ind][len-rodLen];
            
            dp[ind][len] = max(take, notTake);
        }
    }
    return dp[n-1][n];
}


// Space Optimization Approach: [TC-O(N*N) and SC-O(N)]
int cutRod(int price[], int n) 
{
    vector<int> prev(n+1, 0), curr(n+1, 0);
    
    for(int len=0; len<=n; len++)
        prev[len] = len * price[0];
    
    for(int ind=1; ind<n; ind++)
    {
        for(int len=0; len<=n; len++)
        {
            int notTake = 0 + prev[len];
            int take = 0;
            int rodLen = ind + 1;
            if(rodLen <= len)
                take = price[ind] + curr[len-rodLen];
            
            curr[len] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[n];
}


// single Array Optimization
int cutRod(int price[], int n) 
{
    vector<int> prev(n+1, 0);
    
    for(int len=0; len<=n; len++)
        prev[len] = len * price[0];
    
    for(int ind=1; ind<n; ind++)
    {
        for(int len=0; len<=n; len++)
        {
            int notTake = 0 + prev[len];
            int take = 0;
            int rodLen = ind + 1;
            if(rodLen <= len)
                take = price[ind] + prev[len-rodLen];
            
            prev[len] = max(take, notTake);
        }
    }
    return prev[n];
}