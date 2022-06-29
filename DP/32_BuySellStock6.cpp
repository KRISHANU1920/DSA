// Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// Tabulation Approach: [TC-O(N*2) and SC-O(N*2)]
int maxProfit(vector<int>& prices, int fee) 
{
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int> (2, 0));

    for(int ind=n-1; ind>=0; ind--)
    {
        for(int buy=0; buy<=1; buy++)
        {
            // fee can be charged at buy or sell
            if(buy)
            {
                dp[ind][buy] = max( -prices[ind] + dp[ind+1][0],
                                0 + dp[ind+1][1]);
            }
            else
            {
                dp[ind][buy] = max( prices[ind] - fee + dp[ind+1][1],
                                0 + dp[ind+1][0]);
            }
        }
    }
    return dp[0][1];
}

// Space Optimization: [TC-O(N) and SC-O(4)]
int maxProfit(vector<int>& prices, int fee) 
{
    int n = prices.size();
    vector<int> after(2, 0), curr(2, 0);

    for(int ind=n-1; ind>=0; ind--)
    {
        // fee can be charged at buy or sell
        curr[1] = max( -prices[ind] + after[0],
                            0 + after[1]);

        curr[0] = max( prices[ind] - fee + after[1],
                            0 + after[0]);
        
        after = curr;
    }
    return after[1];
}