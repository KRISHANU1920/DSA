// Question Link : https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

bool isSafe(int node, bool graph[101][101], int n, int color[], int col)
{
    for(int k=0; k<n; k++)
    {
        if(k!=node && graph[k][node] == 1 && color[k] == col)
            return false;
    }
    return true;
}

bool solve(int node, bool graph[101][101], int m, int n, int color[])
{
    if(node == n)
        return true;
    
    for(int i=1; i<=m; i++)
    {
        if(isSafe(node, graph, n, color, i))
        {
            color[node] = i;
            
            if(solve(node+1, graph, m, n, color))
                return true;
                
            color[node] = 0;  // backtracking
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) 
{
    int color[n] = {0};
    if(solve(0, graph, m, n, color))
        return true;
    
    return false;
}

/*

Time Complexity: O(N^M)
Space Complexity: O(N)

*/