// Question Link : https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#

Node* merge(Node* down, Node* right)
{
    if(!down)
        return right;
    if(!right)
        return down;
    
    Node *ans = new Node(-1);
    Node *temp = ans;
    
    while(down && right)
    {
        if(down -> data <= right -> data) {
            temp -> bottom = down;
            temp = down;
            down = down -> bottom;
        }
        else {
            temp -> bottom = right;
            temp = right;
            right = right -> bottom;
        }
    }
    
    if(down)
        temp -> bottom = down;
    
    if(right)
        temp -> bottom = right;
    
    ans = ans -> bottom;
    return ans;
}
    
Node *flatten(Node *root)
{
    // base case
   if(root == NULL)
       return root;
       
   Node *down = root;
   // recursive call for right part
   Node *right = flatten(root -> next);
   
   // merge sortd down and right part
   Node *ans = merge(down, right);
   
   return ans;
}

/*

Time Complexity: O(N.M)
Space Complexity: O(N)

*/