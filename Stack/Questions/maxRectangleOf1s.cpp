// Question Link : https://practice.geeksforgeeks.org/problems/max-rectangle/1/#

int* nextSmaller(int *arr, int m)
{
    int *ans = new int[m];
    stack<int> st;
    
    st.push(-1);
    
    for(int i=m-1; i>=0; i--)
    {
        int curr = arr[i];
        
        while(st.top() != -1 && curr <= arr[st.top()]) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int* prevSmaller(int *arr, int m)
{
    int *ans = new int[m];
    stack<int> st;
    
    st.push(-1);
    
    for(int i=0; i<m; i++)
    {
        int curr = arr[i];
        
        while(st.top() != -1 && curr <= arr[st.top()]) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(int *arr, int m)
{
    int maxArea = INT_MIN;
    
    int *next = new int[m];
    next = nextSmaller(arr, m);
    
    int *prev = new int[m];
    prev = prevSmaller(arr, m);
    
    for(int i=0; i<m; i++)
    {
        int length = arr[i];
        if(next[i] == -1)
            next[i] = m;
        
        int breadth = next[i] - prev[i] - 1;
        int currArea = length * breadth;
        maxArea = max(maxArea, currArea);
    }
    
    delete [] next;
    delete [] prev;
    
    return maxArea;
}

int maxArea(int M[MAX][MAX], int n, int m) 
{
    // calulate area of first row
    int area = largestRectangleArea(M[0], m);
    
    // calculate area of remaining rows
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            // update curr row by adding prev row's value
            if(M[i][j] != 0)
                M[i][j] = M[i][j] + M[i-1][j];
            else
                M[i][j] = 0;
        }
        // entire row is updated now
        int newArea = largestRectangleArea(M[i], m);
        area = max(area, newArea);
    }
    return area;
}

/*

Time Complexity: O(n*m)
Space Complexity: O(m)

*/