// Question Link: https://practice.geeksforgeeks.org/problems/maximum-profit4657/1/

// Previous Method
// space optimization approach: [TC-O(N*2*K) ans SC-O(2*K)]
int maxProfit(int K, int N, int A[]) 
{
    vector<vector<int>> after(2, vector<int> (K+1, 0));
    vector<vector<int>> curr(2, vector<int> (K+1, 0));
    
    for(int ind=N-1; ind>=0; ind--)
    {
        for(int buy=0; buy<2; buy++)
        {
            for(int cap=1; cap<=K; cap++)
            {
                if(buy)
                {
                    curr[buy][cap] = max( -A[ind] + after[0][cap],
                                    0 + after[1][cap]);
                }
                else
                {
                    curr[buy][cap] = max( A[ind] + after[1][cap-1],
                                    0 + after[0][cap]);
                }
            }
            after = curr;
        }
    }
    return after[1][K];
}



// Transaction Method
// Recursive Approach: [TC- O(2^N) and SC-O(N)]
int solve(int ind, int transaction, int K, vector<int> &price)
{
    if(ind == price.size() || transaction == 2*K)
        return 0;

    // transaction even state (0, 2) is buy state
    if(transaction % 2 == 0)
    {
        return max( -price[ind] + solve(ind+1, transaction+1, K, price),
                        0 + solve(ind+1, transaction, K, price));
    }
    // transaction odd state (1, 3) is sell state
    else
    {
        return max( price[ind] + solve(ind+1, transaction+1, K, price),
                        0 + solve(ind+1, transaction, K, price));
    }
}

int maxProfit(int k, vector<int>& prices) 
{
    return solve(0, 0, k, prices);
}


// Memoization Approach: [TC-O(N*K) and SC-(O(N*K)+O(N))]
int solve(int ind, int transaction, int K, vector<int> &price, vector<vector<int>> &dp)
{
    if(ind == price.size() || transaction == 2*K)
        return 0;
    
    if(dp[ind][transaction] != -1)
        return dp[ind][transaction];

    if(transaction % 2 == 0)
    {
        return dp[ind][transaction] = max( -price[ind] + solve(ind+1, transaction+1, K, price, dp),
                        0 + solve(ind+1, transaction, K, price, dp));
    }
    else
    {
        return dp[ind][transaction] = max( price[ind] + solve(ind+1, transaction+1, K, price, dp),
                        0 + solve(ind+1, transaction, K, price, dp));
    }
}

int maxProfit(int k, vector<int>& prices) 
{
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int> (2*k, -1));
    return solve(0, 0, k, prices, dp);
}


// Tabulation Approach: [TC-O(N*K) and SC-O(N*K)]
int maxProfit(int k, vector<int>& price) 
{
    int n = price.size();
    vector<vector<int>> dp(n+1, vector<int> (2*k+1, 0));
    
    for(int ind=n-1; ind>=0; ind--)
    {
        for(int transaction=2*k-1; transaction>=0; transaction--)
        {
                if(transaction % 2 == 0)
            {
                dp[ind][transaction] = max( -price[ind] + dp[ind+1][transaction+1],
                                0 + dp[ind+1][transaction]);
            }
            else
            {
                dp[ind][transaction] = max( price[ind] + dp[ind+1][transaction+1],
                                0 + dp[ind+1][transaction]);
            }
        }
    }
    return dp[0][0];
}


// Space Optimization Approach: [TC-O(N*K) and SC-O(2*K)]
int maxProfit(int k, vector<int>& price) 
{
    int n = price.size();
    vector<int> after(2*k+1, 0), curr(2*k+1, 0);
    
    for(int ind=n-1; ind>=0; ind--)
    {
        for(int transaction=2*k-1; transaction>=0; transaction--)
        {
                if(transaction % 2 == 0)
            {
                curr[transaction] = max( -price[ind] + after[transaction+1],
                                0 + after[transaction]);
            }
            else
            {
                curr[transaction] = max( price[ind] + after[transaction+1],
                                0 + after[transaction]);
            }
        }
        after = curr;
    }
    return after[0];
}