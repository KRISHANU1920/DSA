// Selection Sort Using Recursion
#include <bits/stdc++.h>
using namespace std;

int round(int arr[], int min, int i, int n)
{
	// base case
	if(i==n)
		return min;

	if(arr[min] > arr[i])
		min = i;
	
	// recursive call
	return round(arr, min, i+1, n);
}

void selectionSort(int arr[], int n)
{
	// base case
	if(n==0 || n==1)
		return;
	
	int minInd = round(arr, 0, 1, n);
	swap(arr[minInd], arr[0]);

	// recursive call
	selectionSort(arr+1, n-1);
}

int main()
{
	int arr[] = {2,6,1,5,4,3,7};
	selectionSort(arr, 7);
	for(int i=0; i<7; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}