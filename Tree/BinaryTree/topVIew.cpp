// Question Link : https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

vector<int> topView(Node *root)
{
    vector<int> ans;
    
    if(root == NULL)
        return ans;
    
    map<int, int> topNode;
    queue<pair<Node*, int> > q;
    
    q.push(make_pair(root, 0));
    
    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node *frontNode = temp.first;
        int hd = temp.second;
        
        if(topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode -> data;
        
        if(frontNode -> left)
            q.push(make_pair(frontNode -> left, hd-1));
        
        if(frontNode -> right)
            q.push(make_pair(frontNode -> right, hd+1));
    }
    
    for(auto i: topNode)
    {
        ans.push_back(i.second);
    }
    
    return ans;
}

/*

Time Complexity: O(N.log(N))
    where n is the number of nodes in the given binary tree
    with each insertion operation in Map requiring O(log2n) complexity.
    
Space Complexity: O(N)

*/