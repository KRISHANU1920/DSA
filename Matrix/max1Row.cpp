// Question Link : https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#

int rowWithMax1s(vector<vector<int> > arr, int n, int m) 
{
    int i=0, j=0;
    while(i<n || j<m)
    {
        for(i=0; i<n; i++)
        {
            if(arr[i][j] == 1)
                return i;
        }
        j++;
    }
    return -1;
}

/*

Time Complexity: O(m+n)
Space Complexity: O(1)

*/