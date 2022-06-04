// Question Link : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

bool isSafe(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> &visited)
{
    if((x>=0 && x<n) && (y>=0 && y<n) && (m[x][y] == 1) && (visited[x][y] == 0))
        return true;
    else
        return false;
}
void solve(vector<vector<int>> &m, int n, int x, int y, string path, vector<string>& ans, vector<vector<int>> &visited)
{
    // base case
    if(x==n-1 && y==n-1) {
        ans.push_back(path);
        return ;
    }
    visited[x][y] = 1;
    
    // down
    if(isSafe(m, n, x+1, y, visited))
    {
        path.push_back('D');
        solve(m, n, x+1, y, path, ans, visited);
        path.pop_back();
    }
    // left
    if(isSafe(m, n, x, y-1, visited))
    {
        path.push_back('L');
        solve(m, n, x, y-1, path, ans, visited);
        path.pop_back();
    }
    // right
    if(isSafe(m, n, x, y+1, visited))
    {
        path.push_back('R');
        solve(m, n, x, y+1, path, ans, visited);
        path.pop_back();
    }
    // up
    if(isSafe(m, n, x-1, y, visited))
    {
        path.push_back('U');
        solve(m, n, x-1, y, path, ans, visited);
        path.pop_back();
    }
    // backtrack
    visited[x][y] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    string path;
    
    vector<vector<int>> visited = m;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = 0;
            
    // if source index is not valid       
    if(m[0][0] == 0)
        return ans;
        
    int srcx = 0, srcy = 0;
    solve(m, n, srcx, srcy, path, ans, visited);
    sort(ans.begin(), ans.end());
    return ans;
}





// optimized code
void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string move,
            vector<vector<int>> &visited, int di[], int dj[])
{
    // base case
    if(i == n-1 && j == n-1)
    {
        ans.push_back(move);
        return ;
    }
    
    string dir = "DLRU";
    
    for(int ind=0; ind<4; ind++)
    {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        
        if(nexti>=0 && nexti<n && nextj>=0 && nextj<n && !visited[nexti][nextj] & m[nexti][nextj]==1)
        {
            visited[i][j] = 1;
            solve(nexti, nextj, m, n, ans, move + dir[ind], visited, di, dj);
            visited[i][j] = 0;   // backtracking
        }
    }
}
vector<string> findPath(vector<vector<int>> &m, int n) 
{
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int> (n, 0));
    
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, +1, 0};
    
    if(m[0][0] == 1)
        solve(0, 0, m, n, ans, "", visited, di, dj);
    
    return ans;
}


/*

Time Complexity: O(4^(n*m))
Space Complexity: O(n*m)

*/