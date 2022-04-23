// Question Link : https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=1

void inorder(TreeNode<int>* root, vector<int> &in)
{
	if(root == NULL)
		return ;
	
	inorder(root -> left, in);
	in.push_back(root -> data);
	inorder(root -> right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
	// Storing the inoder traversal values into a vector
    vector<int> inorderVal;
	inorder(root, inorderVal);
	
	int n = inorderVal.size();
	
	// Creating a flattened new sorted list from the vector
	TreeNode<int> *newRoot = new TreeNode<int>(inorderVal[0]);
	TreeNode<int> *curr = newRoot;
	
	for(int i=1; i<n; i++)
	{
		TreeNode<int> *temp = new TreeNode<int>(inorderVal[i]);
		curr -> left = NULL;
		curr -> right = temp;
		curr = temp;
	}
	
	// Making right and left of last node NULL
	curr -> left = NULL;
	curr -> right = NULL;
	
	return newRoot;
}


/*

Time Complexity: O(N)
Space Complexity: O(N)

*/