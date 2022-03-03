// Question Link : https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=1

#include <stack>
int findMinimumCost(string S) 
{
    // if length is odd then not possible
    if(S.size() & 1)
        return -1;

    stack<char> st;
    for(int i=0; i<S.size(); i++)
    {
        char ch = S[i];
        if(ch == '{')
            st.push(ch);
        else {
            if(!st.empty() && st.top() == '{')
                st.pop();
            else
                st.push(ch);
        }
    }
    
    // counting number of swaps needed
    int a = 0, b = 0;
    while(!st.empty())
    {
        if(st.top() == '{')
            a++;
        else
            b++;

        st.pop();
    }
    return (a+1)/2 + (b+1)/2;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/