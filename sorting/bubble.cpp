#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 6, 3, 5, 9, 4, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    //applying bubble sort
    for(int i=1; i<n; i++)
    {
        bool swapped = false;
        for(int j=0; j<n-i; j++)
        {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
    cout << "Array after sorting: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*

Time Complexity:
  best case: O(N)    (sorted array)
  worst case: O(N^2)

Space Complexity: O(1)

Stability: Stable

In-place sort

*/