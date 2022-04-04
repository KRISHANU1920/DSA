// Question Link : https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1/#

void  solve(Node *root, int vd, map<int, vector<int> > &nodes)
{
    if(root == NULL)
        return ;
    
    // store all nodes of same line in vector
    nodes[vd].push_back(root -> data);
    
    // increase vertical distance if left child
    solve(root -> left, vd+1, nodes);
    
    // no change in vertical distance for right child
    solve(root -> right, vd, nodes);
}

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    map<int, vector<int> > nodes;
    
    solve(root, 0, nodes);
    
    for(auto i: nodes)
    {
        for(auto j: i.second)
            ans.push_back(j);
    }
    
    return ans;
}

/*

Time Complexity: O(N.log(N))
Space Complexity: O(N)

*/