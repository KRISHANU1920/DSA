// Question Link : https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=1

#include <stack>
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i=0; i<s.size(); i++)
    {
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            st.push(ch);
        else {
            // if character is ')' or lowercase letter
            if(ch == ')')
            {
                bool isRedundant = true;
                while(st.top() != '(')
                {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/