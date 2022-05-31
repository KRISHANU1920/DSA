// Question Link : https://leetcode.com/problems/permutations/


// Approach 1: optimized [TC-O(N! * N) and SC-O(N!)]
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



// Approach 2: using mapping  [TC-O(N! * N) and SC-O(N)]
void solve(vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int freq[])
{
    if(ds.size() == arr.size())
    {
        ans.push_back(ds);
        return ;
    }
    
    for(int i=0; i<arr.size(); i++)
    {
        if(!freq[i])
        {
            ds.push_back(arr[i]);
            freq[i] = 1;
            
            solve(arr, ds, ans, freq);
            
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()];
    
    for(int i=0; i<nums.size(); i++)
        freq[i] = 0;
    
    solve(nums, ds, ans, freq);
    return ans;
}

