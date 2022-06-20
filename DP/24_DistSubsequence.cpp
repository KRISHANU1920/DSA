// Question Link: https://practice.geeksforgeeks.org/problems/distinct-occurrences/1/#

// Recursive Approach: [TC- >> O(2^M * 2^N) ~ Exponential and SC-O(M+N)]
int mod = 1e9+7;
int solve(int i, int j, string S, string T)
{
    if(j < 0)
        return 1;
    
    if(i < 0)
        return 0;
        
    if(S[i] == T[j])
        return (solve(i-1, j-1, S, T) + solve(i-1, j, S, T)) % mod;
    else
        return solve(i-1, j, S, T);
}

int subsequenceCount(string S, string T)
{
    int m = S.size();
    int n = T.size();
    
    return solve(m-1, n-1, S, T);
}


// Memoization Approach: [TC-O(M*N) and SC-(O(M*N)+O(M+N))]
int mod = 1e9+7;
int solve(int i, int j, string S, string T, vector<vector<int>> &dp)
{
    if(j == 0)
        return 1;
    
    if(i == 0)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
        
    if(S[i-1] == T[j-1])
        return dp[i][j] = (solve(i-1, j-1, S, T, dp) + solve(i-1, j, S, T, dp)) % mod;
    else
        return dp[i][j] = solve(i-1, j, S, T, dp);
}

int subsequenceCount(string S, string T)
{
    int m = S.size();
    int n = T.size();
    
    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    return solve(m, n, S, T, dp);
}


// Tabulation Approach: [TC-O(N*N) and SC-O(N*N)]
int mod = 1e9+7;

int subsequenceCount(string S, string T)
{
    int m = S.size();
    int n = T.size();
    
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    
    for(int i=0; i<=m; i++)
        dp[i][0] = 1;
    
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(S[i-1] == T[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[m][n];
}


// Space Optimization Approach: [TC-O(N*N) and SC-O(N)]
int mod = 1e9+7;

int subsequenceCount(string S, string T)
{
    int m = S.size();
    int n = T.size();
    
    vector<int> prev(n+1, 0), curr(n+1, 0);
    
    prev[0] = curr[0] = 1;
    
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(S[i-1] == T[j-1])
                curr[j] = (prev[j-1] + prev[j]) % mod;
            else
                curr[j] = prev[j];
        }
        prev = curr;
    }
    
    return prev[n];
}


// single Array Optimization
int mod = 1e9+7;

int subsequenceCount(string S, string T)
{
    int m = S.size();
    int n = T.size();
    
    vector<int> dp(n+1, 0);
    
    dp[0] = 1;
    
    for(int i=1; i<=m; i++)
    {
        for(int j=n; j>=1; j--)
        {
            if(S[i-1] == T[j-1])
                dp[j] = (dp[j-1] + dp[j]) % mod;
        }
    }
    
    return dp[n];
}