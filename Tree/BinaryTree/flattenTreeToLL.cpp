// Question Link : https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1/


// Approach 1: Recursion (using extra space)
Node* solve(Node *root)
{
    if(root -> left == NULL && root -> right == NULL)
        return root;
    
    if(root -> left)
    {
        Node *leftAns = solve(root -> left);
        leftAns -> right = root -> right;
        root -> right = root -> left;
        root -> left = NULL;
    }
    
    if(root -> right)
    {
        Node *rightAns = solve(root -> right);
        return rightAns;
    }
}
void flatten(Node *root)
{
    solve(root);
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/


// Approach 2: Using Morris Traversal (Constant Space)
void flatten(Node *root)
{
    Node *current, *pred;
    
    if(root == NULL)
        return ;
    
    current = root;
    
    while(current != NULL)
    {
        if(current -> left != NULL)
        {
            pred = current -> left;
            while(pred -> right != NULL)
                pred = pred -> right;
            
            pred -> right = current -> right;
            current -> right = current -> left;
            current -> left = NULL;
        }
        current = current -> right;
    }
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/