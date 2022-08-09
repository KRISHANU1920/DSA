// Question Link: https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

// Recursive Approach: [TC- Exponential and SC-O(N)]
bool isPalindrome(int i, int j, string str)
{
    while(i<j)
    {
        if(str[i] != str[j])
            return false;
        
        i++;
        j--;
    }
    return true;
}

int solve(int i, int N, string str)
{
    if(i == N)
        return 0;
    
    int minCost = INT_MAX;
    for(int j=i; j<N; j++)
    {
        if(isPalindrome(i, j, str))
        {
            int cost = 1 + solve(j+1, N, str);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

int palindromicPartition(string str)
{
    int N = str.size();
    return solve(0, N, str)-1;
}


// Memoization Approach: [TC-O(N^2) and SC-(O(N)+O(N))]
bool isPalindrome(int i, int j, string str)
{
    while(i<j)
    {
        if(str[i] != str[j])
            return false;
        
        i++;
        j--;
    }
    return true;
}

int solve(int i, int N, string str, vector<int> &dp)
{
    if(i == N)
        return 0;
    
    if(dp[i] != -1)
        return dp[i];
        
    int minCost = INT_MAX;
    for(int j=i; j<N; j++)
    {
        if(isPalindrome(i, j, str))
        {
            int cost = 1 + solve(j+1, N, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}

int palindromicPartition(string str)
{
    int N = str.size();
    vector<int> dp(N, -1);
    return solve(0, N, str, dp) - 1;
}


// Tabulation Approach: [TC-O(N^2) and SC-O(N)]
bool isPalindrome(int i, int j, string str)
{
    while(i<j)
    {
        if(str[i] != str[j])
            return false;
        
        i++;
        j--;
    }
    return true;
}

int palindromicPartition(string str)
{
    int N = str.size();
    vector<int> dp(N+1, 0);
    
    dp[N] = 0;
    
    for(int i=N-1; i>=0; i--)
    {
        int minCost = INT_MAX;
        for(int j=i; j<N; j++)
        {
            if(isPalindrome(i, j, str))
            {
                int cost = 1 + dp[j+1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    
    return dp[0] - 1;
}