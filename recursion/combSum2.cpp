// Question Link : https://leetcode.com/problems/combination-sum-ii/

void solve(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if(target == 0)
    {
        ans.push_back(ds);
        return;
    }
    
    for(int i=ind; i<arr.size(); i++)
    {
        // remove duplicate element
        if(i>ind && arr[i] == arr[i-1])
            continue;
        
        // optimization
        if(arr[i] > target)
            break;
        
        ds.push_back(arr[i]);
        solve(i+1, target-arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    vector<vector<int>> ans;
    vector<int> ds;
    
    sort(candidates.begin(), candidates.end());
    solve(0, target, candidates, ans, ds);
    return ans;
}

/*

Time Complexity: O(2^t * k)
Space Complexity: O(k * x)

*/