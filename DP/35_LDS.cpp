// Question Link: https://leetcode.com/problems/largest-divisible-subset/

vector<int> largestDivisibleSubset(vector<int>& a) 
{
    int n = a.size();
    vector<int> dp(n, 1), hash(n, 0);
    int maxi = 1, lastInd = 0;
    
    sort(a.begin(), a.end());
    
    for(int ind=0; ind<n; ind++)
    {
        hash[ind] = ind;
        for(int prev=0; prev<ind; prev++)
        {
            if((a[ind] % a[prev] == 0) && (1+dp[prev] > dp[ind]))
            {
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
        if(maxi < dp[ind])
        {
            maxi = dp[ind];
            lastInd = ind;
        }
    }

    vector<int> ans;
    ans.push_back(a[lastInd]);

    while(hash[lastInd] != lastInd)
    {
        lastInd = hash[lastInd];
        ans.push_back(a[lastInd]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


/*

Time Complexity: O(N^2) + O(N)
Space Complexity: O(N)

*/