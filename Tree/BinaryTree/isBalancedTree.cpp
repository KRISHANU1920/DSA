// Question Link : https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1


// Brute Force Approach
int height(Node *root)
{
    if(root == NULL)
        return 0;
    
    int left = height(root -> left);
    int right = height(root -> right);
    int ans = max(left, right) + 1;
    
    return ans;
}

bool isBalanced(Node *root)
{
    if(root == NULL)
        return true;
    
    bool left = isBalanced(root -> left);
    bool right = isBalanced(root -> right);
    bool diff = (abs(height(root -> left) - height(root -> right)) <= 1);
    
    if(left && right && diff)
        return true;
    else
        return false;
}

/*

Time Complexity: O(N^2)
Space Complexity: O(Height)

*/


// Efficient Approach
pair<bool, int> isBalancedFast(Node *root)
{
    if(root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    
    pair<bool, int> left = isBalancedFast(root -> left);
    pair<bool, int> right = isBalancedFast(root -> right);
    
    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = (abs(left.second - right.second) <= 1);
    
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    
    if(leftAns && rightAns && diff)
        ans.first = true;
    else
        ans.first = false;
    
    return ans;
}

bool isBalanced(Node *root)
{
    return isBalancedFast(root).first;
}

/*

Time Complexity: O(N)
Space Complexity: O(Height)

*/