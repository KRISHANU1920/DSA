// Question Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1


// Using BFS: [TC-O(N+E) and SC-O(N+E) + O(N) + O(N)]
bool solve(int ind, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    color[ind] = 1;
    q.push(ind);
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for(auto it: adj[node])
        {
            if(color[it] == -1)
            {
                q.push(it);
                color[it] = 1 - color[node];
            }
            else if(color[it] == color[node])
                return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[])
{
    vector<int> color(V, -1);
    
    for(int i=0; i<V; i++)
    {
        if(color[i] == -1)
        {
            if(!solve(i, adj, color))
                return false;
        }
    }
    return true;
}


// Using DFS: [TC-O(N+E) and SC-O(N+E) + O(N) + O(N)]
bool solve(int node, vector<int> adj[], vector<int> &color)
{
    if(color[node] == -1)
        color[node] = 1;
    
    for(auto it: adj[node])
    {
        if(color[it] == -1)
        {
                color[it] = 1 - color[node];
                
                if(!solve(it, adj, color))
                return false;
        }
        else if(color[it] == color[node])
            return false;
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[])
{
    vector<int> color(V, -1);
    
    for(int i=0; i<V; i++)
    {
        if(color[i] == -1)
        {
            if(!solve(i, adj, color))
                return false;
        }
    }
    return true;
}
