// Merge sort using temporary arrays

#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int left, int mid, int right)
{
    int len1 = mid-left+1;
    int len2 = right-mid;

    // create temp arrays
    int *first = new int [len1];
    int *second = new int [len2];

    // copy values to temp arrays
    int mainInd = left;
    for(int i=0; i<len1; i++)
        first[i] = arr[mainInd++];
    mainInd = mid+1;
    for(int i=0; i<len2; i++)
        second[i] = arr[mainInd++];

    // merge two sorted arrays
    mainInd = left;
    int ind1=0, ind2=0;
    while(ind1<len1 && ind2<len2)
    {
        if(first[ind1] < second[ind2])
            arr[mainInd++] = first[ind1++];
        else
            arr[mainInd++] = second[ind2++];
    }
    while(ind1 < len1)
        arr[mainInd++] = first[ind1++];
    while(ind2 < len2)
        arr[mainInd++] = second[ind2++];
    
    delete [] first;
    delete [] second;
}

void mergeSort(int *arr, int left, int right)
{
    // base case
    if(left >= right)
        return;

    int mid = left + (right - left)/2;
    // Sorting left side of array
    mergeSort(arr, left, mid);
    // Sorting right side of array
    mergeSort(arr, mid+1, right);

    // merging 
    merge(arr, left, mid, right);
}

int main()
{
    int arr[] = {2,6,1,5,4,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);
	mergeSort(arr, 0, n-1);
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
    return 0;
}

/*

Time Complexity: O(Nlog(N))
Space Complexity: O(N)

*/