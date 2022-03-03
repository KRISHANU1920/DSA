// Question Link : https://leetcode.com/problems/merge-intervals/

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    vector<int> temp = intervals[0];
    for(int i=1; i<intervals.size(); i++)
    {
        if(temp[1] < intervals[i][0]) {
            ans.push_back(temp);
            temp = intervals[i];
        }
        else {
            temp[1] = max(temp[1], intervals[i][1]);
        }
    }
    ans.push_back(temp);
    return ans;
}

/*
Time Complexity: O(N.Log(N))
Space Complexity: O(Log(N))
*/