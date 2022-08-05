// Question Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

// Recursive Approach: [TC- Exponential and SC-O(N)]
int solve(int i, int j, vector<int>& cuts)
{
    if(i > j)
        return 0;
    
    int mini = INT_MAX;
    for(int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j+1] - cuts[i-1] + solve(i, ind-1, cuts) + solve(ind+1, j, cuts);
        mini = min(mini, cost);
    }
    return mini;
}

int minCost(int n, vector<int>& cuts) 
{
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    
    return solve(1, c, cuts);
}


// Memoization Approach: [TC-O(N^3) and SC-(O(N^2)+O(N))]
int solve(int i, int j, vector<int>& cuts, vector<vector<int>> &dp)
{
    if(i > j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int mini = INT_MAX;
    for(int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j+1] - cuts[i-1] + solve(i, ind-1, cuts, dp) + solve(ind+1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

int minCost(int n, vector<int>& cuts) 
{
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    
    vector<vector<int>> dp(c+1, vector<int> (c+1, -1));
    
    return solve(1, c, cuts, dp);
}


// Tabulation Approach: [TC-O(N^3) and SC-O(N^2)]
int minCost(int n, vector<int>& cuts) 
{
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    
    vector<vector<int>> dp(c+2, vector<int> (c+2, 0));
    
    for(int i=c; i>=1; i--)
    {
        for(int j=1; j<=c; j++)
        {
            if(i > j)
                continue;
            
            int mini = INT_MAX;
            for(int ind = i; ind <= j; ind++)
            {
                int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}