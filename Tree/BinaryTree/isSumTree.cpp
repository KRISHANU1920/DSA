// Question Link : https://practice.geeksforgeeks.org/problems/sum-tree/1#

pair<bool, int> isSumTreeFast(Node* root)
{
    // base case
    if(root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    
    // leaf node condition
    if(root -> left == NULL && root -> right == NULL)
    {
        pair<bool, int> p = make_pair(true, root -> data);
        return p;
    }
    
    pair<bool, int> left = isSumTreeFast(root -> left);
    pair<bool, int> right = isSumTreeFast(root -> right);
    
    bool sum = (left.second + right.second == root -> data);
    
    pair<bool, int> ans;
    
    if(left.first && right.first && sum) 
    {
        ans.first = true;
        ans.second = 2 * root -> data;
    }
    else
        ans.first = false;
        
    return ans;
}

bool isSumTree(Node* root)
{
    return isSumTreeFast(root).first;
}

/*

Time Complexity: O(N)
Space Complexity: O(Height)

*/