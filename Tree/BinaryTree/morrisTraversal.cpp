// Question Link : https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

void morrisTraversal(Node *root)
{
    Node *current, *prev;
    
    if(root == NULL);
        return ;
    
    current = root;

    while(current != NULL)
    {
        if(current -> left == NULL)
        {
            cout << current -> data << " ";
            current = current -> right;
        }
        else
        {
            // find the inorder predecessor of the current
            prev = current -> left;
            while(prev -> right != NULL && prev -> right != current)
                prev = prev -> right;

            // make current the right child of it's predecessor
            if(prev -> right == NULL)
            {
                prev -> right = current;
                current = current -> left;
            }

            // revert back the changes made in above if condition
            // to make the tree back to it's original form
            else
            {
                prev -> next = NULL;
                cout << current -> data << " ";
                current = current -> right;
            }
        }
    }
}

/*

Time Complexity: O(N)   [Every edge is traversed at most three times]
Space Complexity: O(1)

*/