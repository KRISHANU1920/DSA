// Question Link : https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/

pair<int, int> solve(Node *root)
{
    // base case
    if(root == NULL)
    {
        pair<int, int> p = make_pair(0,0);
        return p;
    }
    
    pair<int, int> leftAns = solve(root -> left);
    pair<int, int> rightAns = solve(root -> right);
    
    pair<int, int> ans;
    ans.first = root -> data + leftAns.second + rightAns.second;
    ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
    
    return ans;
}

int getMaxSum(Node *root) 
{
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

/*

Time Complexity: O(N)
Space Complexity: O(Height)

*/