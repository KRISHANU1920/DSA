// Question Link : https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1#

vector <int> zigZagTraversal(Node* root)
{
    vector<int> result;
    queue<Node*> q;
    q.push(root);
    
    // flag for direction reversing
    bool leftToRight = true;
    
    while(!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        
        // Level processing
        for(int i=0; i<size; i++)
        {
            Node *frontNode = q.front();
            q.pop();
            
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode -> data;
            
            if(frontNode -> left)
                q.push(frontNode -> left);
                
            if(frontNode -> right)
                q.push(frontNode -> right);
        }
        
        // changing direction
        leftToRight = !leftToRight;
        
        // push the current level transformed elements into result
        for(auto it: ans)
            result.push_back(it);
    }
    return result;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/