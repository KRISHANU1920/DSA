// Question Link : https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#

// Approach 1: Using Stack [TC: O(N) and SC: O(N)]
int celebrity(vector<vector<int> >& M, int n) 
{
    // push all elements into stack
    stack<int> st;
    for(int i=0; i<n; i++)
        st.push(i);
    
    // pop two elements compare them and push the possible element
    while(st.size() > 1)
    {
        int a = st.top();
        st.pop();
        
        int b = st.top();
        st.pop();
        
        if(M[a][b] == 1)
            st.push(b);
        else
            st.push(a);
    }
    int ans = st.top();
    
    // Here ans may be a potential celebrity
    // verify ans is celebrity or not
    for(int i=0; i<n; i++) 
    {
        // row check (all should be zero)
        if(M[ans][i] != 0)
            return -1;
        
        // column check (all should be 1 except diagonal)
        if(i != ans && M[i][ans] != 1)
            return -1;
    }
    return ans;
}


// Approach 2: Using Two Pointers [TC: O(N) and SC: O(1)]
int celebrity(vector<vector<int> >& M, int n) 
{
    int i = 0, j = n-1;
    while(i < j)
    {
        if(M[i][j] == 1)
            i++;          // i knows j, i can't be celebrity
        else
            j--;        // i doesn't know j , j can't be a celebrity
    }
    int ans = i;
    
    // Here ans may be a potential celebrity
    // verify ans is celebrity or not
    for(int i=0; i<n; i++) 
    {
        // row check (all should be zero)
        if(M[ans][i] != 0)
            return -1;
        
        // column check (all should be 1 except diagonal)
        if(i != ans && M[i][ans] != 1)
            return -1;
    }
    return ans;
}