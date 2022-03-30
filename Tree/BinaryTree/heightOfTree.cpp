// Question Link : https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

int height(struct Node* node)
{
    // base case
    if(node == NULL)
        return 0;
    
    int left = height(node -> left);
    int right = height(node -> right);
    
    int ans = max(left, right) + 1;
    
    return ans;
}

/*

Time Complexity: O(N)
Space Complexity: O(height)

Note: also known as Depth of Binary Tree

*/