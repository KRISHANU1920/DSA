// Bubble Sort Using Recursion
#include <bits/stdc++.h>
using namespace std;

void round(int arr[], int i, int n)
{
	// base case
	if(i==n)
		return;

	if(arr[i] > arr[i+1])
		swap(arr[i], arr[i+1]);

	// recursive call
	round(arr, i+1, n);
}

void bubbleSort(int arr[], int n)
{
	// base case
	if(n==0 || n==1)
		return;
		
	round(arr, 0, n);
	
	// recursive call
	bubbleSort(arr, n-1);
}

int main()
{
	int arr[] = {2,6,1,5,4,3,7};
	bubbleSort(arr, 7);
	for(int i=0; i<7; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}