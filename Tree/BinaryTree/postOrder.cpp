// Question Link : https://practice.geeksforgeeks.org/problems/postorder-traversal/1

// Iterative Approach
vector <int> postOrder(Node* root)
{
    vector<int> ans;
    stack<Node*> s;

    Node *curr = root;
    Node *prev = NULL;

    while(!s.empty() || curr != NULL)
    {
        // if the curr node exist then push it into the stack 
        // and update curr to its left
        if(curr != NULL)
        {
            s.push(curr);
            curr = curr -> left;
        }
        else
        {
            // if curr is NULL then update curr to top of stack
            curr = s.top();
            
            // if curr -> right is null or equal to prev then
            // print ans, pop stack, update prev and curr 
            if(curr -> right == NULL || curr -> right == prev)
            {
                ans.push_back(curr -> data);
                s.pop();
                prev = curr;
                curr = NULL;
            }
            else 
            {
                // update curr to right
                curr = curr -> right;
            }
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
    
    solve(root -> left, ans);
    solve(root -> right, ans);
    ans.push_back(root -> data);
}

vector <int> postOrder(Node* root)
{
    vector<int> ans;
    solve(root, ans);
    return ans;
}


/*

Time Complexity: O(N)
Space Complexity: O(N)

*/