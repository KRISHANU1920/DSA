// Question Link : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

void leftTraversal(Node *root, vector<int> &ans)
{
    // base case
    if((root == NULL) || (root -> left == NULL && root -> right == NULL))
        return ;
    
    ans.push_back(root -> data);
    
    if(root -> left)
        leftTraversal(root -> left, ans);
    else
        leftTraversal(root -> right, ans);
}

void leafNodeTraversal(Node *root, vector<int> &ans)
{
    if(root == NULL)
        return;
    
    if(root -> left == NULL && root -> right == NULL)
        ans.push_back(root -> data);
    
    leafNodeTraversal(root -> left, ans);
    leafNodeTraversal(root -> right, ans);
}

void rightTraversal(Node *root, vector<int> &ans)
{
    // base case
    if((root == NULL) || (root -> left == NULL && root -> right == NULL))
        return ;
    
    if(root -> right)
        rightTraversal(root -> right, ans);
    else
        rightTraversal(root -> left, ans);
    
    ans.push_back(root -> data);
    
}

vector <int> boundary(Node *root)
{
    vector<int> ans;
    
    // storing root value
    ans.push_back(root -> data);
    
    // left boundary traversal
    leftTraversal(root -> left, ans);
    
    // leaf nodes traversal
    leafNodeTraversal(root -> left, ans);
    leafNodeTraversal(root -> right, ans);
    
    // right boundary traversal
    rightTraversal(root -> right, ans);
    
    return ans;
}

/*

Time Complexity: O(N)
Space Complexity: O(Height)

*/