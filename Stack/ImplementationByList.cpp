// Stack Implementation using Array
#include <iostream>
using namespace std;

class Node
{
    // properties
    public:
        int data;
        Node *next;
    
    // behaviour
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

Node *top = NULL;
int size = 0;

void push(int value)
{
    Node *temp = new Node(value);

    // if memory is full then return
    if(!temp) {
        cout << "Stack OverFlow !!" << endl;
        return;
    }
    if(!top) {
        top = temp;
    }
    else {
        temp -> next = top;
        top = temp;
    }
    size++;
}

void pop()
{
    if(!top) {
        cout << "Stack UnderFlow !!" << endl;
        return;
    }

    Node *temp = top;
    top = top -> next;
    size--;

    // free memory
    delete temp;
}

int peek()
{
    if(top != NULL)
        return top -> data;
    else {
        cout << "Stack is Empty !!" << endl;
        return -1;
    }
}

bool empty()
{
    if(top == NULL)
        return true;
    else
        return false;
}

int Size()
{
    return size;
}

int main()
{
    // creating stack

    // pushing operation   [TC: O(1)]
    push(4);
    push(19);
    push(23);

    // push(40);
    // push(69);   
    // push(90);
    
    // display stack size   [TC: O(1)]
    cout << "Size of stack: " << Size() << endl;
    
    // displaying top/peek and poping    [TC: O(1)]
    cout << "Element at Top: " << peek() << endl;
    pop();

    cout << "Element at Top: " << peek() << endl;
    pop();
    
    cout << "Element at Top: " << peek() << endl;
    pop();

    // check if stack is empty      [TC: O(1)]
    if(empty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;
    
    // check underflow
    pop();

    cout << "Size of stack: " << Size() << endl;

    return 0;
}