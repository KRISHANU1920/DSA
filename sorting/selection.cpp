#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 6, 3, 5, 9, 4, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    //applying selection sort
    for(int i=0; i<n-1; i++)
    {
        int min_index = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[min_index] > arr[j])
               min_index = j;
        }
        swap(arr[min_index], arr[i]);
    }
    cout << "Array after sorting: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*

Time Complexity:
  best case: O(N^2)
  worst case: O(N^2)

Space Complexity: O(1)

used for short arrays

stability: Unstable

In-place Sort

*/