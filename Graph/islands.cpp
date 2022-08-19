// Question Link : https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

void bfs(int row, int col, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &grid)
{
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=-1; i<=1; i++)
        {
            for(int j=-1; j<=1; j++)
            {
                int nRow = x + i;
                int nCol = y + j;
                
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]=='1' && !vis[nRow][nCol])
                {
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                }
            }
        }
    }
    
}

int numIslands(vector<vector<char>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<int>> vis(n, vector<int> (m, 0));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == '1' && !vis[i][j])
            {
                count++;
                bfs(i, j, n, m, vis, grid);
            }
        }
    }
    return count;
}

/*

Time Complexity: O(N*M)
Space Complexity: O(N*M)

*/