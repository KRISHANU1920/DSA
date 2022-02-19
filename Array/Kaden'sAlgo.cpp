// Question Link : https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

long long maxSubarraySum(int arr[], int n)
{
    int maxSum = INT_MIN, currSum = 0;
    for(int i=0; i<n; i++)
    {
        if(currSum < 0)
            currSum = 0;
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/