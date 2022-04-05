// Question Link : https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#

Node* lca(Node* root ,int n1 ,int n2 )
{
    // base case
    if(root == NULL)
        return NULL;
    
    // if either of n1 or n2 is equal to root -> data then return root
    if(root -> data == n1 || root -> data == n2)
        return root;
    
    // recursively call lca for left and right subtrees
    Node *leftAns = lca(root -> left, n1, n2);
    Node *rightAns = lca(root -> right, n1, n2);
    
    // if both are not null then both nodes are present in left and right
    // subtrees respectively, hence this is the LCA
    if(leftAns != NULL && rightAns != NULL)
        return root;
    
    else if(leftAns != NULL && rightAns == NULL)
        return leftAns;
    
    else if(leftAns == NULL && rightAns != NULL)
        return rightAns;
    
    else
        return NULL;
}

/*

Time Complexity: O(N)
Space Complexity: O(Height)

*/