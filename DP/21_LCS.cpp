// Question Link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

// Recursive Approach: [TC- >> O(2^N * 2^M) ~ Exponential and SC-O(N+M)]
int solve(int i, int j, string &s1, string &s2)
{
    if(i<0 || j<0)
        return 0;
    
    // match
    if(s1[i] == s2[j])
        return 1 + solve(i-1, j-1, s1, s2);
        
    // not match
    return max(solve(i-1, j, s1, s2), solve(i, j-1, s1, s2));
}

int lcs(int N, int M, string s1, string s2)
{
    return solve(N-1, M-1, s1, s2);
}


// Memoization Approach: [TC-O(N*M) and SC-(O(N*M)+O(N+M))]
int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if(i==0 || j==0)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
        
    // match
    if(s1[i-1] == s2[j-1])
        return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);
        
    // not match
    return dp[i][j] = max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));
}

int lcs(int N, int M, string s1, string s2)
{
    vector<vector<int>> dp(N+1, vector<int> (M+1, -1));
    return solve(N, M, s1, s2, dp);
}

// Note: The indexes in the above approach have been right shifted by 1 index.
//        Because tabulation approach cant be made using -1 indexing.




// Tabulation Approach: [TC-O(N*M) and SC-O(N*M)]
int lcs(int N, int M, string s1, string s2)
{
    vector<vector<int>> dp(N+1, vector<int> (M+1, 0));
    
    // below lines are not needed because vector is by default initialized by 0.
    // for(int j=0; j<=M; j++)
    //     dp[0][j] = 0;
    //                              
    // for(int i=0; i<=N; i++)   
    //     dp[i][0] = 0;
        
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            // match
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
                
            // not match
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[N][M];
}


// Space Optimization Approach: [TC-O(N*M) and SC-O(M)]
int lcs(int N, int M, string s1, string s2)
{
    vector<int> prev(M+1, 0), curr(M+1, 0);
        
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            // match
            if(s1[i-1] == s2[j-1])
                curr[j] = 1 + prev[j-1];
                
            // not match
            else
                curr[j] = max(prev[j], curr[j-1]);
        }
        prev = curr;
    }
    return prev[M];
}



// Printing the LCS  [TC-O(N*M)+O(N+M)backtracking  and SC-O(N*M)+O(len)]
// extra code for Tabulation approach
string ans = "";
int len = dp[N][M];

for(int i=0; i<len; i++)
    ans += '$';

int index = len-1;
int i=N, j=M;
while(i>0 && j>0)
{
    if(s1[i-1] == s2[j-1])
    {
        ans[index] = s1[i-1];
        index--;
        i--;
        j--;
    }
    else if(dp[i-1][j] > dp[i][j-1])
        i--;
    else
        j--;
}
return ans;



// Variation 1: Longest Palindromic Subsequence
// Question link: https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1/
int longestPalinSubseq(string A) 
{
    string B = A;
    reverse(B.begin(), B.end());
    int N = A.size();
    
    return lcs(N, N, A, B);
}


// Variation 2: Minimum Insertions needed to make string palindrome
// Question Link: https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1/
int countMin(string str)
{
    int n = str.size();
    return n - longestPalinSubseq(str);
}


// Variation 3: Minimum insertions/deletions to convert str a to b
// Question Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1/
int minOperations(string str1, string str2) 
{ 
    int N = str1.size();
    int M = str2.size();
    
    // ans = (N - lcs) + (M - lcs)
    return N + M - (2 * lcs(N, M, str1, str2));
}