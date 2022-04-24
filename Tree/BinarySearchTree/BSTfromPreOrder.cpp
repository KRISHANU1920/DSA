// Question Link : https://www.codingninjas.com/codestudio/problems/preorder-traversal-to-bst_893111?leftPanelTab=0

BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi, int &i)
{
	// base case
	if(i >= preorder.size())
		return NULL;
	
	if(preorder[i] < mini || preorder[i] > maxi)
		return NULL;
	
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
	root -> left = solve(preorder, mini, root -> data, i);
	root -> right = solve(preorder, root -> data, maxi, i);
	return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) 
{
    int mini = INT_MIN;
	int maxi = INT_MAX;
	int i = 0;
	
	return solve(preorder, mini, maxi, i);
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/