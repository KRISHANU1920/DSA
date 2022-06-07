// Recursive Approach: [TC-O(2^N) and SC-O(N)]
int fibo(int n)
{
    if(n <= 1)
        return n;
    
    return fibo(n-1) + fibo(n-2);
}

int main()
{
    int n;
    cin >> n;

    cout << fibo(n);
}


// Memoization Approach: [TC-O(N) and SC-(O(N)+O(N))]
int fibo(int n, vector<int> &dp)
{
    if(n <= 1)
        return n;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
}

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n+1, -1);
    cout << fibo(n, dp);
    
    return 0;
}


// Tabulation Approach: [TC-O(N) and SC-O(N)]
int main()
{
    int n;
    cin >> n;

    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    cout << dp[n];
    return 0;
}


// Space Optimization Approach: [TC-O(N) and SC-O(1)]
int main()
{
    int n;
    cin >> n;

    int prev1 = 1;
    int prev2 = 0;

    for(int i=2; i<=n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1;
    return 0;
}