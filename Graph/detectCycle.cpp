// Question Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/#


// Using BFS: [TC-O(N+E) and SC-O(N+E)+O(N)+O(N)]
bool solve(int ind, vector<int> adj[], vector<int> &visited)
{
    queue<pair<int, int>> q;
    
    visited[ind] = 1;
    q.push({ind, -1});
    
    while(!q.empty())
    {
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();
        
        for(auto it: adj[node])
        {
            if(!visited[it])
            {
                q.push({it, node});
                visited[it] = 1;
            }
            else if(it != prev)
                return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) 
{
    vector<int> visited(V, 0);
    
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            if(solve(i, adj, visited))
                return true;
        }
    }
    return false;
}


// Using DFS: [TC-O(N+E) and SC-O(N+E) + O(N) + O(N)]
bool solve(int ind, int par, vector<int> adj[], vector<int> &visited)
{
    visited[ind] = 1;
    
    for(auto it: adj[ind])
    {
        if(!visited[it])
        {
            if(solve(it, ind, adj, visited))
                return true;
        }
        else if(it != par)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) 
{
    vector<int> visited(V, 0);
    
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            if(solve(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}