// Question Link : https://practice.geeksforgeeks.org/problems/check-for-bst/1

// Approach 1: Traverse the whole tree InOrder and store the elements accordingly into a vector. 
//             Then Check if the vector is sorted or not. Tree is BST if vector is sorted.



// Approach 2: Checking by range
bool solve(Node* root, int min, int max)
    {
        // base case
        if(root == NULL)
            return true;
        
        if(root -> data > min && root -> data < max)
        {
            bool left = solve(root -> left, min, root -> data);
            bool right = solve(root -> right, root -> data, max);
            
            return (left && right);
        }
        return false;
    }
    
    bool isBST(Node* root) 
    {
        return solve(root, INT_MIN, INT_MAX);
    }

/*

Time Complexity: O(N)
Space Complexity: O(Height)

*/