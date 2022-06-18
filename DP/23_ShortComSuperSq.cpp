// Question Link: https://www.geeksforgeeks.org/print-shortest-common-supersequence/

int shortestCommonSupersequence(string X, string Y, int m, int n)
{
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    
    // LCS Tabulation Code
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    // this returns the length of the Shortest Common SuperSequence
    return m + n - dp[m][n];


    // printing the Shortest Common SuperSequence
    string ans = "";
    int i = m, j = n;

    while(i > 0 && j > 0)
    {
        if(X[i-1] == Y[j-1])
        {
            ans += X[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            ans += X[i-1];
            i--;
        }
        else
        {
            ans += Y[j-1];
            j--;
        }
    }

    while(i > 0)
    {
        ans += X[i-1];
        i--;
    }

    while(j > 0)
    {
        ans += Y[j-1];
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}