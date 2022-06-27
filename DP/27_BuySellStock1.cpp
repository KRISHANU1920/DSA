// Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(vector<int>& prices) 
{
    int n = prices.size();
    int mini = prices[0];
    int maxProfit = 0;
    
    for(int i=1; i<n; i++)
    {
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);            
    }
    return maxProfit;
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/