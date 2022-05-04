// Question Link : https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

ll findSubarray(vector<ll> arr, int n ) 
{
    unordered_map<ll, ll> ump;
    
    ll presum = 0;
    ll ans = 0;
    ump[presum] = 1;
    
    for(auto x: arr)
    {
        presum += x;
        
        if(ump.find(presum) != ump.end())
            ans += ump[presum];
        
        ump[presum]++;
    }
    return ans;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/