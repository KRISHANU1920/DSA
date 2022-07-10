// using TopoSort: [TC-O(N+E)*2 and SC-O(2*N)]

#include<bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<pair<int,int>> adj[], stack<int> &st, vector<int> &visited)
{
    visited[node] = 1;
    
    for(auto it: adj[node])
    {
        if(!visited[it.first])
        {
            topoSort(it.first, adj, st, visited);
        }
    }
    st.push(node);
}

void shortestPath(int src, int V, vector<pair<int, int>> adj[])
{
    vector<int> vis(V, 0);
    vector<int> dist(V, 1e9);
    stack<int> st;

    for(int i=0; i<V; i++)
        if(!vis[i])
            topoSort(i, adj, st, vis);
    
    dist[src] = 0;

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        for(auto it: adj[node])
        {
            if(dist[it.second] != 1e9)
            {
                if(dist[node] + it.second < dist[it.first])
                    dist[it.first] = dist[node] + it.second;
            }
        }
    }

    for(auto it: dist)
    {
        (it == 1e9) ? cout << "INF " : cout << it << " ";
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];

    for(int i=0; i<m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    shortestPath(0, n, adj);
    return 0;
}