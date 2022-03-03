// Question Link : https://leetcode.com/problems/largest-rectangle-in-histogram/

vector<int> nextSmallest(vector<int>& heights, int n)
{
    vector<int> ans(n);
    stack<int> st;
    
    st.push(-1);
    for(int i=n-1; i>=0; i--)
    {
        int curr = heights[i];
        while(st.top() != -1 && curr <= heights[st.top()])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallest(vector<int>& heights, int n)
{
    vector<int> ans(n);
    stack<int> st;
    
    st.push(-1);
    for(int i=0; i<n; i++)
    {
        int curr = heights[i];
        while(st.top() != -1 && curr <= heights[st.top()])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) 
{
    int n = heights.size();
    int maxArea = INT_MIN, currArea = INT_MIN;
    
    vector<int> next(n);
    next = nextSmallest(heights, n);
    
    vector<int> prev(n);
    prev = prevSmallest(heights, n);
    
    for(int i=0; i<n; i++)
    {
        int length = heights[i];
        
        if(next[i] == -1)
            next[i] = n;
        
        int breadth = next[i] - prev[i] - 1;
        currArea = length * breadth;
        maxArea = max(maxArea, currArea);
    }
    return maxArea;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/