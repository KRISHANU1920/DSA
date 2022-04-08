// Question Link : https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1/

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