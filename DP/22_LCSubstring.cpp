// Question Link: https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1/

// Tabulation Approach: [TC-O(N*M) and SC-O(N*M)]
int longestCommonSubstr (string S1, string S2, int n, int m)
{
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            // match
            if(S1[i-1] == S2[j-1]) 
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            
            // not match
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}



// Space Optimization Approach: [TC-O(N*M) and SC-O(M)]
int longestCommonSubstr (string S1, string S2, int n, int m)
{
    vector<int> prev(m+1, 0), curr(m+1, 0);
    
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            // match
            if(S1[i-1] == S2[j-1]) 
            {
                curr[j] = 1 + prev[j-1];
                ans = max(ans, curr[j]);
            }
            
            // not match
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
}