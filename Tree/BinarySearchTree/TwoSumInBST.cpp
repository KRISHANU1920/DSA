// Question Link : https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1/

void inorder(struct Node *root, vector<int> &in)
{
    if(root == NULL)
        return ;
    
    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

int isPairPresent(struct Node *root, int target)
{
    vector<int> inorderVal;
    
    inorder(root, inorderVal);
    
    int i=0, j=inorderVal.size()-1;
    
    while(i < j)
    {
        int sum = inorderVal[i] + inorderVal[j];
        
        if(sum == target)
            return 1;
        
        else if(sum < target)
            i++;
        
        else
            j--;
    }
    return 0;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/