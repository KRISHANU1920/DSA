// Question Link : https://leetcode.com/problems/two-sum/

// Brute Force Approach: [TC-O(N^2) and SC-O(1)]
vector<int> twoSum(vector<int>& nums, int target) 
{        
    for(int i=0; i<nums.size()-1; i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            if(nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {};
}



// Optimized Approach using Hashmaps: [TC-O(N) and SC-O(N)]
vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<int> ans(2, -1);
    unordered_map<int, int> mp;
    
    for(int i=0; i<nums.size(); i++)
    {
        if(mp.find(target-nums[i]) != mp.end())
        {
            ans[0] = mp[target - nums[i]];
            ans[1] = i;
            return ans;
        }
        else
            mp[nums[i]] = i;
    }
    return ans;
}