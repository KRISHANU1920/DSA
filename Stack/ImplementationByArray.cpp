// Stack Implementation using Array
#include <iostream>
using namespace std;

class Stack
{
    // properties
    public:
        int *arr;
        int top;
        int size;

    // behaviour
    Stack(int size)
    {
        this -> size = size;
        arr = new int(size);
        top = -1;
    }

    void push(int data)
    {
        if(size - top > 1) {
            top++;
            arr[top] = data;
        }
        else
            cout << "Stack OverFlow !!" << endl;
    }

    void pop()
    {
        if(top >= 0)
            top--;
        else 
            cout << "Stack UnderFlow !!" << endl;
    }

    int peek()
    {
        if(top >= 0)
            return arr[top];
        else {
            cout << "Stack is Empty !!" << endl;
            return -1;
        }
    }

    bool empty()
    {
        if(top == -1)
            return true;
        else
            return false;
    }

    int Size()
    {
        return size;
    }
};

int main()
{
    // creating stack
    Stack st(5);

    // pushing operation   [TC: O(1)]
    st.push(4);
    st.push(19);
    st.push(23);
    
    // st.push(40);
    // st.push(69);   
    // st.push(90);   causes Overflow
    
    // display stack size   [TC: O(1)]
    cout << "Size of stack: " << st.Size() << endl;
    
    // displaying top/peek and poping    [TC: O(1)]
    cout << "Element at Top: " << st.peek() << endl;
    st.pop();

    cout << "Element at Top: " << st.peek() << endl;
    st.pop();
    
    cout << "Element at Top: " << st.peek() << endl;
    st.pop();

    // check if stack is empty      [TC: O(1)]
    if(st.empty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;
    
    // check underflow
    st.pop();

    return 0;
}