// Question Link: https://practice.geeksforgeeks.org/problems/number-of-coins1824/1/

// Recursive Approach: [TC- >> O(2^M) and SC-O(T)]
int solve(int ind, int T, int coins[])
{
    if(ind == 0)
    {
        if(T % coins[0] == 0)
            return T / coins[0];
        else
            return 1e9;
    }
    
    int notTake = 0 + solve(ind-1, T, coins);
    int take = 1e9;
    if(coins[ind] <= T)
        take = 1 + solve(ind, T-coins[ind], coins);
    
    return max(take, notTake);
}

int minCoins(int coins[], int M, int V) 
{ 
    int ans = solve(M-1, V, coins);
    if(ans >= 1e9)
        return -1;
    else
        return ans;
}


// Memoization Approach: [TC-O(M*T) and SC-(O(M*T)+O(T))]
int solve(int ind, int T, int coins[], vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        if(T % coins[0] == 0)
            return T / coins[0];
        else
            return 1e9;
    }
    
    if(dp[ind][T] != -1)
        return dp[ind][T];
    
    int notTake = 0 + solve(ind-1, T, coins, dp);
    int take = 1e9;
    if(coins[ind] <= T)
        take = 1 + solve(ind, T-coins[ind], coins, dp);
    
    return dp[ind][T] = min(take, notTake);
}

int minCoins(int coins[], int M, int V) 
{ 
    vector<vector<int>> dp(M, vector<int> (V+1, -1));
    int ans = solve(M-1, V, coins, dp);
    if(ans >= 1e9)
        return -1;
    else
        return ans;
} 

// Tabulation Approach: [TC-O(M*T) and SC-O(M*T)]
int minCoins(int coins[], int M, int V) 
{ 
    vector<vector<int>> dp(M, vector<int> (V+1, 0));
    
    for(int T=0; T<=V; T++)
    {
        if(T % coins[0] == 0)
            dp[0][T] = T / coins[0];
        else
            dp[0][T] = 1e9;
    }
    
    for(int ind=1; ind<M; ind++)
    {
        for(int T=0; T<=V; T++)
        {
            int notTake = 0 + dp[ind-1][T];
            int take = 1e9;
            if(coins[ind] <= T)
                take = 1 + dp[ind][T-coins[ind]];
            
            dp[ind][T] = min(take, notTake);
        }
    }
    
    int ans = dp[M-1][V];
    if(ans >= 1e9)
        return -1;
    else
        return ans;
} 


// Space Optimization Approach: [TC-O(M*T) and SC-O(M*T)]
int minCoins(int coins[], int M, int V) 
{ 
    vector<int> prev(V+1, 0), curr(V+1, 0);
    
    for(int T=0; T<=V; T++)
    {
        if(T % coins[0] == 0)
            prev[T] = T / coins[0];
        else
            prev[T] = 1e9;
    }
    
    for(int ind=1; ind<M; ind++)
    {
        for(int T=0; T<=V; T++)
        {
            int notTake = 0 + prev[T];
            int take = 1e9;
            if(coins[ind] <= T)
                take = 1 + curr[T-coins[ind]];
            
            curr[T] = min(take, notTake);
        }
        prev = curr;
    }
    
    int ans = prev[V];
    if(ans >= 1e9)
        return -1;
    else
        return ans;
} 


// Single Array Optimization
int minCoins(int coins[], int M, int V) 
{ 
    vector<int> prev(V+1, 0);
    
    for(int T=0; T<=V; T++)
    {
        if(T % coins[0] == 0)
            prev[T] = T / coins[0];
        else
            prev[T] = 1e9;
    }
    
    for(int ind=1; ind<M; ind++)
    {
        for(int T=0; T<=V; T++)
        {
            int notTake = 0 + prev[T];
            int take = 1e9;
            if(coins[ind] <= T)
                take = 1 + prev[T-coins[ind]];
            
            prev[T] = min(take, notTake);
        }
    }
    
    int ans = prev[V];
    if(ans >= 1e9)
        return -1;
    else
        return ans;
} 
	 