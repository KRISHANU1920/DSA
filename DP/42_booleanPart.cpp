// Question Link: https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

// Recursive Approach: [TC- Exponential and SC-O(N)]
int mod = 1e3+3;

int solve(int i, int j, int isTrue, string S)
{
    if(i > j)
        return 0;
    
    if(i == j)
    {
        if(isTrue)
            return S[i] == 'T';
        else
            return S[i] == 'F';
    }
    
    int ways = 0;
    for(int ind = i+1; ind <= j-1; ind += 2)
    {
        int lT = solve(i, ind-1, 1, S);
        int lF = solve(i, ind-1, 0, S);
        int rT = solve(ind+1, j, 1, S);
        int rF = solve(ind+1, j, 0, S);
        
        if(S[ind] == '&')
        {
            if(isTrue)
            {
                ways = (ways + (lT * rT) % mod) % mod;
            }
            else
            {
                ways = (ways + (lF * rF) % mod + (lF * rT) % mod + (lT * rF) % mod) % mod;
            }
        }
        else if(S[ind] == '|')
        {
            if(isTrue)
            {
                ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
            }
            else 
            {
                ways = (ways + (lF * rF) % mod) % mod;
            }
        }
        else if(S[ind] == '^')
        {
            if(isTrue)
            {
                ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
            }
            else
            {
                ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
            }
        }
    }
    
    return ways;
}

int countWays(int N, string S)
{
    return solve(0, N-1, 1, S);
}


// Memoization Approach: [TC-O(N^3) and SC-(O(N^2)+O(N))]
int mod = 1e3+3;

int solve(int i, int j, int isTrue, string S, vector<vector<vector<int>>> &dp)
{
    if(i > j)
        return 0;
    
    if(i == j)
    {
        if(isTrue)
            return S[i] == 'T';
        else
            return S[i] == 'F';
    }
    
    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
        
    int ways = 0;
    for(int ind = i+1; ind <= j-1; ind += 2)
    {
        int lT = solve(i, ind-1, 1, S, dp);
        int lF = solve(i, ind-1, 0, S, dp);
        int rT = solve(ind+1, j, 1, S, dp);
        int rF = solve(ind+1, j, 0, S, dp);
        
        if(S[ind] == '&')
        {
            if(isTrue)
            {
                ways = (ways + (lT * rT) % mod) % mod;
            }
            else
            {
                ways = (ways + (lF * rF) % mod + (lF * rT) % mod + (lT * rF) % mod) % mod;
            }
        }
        else if(S[ind] == '|')
        {
            if(isTrue)
            {
                ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
            }
            else 
            {
                ways = (ways + (lF * rF) % mod) % mod;
            }
        }
        else if(S[ind] == '^')
        {
            if(isTrue)
            {
                ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
            }
            else
            {
                ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
            }
        }
    }
    
    return dp[i][j][isTrue] = ways;
}

int countWays(int N, string S)
{
    vector<vector<vector<int>>> dp(N, vector<vector<int>> (N, vector<int> (2, -1)));
    return solve(0, N-1, 1, S, dp);
}


// Tabulation Approach: [TC-O(N^3) and SC-O(N^2)]
int mod = 1e3+3;

int countWays(int N, string S)
{
    vector<vector<vector<int>>> dp(N, vector<vector<int>> (N, vector<int> (2, 0)));
    
    for(int i=0; i<N; i++)
    {
        dp[i][i][1] = (S[i] == 'T');
        dp[i][i][0] = (S[i] == 'F');
    }
    
    for(int i=N-1; i>=0; i--)
    {
        for(int j=i+1; j<N; j++)
        {
            for(int isTrue = 0; isTrue<=1; isTrue++)
            {
                int ways = 0;
                for(int ind = i+1; ind <= j-1; ind += 2)
                {
                    int lT = dp[i][ind-1][1];
                    int lF = dp[i][ind-1][0];
                    int rT = dp[ind+1][j][1];
                    int rF = dp[ind+1][j][0];
                    
                    if(S[ind] == '&')
                    {
                        if(isTrue)
                        {
                            ways = (ways + (lT * rT) % mod) % mod;
                        }
                        else
                        {
                            ways = (ways + (lF * rF) % mod + (lF * rT) % mod + (lT * rF) % mod) % mod;
                        }
                    }
                    else if(S[ind] == '|')
                    {
                        if(isTrue)
                        {
                            ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
                        }
                        else 
                        {
                            ways = (ways + (lF * rF) % mod) % mod;
                        }
                    }
                    else if(S[ind] == '^')
                    {
                        if(isTrue)
                        {
                            ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
                        }
                        else
                        {
                            ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
                        }
                    }
                }
                
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][N-1][1];
}