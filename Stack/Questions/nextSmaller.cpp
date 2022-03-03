// Question Link : https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1/#

vector<int> help_classmate(vector<int> arr, int n) 
{ 
    vector<int> ans(n);
    stack<int> st;
    
    st.push(-1);
    
    for(int i=n-1; i>=0; i--)
    {
        int curr = arr[i];
        while(curr <= st.top())
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    
    return ans;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/