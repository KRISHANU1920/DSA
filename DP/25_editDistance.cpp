// Question Link: https://practice.geeksforgeeks.org/problems/edit-distance3702/1/

// Recursive Approach: [TC- >> O(2^M * 2^N) ~ Exponential and SC-O(M+N)]
int solve(int i, int j, string &s, string &t)
{
    if(i < 0)
        return j + 1;
    
    if(j < 0)
        return i + 1;
        
    if(s[i] == t[j])
        return 0 + solve(i-1, j-1, s, t);
    
    else
    {
        int ins = 1 + solve(i, j-1, s, t);
        int del = 1 + solve(i-1, j, s, t);
        int rep = 1 + solve(i-1, j-1, s, t);
        
        return min(ins, min(del, rep));
    }
}

int editDistance(string s, string t) 
{
    int m = s.size();
    int n = t.size();
    
    return solve(m-1, n-1, s, t);
}


// Memoization Approach: [TC-O(M*N) and SC-(O(M*N)+O(M+N))]
int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if(i < 0)
        return j + 1;
    
    if(j < 0)
        return i + 1;
        
    if(dp[i][j] != -1)
        return dp[i][j];
        
    if(s[i] == t[j])
        return dp[i][j] = 0 + solve(i-1, j-1, s, t, dp);
    
    else
    {
        int ins = 1 + solve(i, j-1, s, t, dp);
        int del = 1 + solve(i-1, j, s, t, dp);
        int rep = 1 + solve(i-1, j-1, s, t, dp);
        
        return dp[i][j] = min(ins, min(del, rep));
    }
}

int editDistance(string s, string t) 
{
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m, vector<int> (n, -1));
    return solve(m-1, n-1, s, t, dp);
}


// Tabulation Approach: [TC-O(M*N) and SC-O(M*N)]
int editDistance(string s, string t) 
{
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    
    for(int i=0; i<=m; i++)
        dp[i][0] = i;
    
    for(int j=1; j<=n; j++)
        dp[0][j] = j;
        
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s[i-1] == t[j-1])
                dp[i][j] = 0 + dp[i-1][j-1];
            
            else
            {
                int ins = 1 + dp[i][j-1];
                int del = 1 + dp[i-1][j];
                int rep = 1 + dp[i-1][j-1];
                
                dp[i][j] = min(ins, min(del, rep));
            }
        }
    }
    return dp[m][n];
}


// Space Optimization Approach: [TC-O(M*N) and SC-O(N)]
int editDistance(string s, string t) 
{
    int m = s.size();
    int n = t.size();
    vector<int> prev(n+1, 0), curr(n+1, 0);
    
    for(int j=0; j<=n; j++)
        prev[j] = j;
        
    for(int i=1; i<=m; i++)
    {
        curr[0] = i;
        for(int j=1; j<=n; j++)
        {
            if(s[i-1] == t[j-1])
                curr[j] = 0 + prev[j-1];
            
            else
            {
                int ins = 1 + curr[j-1];
                int del = 1 + prev[j];
                int rep = 1 + prev[j-1];
                
                curr[j] = min(ins, min(del, rep));
            }
        }
        prev = curr;
    }
    return prev[n];
}


// single Array Optimization - Not possible because at the same moment both prev and curr are required.