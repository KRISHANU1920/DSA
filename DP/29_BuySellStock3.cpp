// Question Link: https://practice.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1/

// Recursive Approach: [TC- O(2^N) and SC-O(N)]
int solve(int ind, int buy, int cap, vector<int> &price)
{
    if(ind == price.size() || cap == 0)
        return 0;
    
    if(buy)
    {
        return max( -price[ind] + solve(ind+1, 0, cap, price),
                        0 + solve(ind+1, 1, cap, price));
    }
    else
    {
        return max( price[ind] + solve(ind+1, 1, cap-1, price),
                        0 + solve(ind+1, 0, cap, price));
    }
}

int maxProfit(vector<int>&price)
{
    return solve(0, 1, 2, price);
}


// Memoization Approach: [TC-O(N*2*3) and SC-(O(N*2*3)+O(N))]
int solve(int ind, int buy, int cap, vector<int> &price, vector<vector<vector<int>>> &dp)
{
    if(ind == price.size() || cap == 0)
        return 0;
    
    if(dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];
        
    if(buy)
    {
        return dp[ind][buy][cap] = max( -price[ind] + solve(ind+1, 0, cap, price, dp),
                        0 + solve(ind+1, 1, cap, price, dp));
    }
    else
    {
        return dp[ind][buy][cap] = max( price[ind] + solve(ind+1, 1, cap-1, price, dp),
                        0 + solve(ind+1, 0, cap, price, dp));
    }
}

int maxProfit(vector<int>&price)
{
    int n = price.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, -1)));
    return solve(0, 1, 2, price, dp);
}

// Tabulation Approach: [TC-O(N*2*3) and SC-O(N*2*3)]
int maxProfit(vector<int>&price)
{
    int n = price.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
    
    for(int ind=0; ind<=n; ind++)
        for(int buy=0; buy<2; buy++)
            dp[ind][buy][0] = 0;
    
    for(int buy=0; buy<2; buy++)
        for(int cap=0; cap<3; cap++)
            dp[n][buy][cap] = 0;
    
    
    for(int ind=n-1; ind>=0; ind--)
    {
        for(int buy=0; buy<2; buy++)
        {
            for(int cap=1; cap<=2; cap++)
            {
                if(buy)
                {
                    dp[ind][buy][cap] = max( -price[ind] + dp[ind+1][0][cap],
                                    0 + dp[ind+1][1][cap]);
                }
                else
                {
                    dp[ind][buy][cap] = max( price[ind] + dp[ind+1][1][cap-1],
                                    0 + dp[ind+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}

// Space Optimization Approach: [TC-O(N*2*3) and SC-O(2*3)]
int maxProfit(vector<int>&price)
{
    int n = price.size();
    vector<vector<int>> after(2, vector<int> (3, 0));
    vector<vector<int>> curr(2, vector<int> (3, 0));
    
    for(int ind=n-1; ind>=0; ind--)
    {
        for(int buy=0; buy<2; buy++)
        {
            for(int cap=1; cap<=2; cap++)
            {
                if(buy)
                {
                    curr[buy][cap] = max( -price[ind] + after[0][cap],
                                    0 + after[1][cap]);
                }
                else
                {
                    curr[buy][cap] = max( price[ind] + after[1][cap-1],
                                    0 + after[0][cap]);
                }
            }
            after = curr;
        }
    }
    return after[1][2];
}


// Array Optimization: [TC-O(N*4) and SC-O(4)]
// can also be solve in dp[N+1][4] array by using 4 transactions states
int solve(int ind, int transaction, vector<int> &price)
{
    if(ind == price.size() || transaction == 4)
        return 0;
    
    // transaction even state (0, 2) is buy state
    if(buy % 2 == 0)
    {
        return max( -price[ind] + solve(ind+1, transaction+1, price),
                        0 + solve(ind+1, transaction, price));
    }
    // transaction odd state (1, 3) is sell state
    else
    {
        return max( price[ind] + solve(ind+1, transaction+1, price),
                        0 + solve(ind+1, transaction, price));
    }
}

int maxProfit(vector<int>&price)
{
    // starting from transaction state 0
    return solve(0, 0, price);
}