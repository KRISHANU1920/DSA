// Question Link : https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1#

vector<int> verticalOrder(Node *root)
{
        vector<int> ans;
    
    // creating a map to store nodes at a particular horizontal distance
    map<int, vector<int> > nodes;
    
    // creating empty queue for level order traversal
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));
    
    // Empty Tree
    if(root == NULL)
        return ans;
    
    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int hd = temp.second;
        
        nodes[hd].push_back(frontNode -> data);
        
        // if left child of frontNode exist then push into queue
        if(frontNode -> left)
            q.push(make_pair(frontNode -> left, hd-1));
        
        // if right child of frontNode exist then push into queue
        if(frontNode -> right)
            q.push(make_pair(frontNode -> right, hd+1));
    }
    
    // traversing the map and storing the nodes in list
    // at every horizontal distance
    for(auto i: nodes) {
        for(auto j: i.second) 
        {
            ans.push_back(j);
        }
    }
    return ans;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/