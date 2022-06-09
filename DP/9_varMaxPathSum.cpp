// Recursive Approach: [TC-O((3^N)*M)) and SC-O(N)]
int solve(int i, int j, vector<vector<int>> &matrix)
{
    if(j<0 || j>=matrix[0].size())
        return -1e9;
    
    if(i == 0)
        return matrix[0][j];
    
    int up = matrix[i][j] + solve(i-1, j, matrix);
    int ld = matrix[i][j] + solve(i-1, j-1, matrix);
    int rd = matrix[i][j] + solve(i-1, j+1, matrix);
    
    return max(up, max(ld, rd));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    int maxi = -1e9;
    for(int j=0; j<m; j++)
        maxi = max(maxi, solve(n-1, j, matrix));
    
    return maxi;
}


// Memoization Approach: [TC-O(N*M) and SC- O(N) + O(N*M)]
int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if(j<0 || j>=matrix[0].size())
        return -1e9;
    
    if(i == 0)
        return matrix[0][j];
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int up = matrix[i][j] + solve(i-1, j, matrix, dp);
    int ld = matrix[i][j] + solve(i-1, j-1, matrix, dp);
    int rd = matrix[i][j] + solve(i-1, j+1, matrix, dp);
    
    return dp[i][j] = max(up, max(ld, rd));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    
    int maxi = -1e9;
    for(int j=0; j<m; j++)
        maxi = max(maxi, solve(n-1, j, matrix, dp));
    
    return maxi;
}

// Tabulation Approach: [TC-O(N*M)+ O(M) and SC-O(N*M)]
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    
    for(int j=0; j<m; j++)
        dp[0][j] = matrix[0][j];
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int up = matrix[i][j] + dp[i-1][j];
            
            int ld = matrix[i][j];
            if(j>0) ld += dp[i-1][j-1];
            else ld += -1e9;
            
            int rd = matrix[i][j];
            if(j<m-1) rd += dp[i-1][j+1];
            else rd += -1e9;
            
            dp[i][j] = max(up, max(ld, rd));
        }
    }
    
    int maxi = -1e9;
    for(int j=0; j<m; j++)
        maxi = max(maxi, dp[n-1][j]);
    
    return maxi;
}



// Space Optimization Approach: [TC-O(N*M)+O(M) and SC-O(M)]
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m, 0), curr(m, 0);
    
    for(int j=0; j<m; j++)
        prev[j] = matrix[0][j];
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int up = matrix[i][j] + prev[j];
            
            int ld = matrix[i][j];
            if(j>0) ld += prev[j-1];
            else ld += -1e9;
            
            int rd = matrix[i][j];
            if(j<m-1) rd += prev[j+1];
            else rd += -1e9;
            
            curr[j] = max(up, max(ld, rd));
        }
        prev = curr;
    }
    
    int maxi = -1e9;
    for(int j=0; j<m; j++)
        maxi = max(maxi, prev[j]);
    
    return maxi;
}