#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, E;
    cin >> N >> E;

    // Undirected Graph Adjacency Matrix representation: [SC-O(N^2)]
    vector<vector<int>> adjMat(N+1, vector<int> (N+1, 0));
    for(int i=0; i<E; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }
    
    // Directed Graph Adjacency Matrix representation: [SC-O(N^2)]
    vector<vector<int>> adjMat(N+1, vector<int> (N+1, 0));
    for(int i=0; i<E; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
    }

    // Undirected Graph Adjacency List representation: [SC-O(N + 2*E)]
    vector<int> adjList[N+1];
    for(int i=0; i<E; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Directed Graph Adjacency List representation: [SC-O(N + 2*E)]
    vector<int> adjList[N+1];
    for(int i=0; i<E; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    // Undirected Weighted Graph Adjacency List representation: [SC-O(N + 2*E + 2*E)]
    vector<pair<int,int>> adjList[N+1];
    for(int i=0; i<E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }

    return 0;
}