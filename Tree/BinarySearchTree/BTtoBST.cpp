// Question Link : https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1

void inorder(Node *root, vector<int> &in)
{
    if(root == NULL)
        return ;
    
    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

void solve(Node *root, vector<int> &in, int &i)
{
    if(root == NULL)
        return ;
    
    solve(root -> left, in, i);
    
    root -> data = in[i];
    i++;
    
    solve(root -> right, in, i);
}

Node *binaryTreeToBST (Node *root)
{
    vector<int> inorderVal;
    inorder(root, inorderVal);
    
    sort(inorderVal.begin(), inorderVal.end());
    
    int i=0;
    
    solve(root, inorderVal, i);
    return root;
}

/*

Time Complexity: O(N.log(N))
Space Complexity: O(N)

*/