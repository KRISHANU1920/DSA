// Using BFS algorithm: [TC-O(N+E) and SC-O(N)+O(N)]


vector<int> shortestPath(int V, vector<int> adj[])
{
    vector<int> dist(V, INT_MAX);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while(!q.empty())
    {
        int node = q.front();
        q.pop()

        for(auto it: adj[node])
        {
            if(dist[node]+1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    return dist;
}