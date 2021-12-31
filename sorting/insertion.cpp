#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 6, 3, 5, 9, 4, 8};
    //int arr[] = {7, 6, 5, 4, 3, 2, 1};    // worst
    //int arr[] = {1, 2, 3, 4, 5, 6, 7};   // best
    int n = sizeof(arr)/sizeof(arr[0]);
    //applying selection sort
    for(int i=1; i<n; i++)
    {
        int temp = arr[i];
        int j = i-1;
        //cout << "Round " << i << ": \n";
        //int c=1;
        while(j >= 0)
        {
            if(arr[j] > temp)
                arr[j+1] = arr[j];
            else
                break;
            j--;
            //cout << "Shift " << c++ << ": ";
            //for(int k=0; k<n; k++)
            //    cout << arr[k] << " ";
            //cout << "\t" << temp << "\n";
        }
        arr[j+1] = temp;
        //cout << "Shift " << c++ << ": ";
        //for(int k=0; k<n; k++)
        //    cout << arr[k] << " ";
        //cout << "\t" << temp << "\n";
        //cout << "\n";
    }
    cout << "Array after sorting: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*

Time Complexity:
  best case: O(N)    (sorted)
  worst case: O(N^2)

Space Complexity: O(1)

used for short arrays

stability: Stable

Adaptable

In-place Sort

*/