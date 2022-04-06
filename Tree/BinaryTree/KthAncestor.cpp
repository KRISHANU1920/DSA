// Question Link : https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1/#

Node* solve(Node *root, int &k, int node)
{
    if(root == NULL)
        return NULL;
    
    if(root -> data == node)
        return root;
    
    Node *leftAns = solve(root -> left, k, node);
    Node *rightAns = solve(root -> right, k, node);
    
    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX; // answer lock
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX; // answer lock
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    
    // if node doesn't exist or node is root then return -1
    if(ans == NULL || ans -> data == node)
        return -1;
    else
        return ans -> data;
}

/*

Time Complexity: O(N)
Space Complexity: O(Height)

*/