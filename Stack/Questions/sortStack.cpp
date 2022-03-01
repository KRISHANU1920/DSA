// Question Link : https://practice.geeksforgeeks.org/problems/sort-a-stack/1#

void sortedInsert(stack<int> &s, int num)
{
    // base case
    if(s.empty() || s.top() < num)
    {
        s.push(num);
        return;
    }
    
    int n = s.top();
    s.pop();
    
    // Recursive call
    sortedInsert(s, num);
    
    s.push(n);
}

void SortedStack :: sort()
{
    // base case
    if(s.empty())
        return;
    
    int n = s.top();
    s.pop();
    
    // Recursive call
    sort();
    
    // insert the top element into correct position
    sortedInsert(s, n);
}

/*

Time Complexity: O(N^2)
Space Complexity: O(N)

*/