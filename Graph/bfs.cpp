// Question Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#


// Approach for Disconnected Graph: [TC-O(N+E) and SC-O(N+E) + O(N) + O(N)]
vector<int> bfsOfGraph(int V, vector<int> adj[]) 
{
    vector<int> bfs;
    vector<int> visited(V, 0);
    
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            
            while(!q.empty())
            {
                int Node = q.front();
                q.pop();
                bfs.push_back(Node);
                
                for(auto it: adj[Node])
                {
                    if(!visited[it])
                    {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}



// Approach for Connected Graph
vector<int> bfsOfGraph(int V, vector<int> adj[]) 
{
    vector<int> bfs;
    vector<int> visited(V, 0);
    
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    
    while(!q.empty())
    {
        int Node = q.front();
        q.pop();
        bfs.push_back(Node);
        
        for(auto it: adj[Node])
        {
            if(!visited[it])
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }
    return bfs;
}