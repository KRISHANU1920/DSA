// Question Link: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/

// Tabulation Approach: [TC-O(N*totalSum)+O(totalSum/2)+O(N) and SC-O(N*totalSum)]
int minDifference(int arr[], int n)  
{ 
    int totalSum = 0;
    
    for(int i=0; i<n; i++)
        totalSum += arr[i];

    // Subset Sum code
    vector<vector<bool>> dp(n, vector<bool> (totalSum+1, 0));
    
    for(int ind=0; ind<n; ind++)
        dp[ind][0] = true;
    
    if(arr[0] <= totalSum)  
        dp[0][arr[0]] = true;
    
    for(int ind=1; ind<n; ind++)
    {
        for(int target=1; target<=totalSum; target++)
        {
            bool notPick = dp[ind-1][target];
            bool pick = false;
            if(target >= arr[ind])
                pick = dp[ind-1][target-arr[ind]];
            
            dp[ind][target] = pick | notPick;
        }
    }
    
    // Minimum possible partition code
    int mini = 1e9;
    for(int s1=0; s1<=totalSum/2; s1++)
    {
        if(dp[n-1][s1] == true)
        {
            mini = min(mini, abs((totalSum-s1)-s1));
        }
    }
    return mini;
}


// Space Optimization Approach: [TC-O(N*totalSum)+O(totalSum/2)+O(N) and SC-O(totalSum)]
int minDifference(int arr[], int n)  
{ 
    int totalSum = 0;
    
    for(int i=0; i<n; i++)
        totalSum += arr[i];

    // Subset Sum code
    vector<bool> prev(totalSum+1, 0), curr(totalSum+1, 0);
    
    prev[0] = curr[0] = true;
    
    if(arr[0] <= totalSum)
        prev[arr[0]] = true;
    
    for(int ind=1; ind<n; ind++)
    {
        for(int target=1; target<=totalSum; target++)
        {
            bool notPick = prev[target];
            bool pick = false;
            if(target >= arr[ind])
                pick = prev[target-arr[ind]];
            
            curr[target] = pick | notPick;
        }
        prev = curr;
    }
    
    // Minimum possible partition code
    int mini = 1e9;
    for(int s1=0; s1<=totalSum/2; s1++)
    {
        if(prev[s1] == true)
        {
            mini = min(mini, abs((totalSum-s1)-s1));
        }
    }
    return mini;
} 