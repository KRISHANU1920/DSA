// Question Link : https://bit.ly/3r8mG5b

// Tabulation Approach: [TC-O(N*sum) and SC-O(N*sum)]
int mod = 1e9+7;

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, 0));
    
    if(num[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    
    if(num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1;
    
    for(int ind=1; ind<n; ind++)
    {
        for(int sum=0; sum<=tar; sum++)
        {
            int notTake = dp[ind-1][sum];
            int take = 0;
            if(num[ind] <= sum)
                take = dp[ind-1][sum-num[ind]];

            dp[ind][sum] = (take + notTake) % mod;
        }
    }
    return dp[n-1][tar];
}

int countPartitions(int n, int d, vector<int> &arr) 
{
    int totalSum = 0;
    for(int i=0; i<n; i++)
        totalSum += arr[i];
    
    // since s1 + s2 = totalSum => s1 = totalSum - s2
    // also s1 - s2 = d => totalSum - s2 - s2 = d
    // totalSum - 2*s2 = d  => s2 = (totalSum - d)/2
    
    if(totalSum-d < 0 || (totalSum-d) % 2)
        return false;
    
    // (totalSum-d) is >= 0 and even
    return findWays(arr, (totalSum - d)/2);
}


// Space Optimization Approach: [TC-O(N*sum) and SC-O(sum)]
int mod = 1e9+7;

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar+1, 0), curr(tar+1, 0);
    
    if(num[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    
    if(num[0] != 0 && num[0] <= tar)
        prev[num[0]] = 1;
    
    for(int ind=1; ind<n; ind++)
    {
        for(int sum=0; sum<=tar; sum++)
        {
            int notTake = prev[sum];
            int take = 0;
            if(num[ind] <= sum)
                take = prev[sum-num[ind]];

            curr[sum] = (take + notTake) % mod;
        }
        prev = curr;
    }
    return prev[tar];
}

int countPartitions(int n, int d, vector<int> &arr) 
{
    int totalSum = 0;
    for(int i=0; i<n; i++)
        totalSum += arr[i];
        
    if(totalSum-d < 0 || (totalSum-d) % 2)
        return false;

    return findWays(arr, (totalSum - d)/2);
}


