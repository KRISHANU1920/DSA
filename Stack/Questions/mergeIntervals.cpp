// Question Link : https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1/#

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) 
{
    vector<vector<int>> ans;
    stack<vector<int>> st;
    
    sort(intervals.begin(), intervals.end());
    
    st.push(intervals[0]);
    
    for(int i=1; i<intervals.size(); i++)
    {
        vector<int> top = st.top();
        
        if(top[1] < intervals[i][0])
        st.push(intervals[i]);
        
        else if(top[1] < intervals[i][1])
        {
            top[1] = intervals[i][1];
            st.pop();
            st.push(top);
        }
    }
    
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}

/*

Time Complexity: O(N.Log(N))
Space Complexity: O(N)

*/