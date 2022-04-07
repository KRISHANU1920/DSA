// Question Link : https://practice.geeksforgeeks.org/problems/construct-tree-1/1

// Approach 1: Brute Force Normal Approach
int findPosition(int in[], int element, int n)
{
    for(int i=0; i<n; i++)
        if(in[i] == element)
            return i;
    
    return -1;
}

Node* solve(int in[], int pre[], int n, int &index, int inStart, int inEnd)
{
    // base case
    if(index >= n || inStart > inEnd)
        return NULL;
    
    // creating Root Node for element
    int element = pre[index++];
    Node *root = new Node(element);
    
    // find position of element in inOrder
    int pos = findPosition(in, element, n);
    
    // recursive calls
    root -> left = solve(in, pre, n, index, inStart, pos-1);
    root -> right = solve(in, pre, n, index, pos+1, inEnd);
    
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    int preOrderIndex = 0;
    Node *ans = solve(in, pre, n, preOrderIndex, 0, n-1);
    return ans;
}

/*

Time Complexity: O(N^2)
Space Complexity: O(N)

*/


// Approach 2: Optimized Approach using Mapping of inOrder Nodes
Node* solve(int in[], int pre[], int n, int &index, int inStart,
                    int inEnd, unordered_map<int, int> &mapInOrder)
{
    // base case
    if(index >= n || inStart > inEnd)
        return NULL;
    
    // creating Root Node for element
    int element = pre[index++];
    Node *root = new Node(element);
    
    // find position of element in inOrder
    int pos = mapInOrder[element];
    
    // recursive calls
    root -> left = solve(in, pre, n, index, inStart, pos-1, mapInOrder);
    root -> right = solve(in, pre, n, index, pos+1, inEnd, mapInOrder);
    
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    int preOrderIndex = 0;
    unordered_map<int, int> mapInOrder;
    
    for(int i=0; i<n; i++)
        mapInOrder[in[i]] = i;
        
    Node *ans = solve(in, pre, n, preOrderIndex, 0, n-1, mapInOrder);
    return ans;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/