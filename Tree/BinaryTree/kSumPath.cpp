// Question Link : https://practice.geeksforgeeks.org/problems/k-sum-paths/1/#

void solve(Node *root, int k, int &count, vector<int> path)
{
    if(root == NULL)
        return ;
    
    // store current node value in path vector
    path.push_back(root -> data);
    
    // left subtree call
    solve(root -> left, k, count, path);
    
    // right subtree call
    solve(root -> right, k, count, path);
    
    int Size = path.size();
    int sum =0;
    
    // checking for k sum path
    for(int i=Size-1; i>=0; i--)
    {
        sum += path[i];
        if(sum == k)
            count++;
    }
    
    // path.pop_back();  if path is passed by reference
}

int sumK(Node *root,int k)
{
    vector<int> path;
    int count = 0;
    
    solve(root, k, count, path);
    
    return count;
}

/*

Time Complexity: O(N.Height)
Space Complexity: O(Height)

*/