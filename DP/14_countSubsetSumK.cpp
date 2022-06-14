// Question Link: https://bit.ly/3B5JBkU

// Recursive Approach: [TC-O(2^N) and SC-O(N)]
int solve(int ind, int sum, vector<int> &num)
{
    if(sum == 0)
        return 1;
    
    if(ind == 0)
        return (num[0] == sum);
    
    int notTake = solve(ind-1, sum, num);
    int take = 0;
    if(num[ind] <= sum)
        take = solve(ind-1, sum-num[ind], num);
    
    return take + notTake;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    return solve(n-1, tar, num);
}


// Memoization Approach: [TC-O(N*sum) and SC-(O(N*sum)+O(N))]
int solve(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
{
    if(sum == 0)
        return 1;
    
    if(ind == 0)
        return (num[0] == sum);
    
    if(dp[ind][sum] != -1)
        return dp[ind][sum];
    
    int notTake = solve(ind-1, sum, num, dp);
    int take = 0;
    if(num[ind] <= sum)
        take = solve(ind-1, sum-num[ind], num, dp);
    
    return dp[ind][sum] = take + notTake;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, -1));
    return solve(n-1, tar, num, dp);
}

/*
    Note: If num = {0, 0, 1} then the above code gives wrong output.

    Solution:
    1) remove the base case: if(sum == 0) return 1;
    2) update the base case: 

        if(ind == 0)
        {
            if(sum == 0 && arr[0] == 0) return 2;
            if(sum == 0 || arr[0] == sum) return 1;
            else return 0;
        }

*/


// Tabulation Approach: [TC-O(N*sum) and SC-O(N*sum)]
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, 0));
    
    for(int i=0; i<n; i++)
        dp[i][0] = 1;
    
    if(num[0] <= tar)
        dp[0][num[0]] = 1;
    
    for(int ind=1; ind<n; ind++)
    {
        for(int sum=0; sum<=tar; sum++)
        {
            int notTake = dp[ind-1][sum];
            int take = 0;
            if(num[ind] <= sum)
                take = dp[ind-1][sum-num[ind]];

            dp[ind][sum] = take + notTake;
        }
    }
    return dp[n-1][tar];
}


// Space Optimization Approach: [TC-O(N*sum) and SC-O(sum)]
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar+1, 0), curr(tar+1, 0);
    
    prev[0] = curr[0] = 1;
    
    if(num[0] <= tar)
        prev[num[0]] = 1;
    
    for(int ind=1; ind<n; ind++)
    {
        for(int sum=0; sum<=tar; sum++)
        {
            int notTake = prev[sum];
            int take = 0;
            if(num[ind] <= sum)
                take = prev[sum-num[ind]];

            curr[sum] = take + notTake;
        }
        prev = curr;
    }
    return prev[tar];
}