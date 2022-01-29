// Question Link : https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559

bool isPossible(vector<int> &stalls, int k, int mid)
{
    int cowCount = 1, lastPos = stalls[0];
    for(int i=1; i<stalls.size(); i++)
    {
        if(stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if(cowCount == k)
                return true;
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int l = 0, maxi = stalls[0], res;
    for(int i=1; i<stalls.size(); i++)
        if(maxi < stalls[i])
            maxi = stalls[i];
    int r = maxi;
    sort(stalls.begin(), stalls.end());
    while(l <= r)
    {
        int mid = l + (r - l)/2;
        if(isPossible(stalls, k, mid))
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return res;
}

/*

Time Complexity: O(Nlog(N))
Space Complexity: O(1)

*/