// Question Link : https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450?leftPanelTab=1

void interLeaveQueue(queue < int > & q) 
{
    stack<int> s;
    int n = q.size();
    
    // fetch first half elements of queue into stack
    for(int i=0; i<n/2; i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    // push the elements of stack at the back of queue
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
	}
    
    // pop the first half elements of queue and push at the back
    for(int i=0; i<n/2; i++)
    {
        q.push(q.front());
        q.pop();
    }
    
    // push the first half elements of queue into stack
    for(int i=0; i<n/2; i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    // interleaving the stack and queue elements
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/