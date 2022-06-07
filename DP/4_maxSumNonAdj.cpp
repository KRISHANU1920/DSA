// Recursive Approach: [TC-O(2^N) and SC-O(N)]
int solve(int n, vector<int> &nums)
{
    if(n == 0)
        return nums[n];
    
    if(n < 0)
        return 0;
    
    int pick = nums[n] + solve(n-2, nums);
    int notPick = 0 + solve(n-1, nums);
    
    return max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    return solve(n-1, nums);
}


// Memoization Approach: [TC-O(N) and SC-(O(N)+O(N))]
int solve(int n, vector<int> &nums, vector<int> &dp)
{
    if(n == 0)
        return nums[n];
    
    if(n < 0)
        return 0;
    
    if(dp[n] != -1)
        return dp[n];
    
    int pick = nums[n] + solve(n-2, nums, dp);
    int notPick = 0 + solve(n-1, nums, dp);
    
    return dp[n] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(n-1, nums, dp);
}

// Tabulation Approach: [TC-O(N) and SC-O(N)]
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    
    dp[0] = nums[0];
    int neg = 0;
    
    for(int i=1; i<n; i++)
    {
        int pick = nums[i];
        if(i > 1)
            pick += dp[i-2];
        int notPick = 0 + dp[i-1];
        
        dp[i] = max(pick, notPick);
    }
    return dp[n-1];
}


// Space Optimization Approach: [TC-O(N) and SC-O(1)]
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    
    int prev1 = nums[0];
    int prev2 = 0;
    
    for(int i=1; i<n; i++)
    {
        int pick = nums[i];
        if(i > 1)
            pick += prev2;
        
        int notPick = 0 + prev1;
        
        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}