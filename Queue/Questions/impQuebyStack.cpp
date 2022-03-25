// Question Link : https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1#

// Approach 1: By making push operation costly
void StackQueue :: push(int x)
{
    // fetch elements from s1 and put to s2 till s1 becomes empty
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    
    // push new element in s1
    s1.push(x);
    
    // fetch back the elements in s2 and put into s1 till s2 becomes empty
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

int StackQueue :: pop()
{
    if(s1.empty())
        return -1;
    
    int val = s1.top();
    s1.pop();
    
    return val;
}

/*

Time Complexity: push-O(N) and pop-O(1)
Space Complexity: O(N)

*/


// Approach 2: By making pop operation costly
void StackQueue :: push(int x)
{
    // push element in s1
    s1.push(x);
}

int StackQueue :: pop()
{
    // if both stacks are empty then underflow
    if(s1.empty() && s2.empty())
        return -1;
    
    // if stack2 is empty
    if(s2.empty()) 
    {
        // fetch elements from s1 and put in s2 till s1 becomes empty
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    // store top value of s2 and return
    int val = s2.top();
    s2.pop();
    
    return val;
}

/*

Time Complexity: push-O(1) and pop-O(N)
Space Complexity: O(N)

    Method 2 is definitely better than method 1. 
    Method 1 moves all the elements twice in enQueue operation, while method 2 (in deQueue operation)
    moves the elements once and moves elements only if stack2 empty. So, the amortized complexity of
    the dequeue operation becomes Theta(1)

*/


// Approach 3: Recursive approach for approach 2 using one user stack and one function call stack
void StackQueue :: push(int x)
{
    // push element in stack1
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    // base case for empty stack
    if(s1.empty())
        return -1;
    
    // store and pop current top element of s1
    int x = s1.top();
    s1.pop();
    
    // base case for stack having single element
    if(s1.empty())
        return x;
    
    // recursive call
    int val = pop();
    
    // pusn popped item back to s1
    s1.push(x);
    
    // return ans
    return val;
}

/*

Time Complexity: push-O(1) and pop-O(N)
Space Complexity: O(N)

*/