// Question Link : https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

void solve(Node *root, int len, int sum, int &maxLen, int &maxSum)
{
    if(root == NULL)
    {
        if(len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return ;
    }
    
    sum += root -> data;
    
    solve(root -> left, len+1, sum, maxLen, maxSum);
    solve(root -> right, len+1, sum, maxLen, maxSum);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int len = 0, sum = 0, maxLen = 0, maxSum = 0;
    
    solve(root, len, sum, maxLen, maxSum);
    
    return maxSum;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/