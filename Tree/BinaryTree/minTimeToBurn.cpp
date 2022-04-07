// Question Link : https://practice.geeksforgeeks.org/problems/burning-tree/1#

// Creating Mapping with parent node
// and also return target node
Node* createParentMapping(Node *root, int target, unordered_map<Node*, Node*> &nodeToParent)
{
    nodeToParent[root] = NULL;
    Node *res = NULL;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node *front = q.front();
        q.pop();
        
        if(front -> data == target)
            res = front;
        
        if(front -> left)
        {
            nodeToParent[front -> left] = front;
            q.push(front -> left);
        }
        
        if(front -> right)
        {
            nodeToParent[front -> right] = front;
            q.push(front -> right);
        }
    }
    return res;
}

// function to find minimum time to burn the tree
int burnTree(Node* root, unordered_map<Node*, Node*> nodeToParent)
{
    int ans = 0;
    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    
    visited[root] = true;
    q.push(root);
    
    
    while(!q.empty())
    {
        bool flag = false;
        int Size = q.size();
        
        // process neighbouring nodes
        for(int i=0; i<Size; i++)
        {
            Node *front = q.front();
            q.pop();
            
            if(front -> left && !visited[front -> left])
            {
                q.push(front -> left);
                visited[front -> left] = true;
                flag = true;
            }
            
            if(front -> right && !visited[front -> right])
            {
                q.push(front -> right);
                visited[front -> right] = true;
                flag = true;
            }
            
            if(nodeToParent[front] && !visited[nodeToParent[front]])
            {
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
                flag = true;
            }
        }
        
        if(flag)
            ans++;
    }
    return ans;
}

int minTime(Node* root, int target) 
{
    unordered_map<Node*, Node*> nodeToParent;
    
    Node *targetNode = createParentMapping(root, target, nodeToParent);
    
    int ans = burnTree(targetNode, nodeToParent);
    
    return ans;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/