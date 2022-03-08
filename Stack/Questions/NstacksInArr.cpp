// Question Link : https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1

// Note: After giving this question there is high chance that interviewer may 
//      ask questions from Operating System (fragmentation, Memory Management)

class NStack
{
private:
    	int *arr;
        int *top;
        int *next;
        int freeSpot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        arr = new int[S];
        top = new int[N];
        next = new int[S];
        
        for(int i=0; i<N; i++)
            top[i] = -1;
        
        for(int i=0; i<S-1; i++)
            next[i] = i+1;
        next[S-1] = -1;
        
        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Stack Overflow Condition
        if(freeSpot == -1)
            return false;
        
        // get free index from freeSpot
        int index = freeSpot;
        
        // update freeSpot to next free space
        freeSpot = next[index];
        
        // push element to desired stack
        arr[index] = x;
        
        // update next before updating top
        next[index] = top[m-1];
        
        // update top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Stack Underflow Condition
        if(top[m-1] == -1)
            return -1;
        
        // store free space index
        int index = top[m-1];
        
        // update top
        top[m-1] = next[index];
        
        // update next element of stack
        next[index] = freeSpot;
        
        // update Free Space
        freeSpot = index;
        
        return arr[index];
    }
};

/*

Time Complexity: O(1)
Space Complexity: O(S+N)

*/