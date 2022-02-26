// Question Link : https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

class twoStacks
{
    public:
        int *arr;
        int top1;
        int top2;
        int size;
    
    twoStacks(int size)
    {
        this -> size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};

//Function to push an integer into the stack1.
void twoStacks :: push1(int x)
{
    if(top2 - top1 > 1) {
        top1++;
        arr[top1] = x;
    }
    else
        cout << "Stack OverFlow!!"  << endl;
}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    if(top2 - top1 > 1) {
        top2--;
        arr[top2] = x;
    }
    else
        cout << "Stack OverFlow!!" << endl;
}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    if(top1 >= 0) {
        int ans = arr[top1];
        top1--;
        return ans;
    }
    else
        return -1;  // underFlow
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    if(top2 < size) {
        int ans = arr[top2];
        top2++;
        return ans;
    }
    else
        return -1;  // underFlow
}

/*

All Operations:-
    Time Complexity: O(1)
    Space Complexity: O(1)

*/