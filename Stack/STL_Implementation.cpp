// Stack Implementation by STL
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // creating stack
    stack<int> st;

    // pushing operation   [TC: O(1)]
    st.push(4);
    st.push(19);
    st.push(23);
    
    // display stack size   [TC: O(1)]
    cout << "Size of stack: " << st.size() << endl;
    
    // displaying top and poping    [TC: O(1)]
    cout << st.top() << endl;
    st.pop();

    cout << st.top() << endl;
    st.pop();
    
    cout << st.top() << endl;
    st.pop();

    // check if stack is empty      [TC: O(1)]
    if(st.empty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    return 0;
}