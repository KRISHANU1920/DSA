// Question Link: https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

// Recursive Approach: [TC- Exponential and SC-O(N)]
int solve(int i, int k, int n, vector<int> &arr)
{
    if(i == n)
        return 0;
    
    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;
    
    for(int j=i; j<min(n, i+k); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = (len * maxi) + solve(j+1, k, n, arr);
        maxAns = max(maxAns, sum);
    }
    return maxAns;
}

int maxSumAfterPartitioning(vector<int>& arr, int k) 
{
    int n = arr.size();
    return solve(0, k, n, arr);
}


// Memoization Approach: [TC-O(N*K) and SC-(O(N)+O(N))]
int solve(int i, int k, int n, vector<int> &arr, vector<int> &dp)
{
    if(i == n)
        return 0;
    
    if(dp[i] != -1)
        return dp[i];
    
    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;
    
    for(int j=i; j<min(n, i+k); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = (len * maxi) + solve(j+1, k, n, arr, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[i] = maxAns;
}

int maxSumAfterPartitioning(vector<int>& arr, int k) 
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return solve(0, k, n, arr, dp);
}


// Tabulation Approach: [TC-O(N*K) and SC-O(N)]
int maxSumAfterPartitioning(vector<int>& arr, int k) 
{
    int n = arr.size();
    vector<int> dp(n+1, 0);
    
    dp[n] = 0;
    
    for(int i=n-1; i>=0; i--)
    {
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        for(int j=i; j<min(n, i+k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (len * maxi) + dp[j+1];
            maxAns = max(maxAns, sum);
        }
        dp[i] = maxAns;
    }
    return dp[0];
}