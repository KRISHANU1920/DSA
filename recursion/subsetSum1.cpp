// Question Link : https://practice.geeksforgeeks.org/problems/subset-sums2234/1

void solve(int ind, vector<int> &arr, vector<int> &ans, int sum)
{
    if(ind == arr.size())
    {
        ans.push_back(sum);
        return ;
    }
    
    // picking the element
    solve(ind+1, arr, ans, sum+arr[ind]);
    
    // not picking the element
    solve(ind+1, arr, ans, sum);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ans;
    solve(0, arr, ans, 0);
    
    sort(ans.begin(), ans.end());
    return ans;
}

/*

Time Complexity: O(2^N * log(2^N))
Space Complexity: O(2^N)

*/