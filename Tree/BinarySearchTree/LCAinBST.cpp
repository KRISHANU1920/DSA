// Question Link : https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

// Approach 1: Recursive (TC: O(Height) & SC: O(Height))
Node* LCA(Node *root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    
    if(root -> data < n1 && root -> data < n2)
        LCA(root -> right, n1, n2);
    
    else if(root -> data > n1 && root -> data > n2)
        LCA(root -> left, n1, n2);
        
    else
        return root;
}

// Approach 2: Iterative (TC: O(Height) & SC: O(1))
Node* LCA(Node *root, int n1, int n2)
{
    while(root != NULL)
    {
        if(root -> data < n1 && root -> data < n2)
            root = root -> right;
        
        else if(root -> data > n1 && root -> data > n2)
            root = root -> left;
            
        else
            return root;
    }
    return NULL;
}

