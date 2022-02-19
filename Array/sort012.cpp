// Question Link :https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

void sort012(int a[], int n)
{
    int start = 0, mid = 0;
    int end = n - 1;
    while( mid <= end)
    {
        if(a[mid] == 0)
            swap(a[start++], a[mid++]);
        else if(a[mid] == 2)
            swap(a[mid], a[end--]);
        else
            mid++;
    }
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/