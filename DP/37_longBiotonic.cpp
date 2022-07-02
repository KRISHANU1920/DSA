// Question Link: https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1/#

int LongestBitonicSequence(vector<int> a)
{
    int n = a.size();
    
    // calculating LIS dp1 array from left to right
    vector<int> dp1(n, 1);
    for(int ind=0; ind<n; ind++)
    {
        for(int prev=0; prev<ind; prev++)
        {
            if(a[prev] < a[ind] && (1+dp1[prev] > dp1[ind]))
            {
                dp1[ind] = 1 + dp1[prev];
            }
        }
    }
    
    // calculating LIS dp2 array from right to left
    vector<int> dp2(n, 1);
    for(int ind=n-1; ind>=0; ind--)
    {
        for(int prev=n-1; prev>ind; prev--)
        {
            if(a[prev] < a[ind] && (1+dp2[prev] > dp2[ind]))
            {
                dp2[ind] = 1 + dp2[prev];
            }
        }
    }
    
    // calulating biotonic subsequence by combining dp1 & dp2
    int maxi = 1;
    for(int i=0; i<n; i++)
    {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
}


/*

Time Complexity: O(N^2)
Space Compexity: O(2*N)

*/