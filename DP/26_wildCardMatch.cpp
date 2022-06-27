// Question Link: https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1#

// Recursive Approach: [TC- >> O(2^M * 2^N) ~ Exponential and SC-O(M+N)]
bool solve(int i, int j, string &wild, string &pattern)
{
    if(i<0 && j<0)
        return true;
    
    if(i<0 && j>=0)
        return false;
    
    if(i>=0 && j<0)
    {
        for(int ii=0; ii<=i; ii++)
        {
            if(wild[ii] != '*')
                return false;
        }
        return true;
    }
    
    if(wild[i] == pattern[j] || wild[i] == '?')
        return solve(i-1, j-1, wild, pattern);
    
    if(wild[i] == '*')
        return solve(i-1, j, wild, pattern) | solve(i, j-1, wild, pattern);
    
    return false;
}

bool match(string wild, string pattern)
{
    int m = wild.size();
    int n = pattern.size();
    
    return solve(m-1, n-1, wild, pattern);
}


// Memoization Approach: [TC-O(M*N) and SC-(O(M*N)+O(M+N))]
bool solve(int i, int j, string &wild, string &pattern, vector<vector<int>> &dp)
{
    if(i<0 && j<0)
        return true;
    
    if(i<0 && j>=0)
        return false;
    
    if(i>=0 && j<0)
    {
        for(int ii=0; ii<=i; ii++)
        {
            if(wild[ii] != '*')
                return false;
        }
        return true;
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(wild[i] == pattern[j] || wild[i] == '?')
        return dp[i][j] = solve(i-1, j-1, wild, pattern, dp);
    
    if(wild[i] == '*')
        return dp[i][j] = solve(i-1, j, wild, pattern, dp) | solve(i, j-1, wild, pattern, dp);
    
    return dp[i][j] = false;
}

bool match(string wild, string pattern)
{
    int m = wild.size();
    int n = pattern.size();
    vector<vector<int>> dp(m, vector<int> (n, -1));
    return solve(m-1, n-1, wild, pattern, dp);
}

