// Question Link : https://leetcode.com/problems/permutations/

void solve(string S, int index, vector<string>& ans)
{
    // base case
    if(index >= S.size()) {
        ans.push_back(S);
        return ;
    }
    for(int j=index; j<S.size(); j++)
    {
        swap(S[index], S[j]);
        solve(S, index+1, ans);
        swap(S[index], S[j]); // backtrack
    }
}

vector<string>find_permutation(string S)
{
    vector<string> ans;
    int index = 0;
    solve(S, index, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
