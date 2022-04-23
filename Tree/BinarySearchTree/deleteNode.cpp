// Question Link : https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1/#

int minVal(Node *root)
{
    while(root -> left != NULL)
        root = root -> left;
        
    return root -> data;
}

Node *deleteNode(Node *root, int X) 
{
    // base case
    if(root == NULL)
        return root;
    
    if(root -> data == X)
    {
        // 0 child
        if(root -> left == NULL && root -> right == NULL)
        {
            delete root;
            return NULL;
        }
        
        // 1 child
        
        // left child only
        if(root -> left != NULL && root -> right == NULL) 
        {
            Node *temp = root -> left;
            delete root;
            return temp;
        }
        
        // right child only
        if(root -> left == NULL && root -> right != NULL)
        {
            Node *temp = root -> right;
            delete root;
            return temp;
        }
        
        // 2 children
        if(root -> left != NULL && root -> right != NULL)
        {
            // get the inorder successor
            int mini = minVal(root -> right);
            
            // copy the inorder successor data to current node
            root -> data = mini;
            
            // delete the inorder successor
            root -> right = deleteNode(root -> right, mini);
        }
    }
    
    else if(root -> data < X)
        root -> right = deleteNode(root -> right, X);
    
    else
        root -> left = deleteNode(root -> left, X);
        
    return root;
}


/*

Time Complexity: O(Height)
Space Complexity: O(Height)

*/