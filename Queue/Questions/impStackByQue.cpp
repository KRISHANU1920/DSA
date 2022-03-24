// Question Link : https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1/

// Approach 1: By making push operation costly
void QueueStack :: push(int x)
{
       // push new element into q2
       q2.push(x);
       
       // fetch elements of q1 & push into q2
       while(!q1.empty())
       {
           q2.push(q1.front());
           q1.pop();
       }
       
       swap(q1, q2);
}
 
int QueueStack :: pop()
{
       if(q1.empty())
           return -1;
       else {
           int ans = q1.front();
           q1.pop();
           return ans;
       }
}

/*

Time Complexity: push-O(N) and pop-O(1)
Space Complexity: push-O(1) and pop-O(1)

*/


// Approach 2: By making pop operation costly
void QueueStack :: push(int x)
{
   // push new element into q1
   q1.push(x);
}
 
int QueueStack :: pop()
{
    if(q1.empty())
        return -1;
    
    // except the last element fetch all elements from
    // q1 and push into q2
    while(q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    
    // store the single element left in q1 as result
    int ans = q1.front();
    q1.pop();
    
    swap(q1, q2);
    
    return ans;
}

/*

Time Complexity: push-O(1) and pop-O(N)
Space Complexity: push-O(1) and pop-O(1)

*/