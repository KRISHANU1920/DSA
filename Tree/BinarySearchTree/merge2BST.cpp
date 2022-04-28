// Question Link : https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1/


// Approach 1: using extra 2 vectors [ TC-O(M+N) & SC-O(M+N) ]
void inorder(TreeNode<int> *root, vector<int> &in)
{
	if(root == NULL)
		return ;

	inorder(root -> left, in);
	in.push_back(root -> data);
	inorder(root -> right, in);
}

void merge(vector<int> &a, vector<int> &b, vector<int> &merged)
{
	int i=0, j=0, k=0;

	while(i < a.size() && j < b.size())
	{
		if(a[i] < b[j])
			merged[k++] = a[i++]; 

		else
			merged[k++] = b[j++];
	}

	while(i < a.size())
		merged[k++] = a[i++];

	while(j < b.size())
		merged[k++] = b[j++];
}

TreeNode<int> *constructBST(int s, int e, vector<int> &merged)
{
	if(s > e)
		return NULL;
	
	int mid = s + (e-s)/2;
	
	TreeNode<int> *root = new TreeNode<int>(merged[mid]);
	root -> left = constructBST(s, mid-1, merged);
	root -> right = constructBST(mid+1, e, merged);
	
	return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
	vector<int> a;
	vector<int> b;

	// store inorder traversed values into arrays
	inorder(root1, a);
	inorder(root2, b);

	// merge the two sorted inorder arrays
	vector<int> merged(a.size() + b.size());
	merge(a, b, merged);

	// construct BST from merged inorder array
	return constructBST(0, merged.size()-1, merged);
}




// ------------------------------------------------------------------------------------------------------------------//

// Approach 2: By Changing links [ TC-O(M+N) & SC-O(H1+H2)]
void convertIntoSortedDLL(TreeNode<int> *root, TreeNode<int>* &head)
{
	if(root == NULL)
		return ;

	convertIntoSortedDLL(root -> right, head);

	root -> right = head;

	if(head != NULL)
		head -> left = root;

	head = root ;

	convertIntoSortedDLL(root -> left, head);
}

TreeNode<int> *mergeBothDLL(TreeNode<int> *head1, TreeNode<int> *head2)
{
	TreeNode<int> *head = new TreeNode<int>(-1);
	TreeNode<int> *curr = head;
	
	while(head1 != NULL && head2 != NULL)
	{
		if(head1 -> data < head2 -> data)
		{
			curr -> right = head1;
			head1 -> left = curr;
			head1 = head1 -> right;
		}
		else
		{
			curr -> right = head2;
			head2 -> left = curr;
			head2 = head2 -> right;
		}
		curr = curr -> right;
	}
	
	if(head1) 
	{
		curr -> right = head1;
		head1 -> left = curr;
	}
	
	if(head2)
	{
		curr -> right = head2;
		head2 -> left = curr;
	}
	
	head -> right -> left = NULL;
	return head -> right;
}

TreeNode<int> *SortedLLtoBST(TreeNode<int>* &head, int n)
{
	if(n <= 0 || head == NULL)
		return NULL;
	
	TreeNode<int> *left = SortedLLtoBST(head, n/2);
	
	TreeNode<int> *root = head;
	root -> left = left;
	head = head -> right;
	
	root -> right = SortedLLtoBST(head, n-n/2-1);
	return root;
}

int countNodes(TreeNode<int> *head)
{
	TreeNode<int> *temp = head;
	int count = 0;
	
	while(temp != NULL)
	{
		count++;
		temp = temp -> right;
	}
	return count;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
	// convert BST into Sorted Linked List
	TreeNode<int> *head1 = NULL;
	convertIntoSortedDLL(root1, head1);
	head1 -> left = NULL;
	
	TreeNode<int> *head2 = NULL;
	convertIntoSortedDLL(root2, head2);
	head2 -> left = NULL;
	
	// Merge both the Sorted Linked Lists
	TreeNode<int> *head = mergeBothDLL(head1, head2);
	
	// Construct BST from the Merged Linked List
	return SortedLLtoBST(head, countNodes(head));
}