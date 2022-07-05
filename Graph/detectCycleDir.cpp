// Question Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/


// Using DFS: [TC-O(N+E) and SC-O(2*N) + O(N)]
bool solve(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis)
{
    vis[node] = 1;
    dfsVis[node] = 1;
    
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            if(solve(it, adj, vis, dfsVis))
            {
                return true;
            }
        }
        else if(dfsVis[it])
            return true;
    }
    
    dfsVis[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) 
{
    vector<int> vis(V, 0);
    vector<int> dfsVis(V, 0);
    
    for(int i=0; i<V; i++)
    {
        if(!vis[i])
        {
            if(solve(i, adj, vis, dfsVis))
            {
                return true;
            }
        }
    }
    return false;
}


// Using BFS (Kahn's Algo reverse logic): [TC-O(N+E) and SC-O(N+E)+O(N)+O(N)]
bool isCyclic(int V, vector<int> adj[]) 
{
    queue<int> q;
    vector<int> inDegree(V, 0);
    
    // storing inDegree values of each node
    for(int i=0; i<V; i++)
        for(auto it: adj[i])
            inDegree[it]++;
            
    // pushing the nodes into queue having inDegree '0'
    for(int i=0; i<V; i++)
        if(inDegree[i] == 0)
            q.push(i);
    
    // calculating topological order
    vector<int> topo;
    int count = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        
        for(auto it: adj[node])
        {
            inDegree[it]--;
            if(inDegree[it] == 0)
                q.push(it);
        }
    }
    if(count == V)
        return false;
    
    else 
        return true;
}