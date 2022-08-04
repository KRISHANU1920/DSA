// Question Link: https://practice.geeksforgeeks.org/problems/complete-binary-tree/1

bool isCompleteBT(Node* root)
{
    if(root == NULL)
        return true;
        
    bool flag = false;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        
        if(!temp)
        {
            flag = true;
            continue;
        }
        
        if(flag)
            return false;
        
        q.push(temp -> left);
        q.push(temp -> right);
    }
    return true;
}


/*

Time Complexity: O(N)
Space Complexity: O(N)

*/