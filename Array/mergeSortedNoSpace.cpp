// Question Link :https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

void merge(int arr1[], int arr2[], int n, int m)
{
    int i = n - 1, j = 0;
    while(i>=0 && j<m)
    {
        if(arr1[i] > arr2[j])
            swap(arr1[i], arr2[j]);
        i--;
        j++;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

/*

Time Complexity: O((n+m)*log(n+m))
Space Complexity: O(1)

*/