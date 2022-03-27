// Question Link : https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) 
{
	deque<int> maxi(k);
    deque<int> mini(k);
    long long ans = 0;
    
    // finding max and min value of first k size window
    for(int i=0; i<k; i++)
    {
        while(!maxi.empty() && nums[maxi.back()] <= nums[i])
            maxi.pop_back();
        
        while(!mini.empty() && nums[mini.back()] >= nums[i])
            mini.pop_back();
        
        maxi.push_back(i);
        mini.push_back(i);
	}
    
    // calculating sum of max and min of first k size window
    ans += nums[maxi.front()] + nums[mini.front()];
    
    // finding max and min for remaining k size windows
    for(int i=k; i<n; i++)
    {
        // removal
        while(!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        
        while(!mini.empty() && i - mini.front() >= k)
            mini.pop_front();
        
        // addition
        while(!maxi.empty() && nums[maxi.back()] <= nums[i])
            maxi.pop_back();
        
        while(!mini.empty() && nums[mini.back()] >= nums[i])
            mini.pop_back();
        
        maxi.push_back(i);
        mini.push_back(i);
        
        // updating current window sum in ans
        ans += nums[maxi.front()] + nums[mini.front()];
	}
    
    return ans;
}


/*

Time Complexity: O(n)
Space Complexity: O(k)

*/