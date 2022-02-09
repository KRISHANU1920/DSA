#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s], count = 0;
    for(int i=s+1; i<=e; i++)
        if(arr[i] <= arr[s])
            count++;
    // place pivot to right position
    int pivotIndex = s + count;
    swap(arr[s], arr[s+count]);

    int i=s, j=e;
    while(i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if(s >= e)
        return;
    
    // partition call
    int p = partition(arr, s, e);
    
    // recursive call for left part
    quickSort(arr, s, p-1);
    // recursive call for right part
    quickSort(arr, p+1, e);
}

int main()
{
    int arr[] = {2,6,1,5,4,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, n-1);
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
    return 0;
}

/*

Time Complexity:
    Best Case - O(Nlog(N))
    Average Case - O(Nlog(N))
    Worst Case - O(N^2)

Space Complexity: O(N)

*/


// shorter version of partition function
int partition(int arr[], int s, int e)
{
    int i = s-1, pivot = arr[e];
    for(int j=s; j<e; j++)
    {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // place pivot element to correct postion
    swap(arr[i+1], arr[e]);
    // return pivotIndex
    return i+1;
}