// Question Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    ListNode *dummy = new ListNode();
    dummy -> next = head;
        
    ListNode *fast = dummy, *slow = dummy;
    
    for(int i=0; i<n; i++)
        fast = fast -> next;
    
    while(fast -> next != NULL)
    {
        fast = fast -> next;
        slow = slow -> next;
    }
    
    ListNode *temp = slow -> next;
    slow -> next = slow -> next -> next;
    delete temp;
    return dummy -> next;
}


/*

Time Complexity: O(N)
Space Complexity: O(1)

*/