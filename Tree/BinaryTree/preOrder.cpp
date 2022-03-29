// Question Link : https://practice.geeksforgeeks.org/problems/preorder-traversal/1

// Iterative Approach
vector <int> preorder(Node* root)
{
    vector<int> ans;
    stack<Node*> s;
    
    Node *curr = root;
    
    // if the curr node is NULL and the stack is empty, then we are done
    while(!s.empty() || curr != NULL)
    {
        // if the curr node exist then push it into the stack 
        // print the value and update curr to its left
        if(curr != NULL)
        {
            s.push(curr);
            ans.push_back(curr -> data);
            curr = curr -> left;
        }
        else
        {
            // if curr is NULL then update curr to top of stack
            // pop the stack and update curr to right
            curr = s.top();
            s.pop();
            curr = curr -> right;
        }
    }
    return ans;
}


// Recursive Approach
void solve(Node* root, vector<int> &ans)
{
    // base case
    if(root == NULL)
        return ;
        
    ans.push_back(root -> data);
    solve(root -> left, ans);
    solve(root -> right, ans);
}
vector <int> preorder(Node* root)
{
    vector<int> ans;
    solve(root, ans);
    return ans;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/