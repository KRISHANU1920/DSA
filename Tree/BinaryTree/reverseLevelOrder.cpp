// Question Link : https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    queue<Node*> q;
    stack<Node*> s;
    
    q.push(root);
    s.push(root);
    
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        
        // store right side of node first for reverse level order
        if(temp -> right != NULL)
        {
            q.push(temp -> right);
            s.push(temp -> right);
        }
        
        if(temp -> left != NULL)
        {
            q.push(temp -> left);
            s.push(temp -> left);
        }
    }
    
    while(!s.empty())
    {
        ans.push_back(s.top() -> data);
        s.pop();
    }
    
    return ans;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/