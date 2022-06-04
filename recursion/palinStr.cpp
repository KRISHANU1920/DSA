// Question Link : https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1/

void solve(int index, string S, vector<string> &path, vector<vector<string>> &ans)
{
    if(index == S.size())
    {
        ans.push_back(path);
        return ;
    }
    
    for(int i=index; i<S.size(); i++)
    {
        if(isPalindrome(S, index, i) == true)
        {
            path.push_back(S.substr(index, i - index + 1));
            solve(i+1, S, path, ans);
            path.pop_back();  // backtracking
        }
    }
}

bool isPalindrome(string S, int start, int end)
{
    while(start <= end)
    {
        if(S[start++] != S[end--])
            return false;
    }
    return true;
}

vector<vector<string>> allPalindromicPerms(string S) {
    vector<vector<string>> ans;
    vector<string> path;
    
    solve(0, S, path, ans);
    
    return ans;
}

/*

Time Complexity: O(N*(2^N))
Space Complexity: O(N^2)

*/