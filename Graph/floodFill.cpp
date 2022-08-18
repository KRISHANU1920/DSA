// Question Link : https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1


// Using DFS:
void dfs(int row, int col, int iniColor, int newColor, int delR[], int delC[], 
                vector<vector<int>> &image, vector<vector<int>> &ans)
{
    ans[row][col] = newColor;
    int M = image.size();
    int N = image[0].size();
    
    for(int i=0; i<4; i++)
    {
        int nRow = row + delR[i];
        int nCol = col + delC[i];
        
        if(nRow>=0 && nRow<M && nCol>=0 && nCol<N && image[nRow][nCol] == iniColor
            && ans[nRow][nCol] != newColor)
        {
            dfs(nRow, nCol, iniColor, newColor, delR, delC, image, ans);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
    vector<vector<int>> ans = image;
    int delR[] = {-1, 0, +1, 0};
    int delC[] = {0, +1, 0, -1};
    int iniColor = image[sr][sc];
    
    dfs(sr, sc, iniColor, newColor, delR, delC, image, ans);
    return ans;
}

// Using BFS:
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
    vector<vector<int>> ans = image;
    int M = image.size();
    int N = image[0].size();
    int delR[] = {-1, 0, +1, 0};
    int delC[] = {0, +1, 0, -1};
    int iniColor = image[sr][sc];
    queue<pair<int, int>> q;
    
    q.push({sr, sc});
    ans[sr][sc] = newColor;
    
    while(!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        int row = node.first;
        int col = node.second;
        
        for(int i=0; i<4; i++)
        {
            int nRow = row + delR[i];
            int nCol = col + delC[i];
            
            if(nRow>=0 && nRow<M && nCol>=0 && nCol<N && image[nRow][nCol] == iniColor
                && ans[nRow][nCol] != newColor)
            {
                q.push({nRow, nCol});
                ans[nRow][nCol] = newColor;
            }
        }
        
    }
    return ans;
}

/*

Time Complexity: O(M*N)
Space Complexity: O(M*N)

*/