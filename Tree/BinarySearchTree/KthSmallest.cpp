// Question Link : https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

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

/*

Time Complexity: O(N)
Space Complexity: O(Height)

*/