// Question Link : https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

void inorder(Node *root, vector<Node*> &in)
{
    if(root == NULL)
        return ;
    
    inorder(root -> left, in);
    in.push_back(root);
    inorder(root -> right, in);
}

bool isDeadEnd(Node *root)
{
    vector<Node*> v;
    inorder(root, v);
    
    int n = v.size();
    
    if(v[0]->right == NULL && (v[0]->data == 1 && v[1]->data == 2))
        return true;
    
    for(int i=1; i<n-1; i++)
    {
        if((v[i]->left == NULL && v[i]->right == NULL) && (v[i]->data == v[i-1]->data+1 && v[i]->data == v[i+1]->data-1))
            return true;
        
    }
    
    return false;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/