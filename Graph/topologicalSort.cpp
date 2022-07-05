// Question Link: https://practice.geeksforgeeks.org/problems/topological-sort/1/


// Using DFS: [TC-O(N+E) and SC-O(2*N)]
void solve(int node, vector<int> adj[], stack<int> &st, vector<int> &visited)
{
    visited[node] = 1;
    
    for(auto it: adj[node])
    {
        if(!visited[it])
        {
            solve(it, adj, st, visited);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) 
{
    stack<int> st;
    vector<int> visited(V, 0);
    
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            solve(i, adj, st, visited);
        }
    }
    
    vector<int> topo;
    while(!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}


// Using BFS (Kahn's Algorithm): [TC-O(N+E) and SC-O(N)+O(N)]
vector<int> topoSort(int V, vector<int> adj[]) 
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
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for(auto it: adj[node])
        {
            inDegree[it]--;
            if(inDegree[it] == 0)
                q.push(it);
        }
    }
    return topo;
}