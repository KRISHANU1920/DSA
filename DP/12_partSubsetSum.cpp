// Question Link: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

// Space Optimization Approach: [TC-O(N*sum)+O(N) and SC-O(sum)]
bool isSubsetSum(int arr[], int n, int sum)
{
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

int equalPartition(int N, int arr[])
{
    int sum = 0;
    for(int i=0; i<N; i++)
        sum += arr[i];
    
    if(sum % 2)
        return 0;
    
    else
        return isSubsetSum(arr, N, sum/2);
        
}