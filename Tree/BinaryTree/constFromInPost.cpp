// Question Link : https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1/#

Node* solve(int in[], int post[], int n, int &index, int inStart,
                    int inEnd, unordered_map<int, int> &mapInOrder)
{
    // base case
    if(index < 0 || inStart > inEnd)
        return NULL;
    
    // creating Root Node for element
    int element = post[index--];
    Node *root = new Node(element);
    
    // find position of element in inOrder
    int pos = mapInOrder[element];
    
    // recursive calls [In case of PostOrder & inOrder, we first build right subtree]
    root -> right = solve(in, post, n, index, pos+1, inEnd, mapInOrder);
    root -> left = solve(in, post, n, index, inStart, pos-1, mapInOrder);
    
    return root;
}

Node* buildTree(int in[],int post[], int n)
{
    int postOrderIndex = n-1;
    unordered_map<int, int> mapInOrder;
    
    for(int i=0; i<n; i++)
        mapInOrder[in[i]] = i;
        
    Node *ans = solve(in, post, n, postOrderIndex, 0, n-1, mapInOrder);
    return ans;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/