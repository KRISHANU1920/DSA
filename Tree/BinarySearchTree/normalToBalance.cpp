// Question Link : https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1/

void inorder(Node *root, vector<int> &in)
{
    if(root == NULL)
        return ;
    
    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

Node* inorderToBST(int s, int e, vector<int> &in)
{
    if(s > e)
        return NULL;
    
    int mid = s + (e-s)/2;
    
    Node *root = new Node(in[mid]);
    root -> left = inorderToBST(s, mid-1, in);
    root -> right = inorderToBST(mid+1, e, in);
    
    return root;
}

Node* buildBalancedTree(Node* root)
{
	vector<int> inorderVal;
	inorder(root, inorderVal);
	
	return inorderToBST(0, inorderVal.size()-1, inorderVal);
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/