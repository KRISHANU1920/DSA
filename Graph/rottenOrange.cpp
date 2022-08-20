// Question Link : https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

int orangesRotting(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int fresh = 0;
    int tm = 0;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 2)
            {
                vis[i][j] = 2;
                q.push({{i, j}, 0});
            }
            if(grid[i][j] == 1)
                fresh++;
        }
    }
    
    int delR[] = {-1, 0, +1, 0};
    int delC[] = {0, +1, 0, -1};
    int count = 0;
    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        tm = max(tm, t);
        
        for(int i=0; i<4; i++)
        {
            int nRow = r + delR[i];
            int nCol = c + delC[i];
            
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m 
                && grid[nRow][nCol] == 1 && vis[nRow][nCol]!=2)
            {
                q.push({{nRow, nCol}, t+1});
                vis[nRow][nCol] = 2;
                count++;
            }
        }
    }
    if(count != fresh)
        return -1;
    
    return tm;
}

/*

Time Complexity: O(N*M)
Space Complexity: O(N*M)

*/