// Question Link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/


// Approach for Disconnected Graph: [TC-O(N+E) and SC-O(N+E) + O(N) + O(N)]
void solve(int node, vector<int> adj[], vector<int> &visited, vector<int> &dfs)
{
    dfs.push_back(node);
    visited[node] = 1;
    
    for(auto it: adj[node])
    {
        if(!visited[it])
        {
            solve(it, adj, visited, dfs);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) 
{
    vector<int> dfs;
    vector<int> visited(V, 0);
    
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            solve(0, adj, visited, dfs);
        }
    }
    return dfs;
}


// Approach for Connected Graph
void solve(int node, vector<int> adj[], vector<int> &visited, vector<int> &dfs)
{
    dfs.push_back(node);
    visited[node] = 1;
    
    for(auto it: adj[node])
    {
        if(!visited[it])
        {
            solve(it, adj, visited, dfs);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) 
{
    vector<int> dfs;
    vector<int> visited(V, 0);
    
    solve(0, adj, visited, dfs);
    
    return dfs;
}