// Question Link : https://leetcode.com/problems/search-in-rotated-sorted-array/

int findPivot(vector<int>& nums, int n)
{
    int s=0, e=n-1;
    while(s<e)
    {
        int mid = s + (e - s)/2;
        if(nums[0] <= nums[mid])
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

int binary_search(vector<int>& nums, int s, int e, int target)
{
    while(s<=e)
    {
        int mid = s + (e - s)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    
    int n = nums.size();
    int pivot = findPivot(nums, n);
    if(target >= nums[pivot] && target <= nums[n-1])
        return binary_search(nums, pivot, n-1, target);
    else
        return binary_search(nums, 0, pivot-1, target);
}

/*

Time Complexity: O(logN)
Space Complexity: O(1)

*/