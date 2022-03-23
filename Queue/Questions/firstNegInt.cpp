// Question Link : https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
                                                 
    deque<int> dq;
    vector<long long> ans;
    
    // processing first window
    for(int i=0; i<K; i++)
    {
        if(A[i] < 0)
            dq.push_back(i);
    }
    
    // storing ans for first window
    if(!dq.empty())
        ans.push_back(A[dq.front()]);
    else
        ans.push_back(0);
        
    // processing remaining windows
    for(int i=K; i<N; i++)
    {
        // removal
        if(!dq.empty() && i-dq.front() >= K)
            dq.pop_front();
        
        // adding
        if(A[i] < 0)
            dq.push_back(i);
        
        // storing ans for curr window
        if(!dq.empty())
            ans.push_back(A[dq.front()]);
        else
            ans.push_back(0);
    }
    
    return ans;                                        
 }

/*

Time Complexity: O(N)
Space Complexity: O(K)

*/