// Question Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/

int findNumberOfLIS(vector<int>& a) 
{
    int n = a.size();
    vector<int> dp(n, 1), cnt(n, 1);
    int maxi = 1;

    for(int ind=0; ind<n; ind++)
    {
        for(int prev=0; prev<ind; prev++)
        {
            if(a[prev] < a[ind] && (1+dp[prev] > dp[ind]))
            {
                dp[ind] =  1 + dp[prev];
                cnt[ind] = cnt[prev];
            }
            else if(a[prev] < a[ind] && (1+dp[prev] == dp[ind]))
                cnt[ind] += cnt[prev];
        }
        maxi = max(maxi, dp[ind]);
    }
    
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(maxi == dp[i])
            ans += cnt[i];
    }
    return ans;
}


/*

Time Complexity: O(N*N)
Space Complexity: O(2*N)

*/