// Question Link : https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution 
{
    public:
    int isPossible(int A[], int N, int M, int mid)
    {
        int pageSum=0, studentCount=1;
        for(int i=0; i<N; i++)
        {
            if(pageSum + A[i] <= mid)
                pageSum += A[i];
            else
            {
                studentCount++;
                if(studentCount > M || A[i] > mid)
                    return false;
                pageSum = A[i];
            }
        }
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        int s = 0, e = 0, result = -1;
        for(int i=0; i<N; i++)
            e += A[i];
        while(s <= e)
        {
            int mid = s + (e - s)/2;
            if(isPossible(A, N, M, mid))
            {
                result = mid;
                e = mid - 1;
            }
            else
                 s = mid + 1;
        }
        return result;
    }
};

/*

Time Complexity: O(Nlog(N))
Space Complexity: O(1)

*/