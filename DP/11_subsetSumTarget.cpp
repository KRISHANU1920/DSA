// Question Link: https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/

// Recursive Approach: [TC-O(2^N) and SC-O(N)]
bool solve(int ind, vector<int> &arr, int target)
{
    if(target == 0)
        return true;
    
    if(ind == 0)
        return (target == arr[0]);
    
    bool notPick = solve(ind-1, arr, target);
    bool pick = false;
    if(target >= arr[ind])
        pick = solve(ind-1, arr, target-arr[ind]);
    
    return pick | notPick;
}

bool isSubsetSum(vector<int>arr, int sum)
{
    int n = arr.size();
    return solve(n-1, arr, sum);
}


// Memoization Approach: [TC-O(N*M) and SC-(O(N*M)+O(N))]
bool solve(int ind, vector<int> &arr, int target, vector<vector<int>> &dp)
{
    if(target == 0)
        return true;
    
    if(ind == 0)
        return (target == arr[0]);
        
    if(dp[ind][target] != -1)
        return dp[ind][target];
    
    bool notPick = solve(ind-1, arr, target , dp);
    bool pick = false;
    if(target >= arr[ind])
        pick = solve(ind-1, arr, target-arr[ind], dp);
    
    return dp[ind][target] = pick | notPick;
}

bool isSubsetSum(vector<int>arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (sum+1, -1));
    return solve(n-1, arr, sum, dp);
}

// Tabulation Approach: [TC-O(N*M) and SC-O(N*M)]
bool isSubsetSum(vector<int>arr, int sum)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool> (sum+1, 0));
    
    for(int ind=0; ind<n; ind++)
        dp[ind][0] = true;
        
    dp[0][arr[0]] = true;
    
    for(int ind=1; ind<n; ind++)
    {
        for(int target=1; target<=sum; target++)
        {
            bool notPick = dp[ind-1][target];
            bool pick = false;
            if(target >= arr[ind])
                pick = dp[ind-1][target-arr[ind]];
            
            dp[ind][target] = pick | notPick;
        }
    }
    return dp[n-1][sum];
}


// Space Optimization Approach: [TC-O(N*M) and SC-O(M)]
bool isSubsetSum(vector<int>arr, int sum)
{
    int n = arr.size();
    vector<bool> prev(sum+1, 0), curr(sum+1, 0);
    
    prev[0] = curr[0] = true;
    
    if(arr[0] <= sum)
        prev[arr[0]] = true;
    
    for(int ind=1; ind<n; ind++)
    {
        for(int target=1; target<=sum; target++)
        {
            bool notPick = prev[target];
            bool pick = false;
            if(target >= arr[ind])
                pick = prev[target-arr[ind]];
            
            curr[target] = pick | notPick;
        }
        prev = curr;
    }
    return prev[sum];
}