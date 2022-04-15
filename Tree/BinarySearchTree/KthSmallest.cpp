// Question Link : https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1


// Approach 1: Traverse the whole tree InOrder and store the elements accordingly into a vector. 
//             The formed vector is sorted. Return the Kth element of the vector.



// Approach 2: Using Recursion [TC: O(N) & SC: O(1)]
int solve(Node *root, int &i, int K)
{
    // base case
    if(root == NULL)
        return -1;
    
    // Left
    int left = solve(root -> left, i, K);
    
    if(left != -1)
        return left;
    
    // Node
    i++;
    if(i == K)
        return root -> data;
        
    // Right
    return solve(root -> right, i, K);
}

int KthSmallestElement(Node *root, int K) 
{
    int i = 0;
    int ans = solve(root, i, K);
    return ans;
}


// Approach 3: Using Morris Inorder Traversal [TC: O(N) & SC: O(1)]
int morrisTraversal(Node *root, int &i, int K)
{
    Node *current, *prev;
    
    int ans = -1;
    
    current = root;

    while(current != NULL)
    {
        if(current -> left == NULL)
        {
            //cout << current -> data << " ";
            i++;
            if(i == K)
                ans = current -> data;
                
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
                prev -> right = NULL;
                //cout << current -> data << " ";
                
                i++;
                if(i == K)
                    ans = current -> data;
                    
                current = current -> right;
            }
        }
    }
    return ans;
}

int KthSmallestElement(Node *root, int K) 
{
    int i = 0;
    int ans = morrisTraversal(root, i, K);
    return ans;
}