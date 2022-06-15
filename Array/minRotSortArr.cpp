// Question Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

int findMin(vector<int>& nums) 
{
    int left = 0, right = size(nums)-1;
    
    while(left < right)
    {
        int mid = left + (right - left)/2;
        
        if(nums[mid] < nums[right])
            right = mid;
        else
            left = mid+1;
    }
    
    return nums[left];
}

/*

Time Complexity: O(logN)
Space Complexity: O(1)

*/