// Question Link : https://leetcode.com/problems/spiral-matrix/

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    vector<int> ans;
    int k = 0;              // starting row index
    int l = 0;              // starting column index
    int m = matrix.size();     // ending row index
    int n = matrix[0].size();   // ending column index
    
    while(k<m && l<n)
    {
        // store the first row from the remaining rows
        for(int i=l; i<n; i++) {
            ans.push_back(matrix[k][i]);
        }
        k++;
        
        // store the last column from the remaining columns
        for(int i=k; i<m; i++) {
            ans.push_back(matrix[i][n-1]);
        }
        n--;
        
        // store the last row from the remaining rows
        if(k < m) {
            for(int i=n-1; i>=l; i--) {
                ans.push_back(matrix[m-1][i]);
            }
            m--;
        }
        
        // store the first column from the remaining columns
        if(l < n) {
            for(int i=m-1; i>=k; i--) {
                ans.push_back(matrix[i][l]);
            }
            l++;
        }
    }
    return ans;
}

/*
Time Complexity: O(m.n)
Space Complexity: O(1)
*/