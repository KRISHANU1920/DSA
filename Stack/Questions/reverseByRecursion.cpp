// Question Link : https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1

// Reversing a Stack using Recursion (Extra O(N) Space)
void insertAtBottom(stack<int> &stack, int element)
{
    // base case
    if(stack.empty())
    {
        stack.push(element);
        return;
    }
    
    int top = stack.top();
    stack.pop();
    
    // Recursive call
    insertAtBottom(stack, element);
    
    stack.push(top);
}

void reverseStack(stack<int> &stack) 
{
    // base case
    if(stack.empty())
        return;
    
    int num = stack.top();
    stack.pop();
    
    // recursive call to reverse rest elements
    reverseStack(stack);
    
    // insert the top element at the bottom of the reversed stack
    insertAtBottom(stack, num);
}

/*

Time Complexity: O(N^2)
Space Complexity: O(N)

Note: We can reverse the stack in O(1) space by implementing 
      the stack using linked lists

*/