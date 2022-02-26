// Question Link : https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/

void solve(stack<int>& inputStack, int count, int size)
{
    // base case
    if(count == size/2) {
        inputStack.pop();
        return ;
    }
    
    int num = inputStack.top();
    inputStack.pop();
    
    // Recursive Call
    solve(inputStack, count+1, size);
    
    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N)
{
    int count = 0;
    solve(inputStack, count, N);
}

/*

Time Complexity: O(N)
Space Complexity: O(N)


Note: Deletion of Middle element can be done in O(1) Time by implementing
       the stack using Doubly LinkedList.

*/