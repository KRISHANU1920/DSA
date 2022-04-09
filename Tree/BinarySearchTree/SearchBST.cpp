// Question Link : https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1/

// Reccursive Approach
bool search(Node* root, int x) 
{
    if(root == NULL)
        return false;
        
    if(root -> data == x)
        return true;
    
    if(root -> data > x)
        return search(root -> left, x);
    else
        return search(root -> right, x);
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/


// Iterative Approach
bool search(Node* root, int x) 
{
    Node *temp = root;
    
    while(temp != NULL)
    {
        if(temp -> data == x)
            return true;
        
        if(temp -> data > x)
            temp = temp -> left;
        else
            temp = temp -> right;
    }
    return false;
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/