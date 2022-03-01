// Question Link : https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

bool ispar(string x)
{
    stack<char> st;
    
    for(int i=0; i<x.size(); i++)
    {
        char ch = x[i];
        // if opening bracket then push in stack
        if(ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else {
            // if closing bracket then match and pop
            if(!st.empty())
            {
                char top = st.top();
                if((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '['))
                {
                    st.pop();
                }
                else
                    return false;
            }
            else
                return false;
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/