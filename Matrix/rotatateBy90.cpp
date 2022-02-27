// Question Link : https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/

void rotate(vector<vector<int> >& matrix)
{
    int N = matrix.size();
    
    // doing transpose in place
    for(int i=0; i<N; i++)
    {
        for(int j=i; j<N; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
    
    // swapping upper half with lower half
    for(int i=0; i<N/2; i++)
    {
        for(int j=0; j<N; j++)
            swap(matrix[i][j], matrix[N-i-1][j]);
    }
}

/*

Time Complexity: O(N^2)
Space Complexity: O(1)

*/