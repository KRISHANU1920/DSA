// Question Link : https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/#

#include <bits/stdc++.h>
#define lld long long int
using namespace std;

lld merge(lld arr[], lld left, lld mid, lld right)
{
    lld len1 = mid-left+1;
    lld len2 = right-mid;
    lld i, inv_count = 0;
    
    // create temp arrays
    lld *first = new lld [len1];
    lld *second = new lld [len2];

    // copy values to temp arrays
    lld mainInd = left;
    for(i=0; i<len1; i++)
        first[i] = arr[mainInd++];
    mainInd = mid+1;
    for(i=0; i<len2; i++)
        second[i] = arr[mainInd++];

    // merge two sorted arrays
    mainInd = left;
    lld ind1=0, ind2=0;
    while(ind1<len1 && ind2<len2)
    {
        if(first[ind1] <= second[ind2])
            arr[mainInd++] = first[ind1++];
        else {
            arr[mainInd++] = second[ind2++];
            // inversions counting
            inv_count += (len1-ind1);
        }
    }
    while(ind1 < len1)
        arr[mainInd++] = first[ind1++];
    while(ind2 < len2)
        arr[mainInd++] = second[ind2++];
    
    delete [] first;
    delete [] second;
    
    return inv_count;
}

lld mergeSort(long long arr[], lld left, lld right)
{
    // inversion count variable
    lld inv_count = 0;
    if(left < right)
    {
        lld mid = left + (right - left)/2;
        // Sorting left side of array
        inv_count += mergeSort(arr, left, mid);
        // Sorting right side of array
        inv_count += mergeSort(arr, mid+1, right);
    
        // merging 
        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}
lld inversionCount(long long arr[], long long N)
{
    return mergeSort(arr, 0, N-1);
}

int main()
{
    lld arr[] = {2,6,1,5,4,3,7};
    lld n = sizeof(arr)/sizeof(arr[0]);
	cout << inversionCount(arr, n);
	cout << endl;
    return 0;
}

/*

Time Complexity: O(Nlog(N))
Space Complexity: O(N)

*/