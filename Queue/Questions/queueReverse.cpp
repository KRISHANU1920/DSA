// Question Link : https://practice.geeksforgeeks.org/problems/queue-reversal/1

// Approach 1: Using Stack (TC-O(N) and SC-O(N))
queue<int> rev(queue<int> q)
{
    stack<int> st;
    
    while(!q.empty())
    {
        int element = q.front();
        q.pop();
        st.push(element);
    }
    
    while(!st.empty())
    {
        int element = st.top();
        st.pop();
        q.push(element);
    }
    
    return q;
}

// Approach 2: Using Recursion (TC-O(N) and SC-O(N))
queue<int> rev(queue<int> q)
{
    // base case
    if(q.size() == 1)
        return q;
    
    int element = q.front();
    q.pop();
    
    // recursive call
    q = rev(q);
    
    q.push(element);
    return q;
}