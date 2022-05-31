// Question Link : https://leetcode.com/problems/subsets-ii/

void solve(int ind, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    
    for(int i=ind; i<arr.size(); i++)
    {
        if(i>ind && arr[i]==arr[i-1])
            continue;
        
        ds.push_back(arr[i]);
        solve(i+1, arr, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    solve(0, nums, ds, ans);
    return ans;
}

/*

Time Complexity: O(2^N * N) [2^N for generating all subsets and N for adding subset in ans]
Space Complexity: O(2^N * K) [ K is average length of subset]
Auxillary Space: O(N) [depth of recursion]

*/