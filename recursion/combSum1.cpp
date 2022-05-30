// Question Link : https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std;


void solve(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if(ind == arr.size())
    {
        if(target == 0)
            ans.push_back(ds);
        return;
    }

    if(arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        solve(ind, target-arr[ind], arr, ans, ds);
        ds.pop_back();
    }

    solve(ind+1, target, arr, ans, ds);
}

int main()
{
    vector<int> arr = {2,3,4,5,6,7};
    vector<int> ds;
    vector<vector<int>> ans;
    int target = 9;

    solve(0, target, arr, ans, ds);

    for(auto i: ans)
    {
        for(auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

Time Complexity: O(2^t * k)
Space Complexity: O(k * x)

*/