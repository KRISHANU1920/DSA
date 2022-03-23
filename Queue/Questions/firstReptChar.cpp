// Question Link : https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

string FirstNonRepeating(string A)
{
    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";
    
    for(int i=0; i<A.size(); i++)
    {
        char ch = A[i];
        
        // increase count of character scanned
        count[ch]++;
        
        // push character into queue
        q.push(ch);
        
        while(!q.empty())
        {
            // Repeating character
            if(count[q.front()] > 1)
                q.pop();
            
            // Non-Repeating character
            else {
                ans.push_back(q.front());
                break;
            }
        }
        
        if(q.empty())
            ans.push_back('#');
    }
    
    return ans;
}