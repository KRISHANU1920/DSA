// Question Link: https://practice.geeksforgeeks.org/problems/coin-change2448/1

// Recursive Approach: [TC- >> O(2^M) and SC-O(n)]
long long int solve(int ind, int n, int S[])
{
    if(ind == 0)
    {
        return (n % S[0] == 0);
    }
           
    long long int notTake = solve(ind-1, n, S);
    long long int take = 0;
    if(S[ind] <= n)
        take = solve(ind, n-S[ind], S);
    
    return take + notTake;
}

long long int count(int S[], int m, int n) 
{
    return solve(m-1, n, S);
}


// Memoization Approach: [TC-O(M*N) and SC-(O(M*N)+O(N))]
long long int solve(int ind, int n, int S[], vector<vector<long long int>> &dp)
{
    if(ind == 0)
    {
        return (n % S[0] == 0);
    }
    
    if(dp[ind][n] != -1)
        return dp[ind][n];
        
    long long int notTake = solve(ind-1, n, S, dp);
    long long int take = 0;
    if(S[ind] <= n)
        take = solve(ind, n-S[ind], S, dp);
    
    return dp[ind][n] = take + notTake;
}

long long int count(int S[], int m, int n) 
{
    vector<vector<long long int>> dp(m, vector<long long int> (n+1, -1));
    return solve(m-1, n, S, dp);
} 


// Tabulation Approach: [TC-O(M*N) and SC-O(M*N)]
long long int count(int S[], int m, int n) 
{
    vector<vector<long long int>> dp(m, vector<long long int> (n+1, 0));
    
    for(int amt=0; amt<=n; amt++)
    {
        if(amt % S[0] == 0)
            dp[0][amt] = 1;
    }
    
    for(int ind=1; ind<m; ind++)
    {
        for(int amt=0; amt<=n; amt++)
        {
            long long int notTake = dp[ind-1][amt];
            long long int take = 0;
            if(S[ind] <= amt)
                take = dp[ind][amt-S[ind]];
            
            dp[ind][amt] = take + notTake;
        }
    }
    return dp[m-1][n];
}


// Space Optimization Approach: [TC-O(M*N) and SC-O(N)]
long long int count(int S[], int m, int n) 
{
    vector<long long int> prev(n+1, 0), curr(n+1, 0);
    
    for(int amt=0; amt<=n; amt++)
    {
        if(amt % S[0] == 0)
            prev[amt] = 1;
    }
    
    for(int ind=1; ind<m; ind++)
    {
        for(int amt=0; amt<=n; amt++)
        {
            long long int notTake = prev[amt];
            long long int take = 0;
            if(S[ind] <= amt)
                take = curr[amt-S[ind]];
            
            curr[amt] = take + notTake;
        }
        prev = curr;
    }
    return prev[n];
} 


// single Array Optimization
long long int count(int S[], int m, int n) 
{
    vector<long long int> prev(n+1, 0);
    
    for(int amt=0; amt<=n; amt++)
    {
        if(amt % S[0] == 0)
            prev[amt] = 1;
    }
    
    for(int ind=1; ind<m; ind++)
    {
        for(int amt=0; amt<=n; amt++)
        {
            long long int notTake = prev[amt];
            long long int take = 0;
            if(S[ind] <= amt)
                take = prev[amt-S[ind]];
            
            prev[amt] = take + notTake;
        }
    }
    return prev[n];
}