// Question Link : https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1/

queue<int> modifyQueue(queue<int> q, int k) 
{
    stack<int> st;
    
    // pop first k element from queue and push into stack
    for(int i=0; i<k; i++)
    {
        int val = q.front();
        q.pop();
        st.push(val);
    }
    
    // fetch elements from stack and push into queue
    while(!st.empty())
    {
        int val = st.top();
        st.pop();
        q.push(val);
    }
    
    // fetch first (n-k) elements from queue and push back
    int t = q.size()-k;
    
    while(t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    
    return q;
}

/*

Time Complexity: O(N)
Space Complexity: O(K)

*/