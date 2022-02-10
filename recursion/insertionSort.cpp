#include <bits/stdc++.h>
using namespace std;

void place(int arr[], int e, int key)
{
    // base case
    if(e==-1 || arr[e] <= key) {
        arr[e+1] = key;
        return;
    }
    // recursive call
    else {
        arr[e+1] = arr[e];
        place(arr, e-1, key);
    }
}

void insertionSort(int arr[], int s, int n)
{
    // base case
    if(s >= n)
        return;
    // sort left side and place key at right position
    place(arr, s, arr[s+1]);
    // recursive call
    insertionSort(arr, s+1, n);
}

int main()
{
    int arr[] = {2,6,1,7,10, 42, 21, 0, 8, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
	insertionSort(arr, 0, n-1);
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
    return 0;
}