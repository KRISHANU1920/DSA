// Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Recursive Approach: [TC- O(2^N) and SC-O(N)]
int solve(int ind, int buy, vector<int> &prices)
{
    if(ind == prices.size())
        return 0;
    
    int profit = 0;
    if(buy)
    {
        profit = max( -prices[ind] + solve(ind+1, 0, prices),
                        0 + solve(ind+1, 1, prices));
    }
    else
    {
        profit = max( prices[ind] + solve(ind+1, 1, prices),
                        0 + solve(ind+1, 0, prices));
    }
    return profit;
}

int maxProfit(vector<int>& prices) 
{
    return solve(0, 1, prices);
}


// Memoization Approach: [TC-O(N*2) and SC-(O(N*2)+O(N))]
int solve(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if(ind == prices.size())
        return 0;
    
    if(dp[ind][buy] != -1)
        return dp[ind][buy];
    
    int profit = 0;
    if(buy)
    {
        profit = max( -prices[ind] + solve(ind+1, 0, prices, dp),
                        0 + solve(ind+1, 1, prices, dp));
    }
    else
    {
        profit = max( prices[ind] + solve(ind+1, 1, prices, dp),
                        0 + solve(ind+1, 0, prices, dp));
    }
    return dp[ind][buy] = profit;
}

int maxProfit(vector<int>& prices) 
{
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int> (2, -1));
    return solve(0, 1, prices, dp);
}


// Tabulation Approach: [TC-O(M*N) and SC-O(M*N)]
int maxProfit(vector<int>& prices) 
{
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int> (2, 0));
    
    dp[n][0] = dp[n][1] = 0;
    
    for(int ind=n-1; ind>=0; ind--)
    {
        for(int buy=0; buy<=1; buy++)
        {
            int profit = 0;
            if(buy)
            {
                profit = max( -prices[ind] + dp[ind+1][0],
                                0 + dp[ind+1][1]);
            }
            else
            {
                profit = max( prices[ind] + dp[ind+1][1],
                                0 + dp[ind+1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

// Space Optimization Approach: [TC-O(N*2) and SC-O(4)]
int maxProfit(vector<int>& prices) 
{
    int n = prices.size();
    vector<int> ahead(2, 0), curr(2, 0);
    
    for(int ind=n-1; ind>=0; ind--)
    {
        for(int buy=0; buy<=1; buy++)
        {
            int profit = 0;
            if(buy)
            {
                profit = max( -prices[ind] + ahead[0], 0 + ahead[1]);
            }
            else
            {
                profit = max( prices[ind] + ahead[1], 0 + ahead[0]);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
}


// Variables Optimization: [TC-O(N) and SC-O(4)]
int maxProfit(vector<int>& prices) 
{
    int n = prices.size();
    int aheadBuy, aheadNotBuy, currBuy, currNotBuy;
    aheadBuy = aheadNotBuy = 0;
    
    for(int ind=n-1; ind>=0; ind--)
    {
        currBuy = max( -prices[ind] + aheadNotBuy, 0 + aheadBuy);
        currNotBuy = max( prices[ind] + aheadBuy, 0 + aheadNotBuy);
        
        aheadBuy = currBuy;
        aheadNotBuy = currNotBuy;
    }
    return aheadBuy;
}