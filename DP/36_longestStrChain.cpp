// Question Link: https://leetcode.com/problems/longest-string-chain/

bool static comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

bool isPossible(string &s1, string &s2)
{
    if(s1.size() != s2.size()+1)
        return false;
    
    int first = 0, second = 0;
    
    while(first < s1.size())
    {
        if(s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
            first++;
    }
    
    if(first == s1.size() && second == s2.size())
        return true;
    
    return false;
}
int longestStrChain(vector<string>& a) 
{
    int n = a.size();
    vector<int> dp(n, 1);
    int maxi = 1;

    sort(a.begin(), a.end(), comp);

    for(int ind=0; ind<n; ind++)
    {
        for(int prev=0; prev<ind; prev++)
        {
            if(isPossible(a[ind], a[prev]) && (1+dp[prev] > dp[ind]))
            {
                dp[ind] = 1 + dp[prev];
            }
        }
        maxi = max(maxi, dp[ind]);
    }
    return maxi;
}


/*

Time Complexity: O(N^2) + O(N.log(N))
Space Complexity: O(N)

*/