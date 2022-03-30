// Question Link : https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

// Approach 1: using Height of Binary Tree
int height(Node *root)
{
    // base case
    if(root == NULL)
        return 0;
    
    int left = height(root -> left);
    int right = height(root -> right);
    int ans = max(left, right) + 1;
    
    return ans;
}
int diameter(Node* root) 
{
    // base case
    if(root == NULL)
        return 0;
    
    int op1 = diameter(root -> left);
    int op2 = diameter(root -> right);
    int op3 = height(root -> left) + height(root -> right) + 1;
    
    int ans = max(op1, (op2, op3));
    
    return ans;
}

/*

Time Complexity: O(N^2)
Space Complexity: O(Height)

*/


// Approach 2: By returning both diameter and height using pair<int, int>
pair<int, int> diameterFast(Node* root)
{
    if(root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    
    pair<int, int> left = diameterFast(root -> left);
    pair<int, int> right = diameterFast(root -> right);
    
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    
    pair<int, int> ans;
    ans.first = max(op1, (op2, op3));
    ans.second = max(left.second, right.second) + 1;
    
    return ans;
}

int diameter(Node* root) 
{
    pair<int, int> ans = diameterFast(root);
    return ans.first;
}

/*

Time Complexity: O(N)
Space Complexity: O(Height)

*/