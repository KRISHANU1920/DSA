// Question Link : https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#

int solve(Node* root)
{
    // base case
    if(root == NULL)
        return 0;
    
    int left = solve(root -> left);
    int right = solve(root -> right);
    
    int currVal = root -> data;
    
    root -> data = left + right;
    
    return left + right + currVal;
}

void toSumTree(Node *node)
{
    solve(node);
}

/*

Time Complexity: O(N)
Space Complexity: O(Height)

*/