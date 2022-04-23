// Question Link : https://www.codingninjas.com/codestudio/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{  
    BinaryTreeNode<int> *temp = root;
    int pre = -1, suc = -1;
    
    while(temp -> data != key)
    {
        if(temp -> data < key)
        {
            pre = temp -> data;
            temp = temp -> right;
        }
        else
        {
            suc = temp -> data;
            temp = temp -> left;
        }
    }
    
    // finding Inorder Predecessor
    BinaryTreeNode<int>* leftSubtree = temp -> left;
    while(leftSubtree != NULL)
    {
        pre = leftSubtree -> data;
        leftSubtree = leftSubtree -> right;
    }
    
    // finding Inorder Successor
    BinaryTreeNode<int>* rightSubtree = temp -> right;
    while(rightSubtree != NULL)
    {
        suc = rightSubtree -> data;
        rightSubtree = rightSubtree -> left;
    }
	return {pre, suc};
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/