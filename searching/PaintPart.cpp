// Question Link : https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

class Solution
{
  public:
    bool isPossible(int arr[], int n, int k, long mid)
    {
        long sum = 0;
        int count = 1;
        for(int i=0; i<n; i++)
        {
            if(sum + arr[i] <= mid)
                sum += arr[i];
            else {
                count++;
                if(count > k || arr[i] > mid)
                    return false;
                sum = arr[i];
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        long l = 0, r = 0;
        long long res;
        for(int i=0; i<n; i++)
            r += arr[i];
        while(l <= r)
        {
            long mid = l + (r - l)/2;
            if(isPossible(arr, n, k, mid)) {
                res = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return res;
    }
};

/*

Time Complexity: O(Nlog(N))
Space Complexity: O(1)

*/