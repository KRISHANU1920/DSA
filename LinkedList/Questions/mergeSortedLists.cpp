// Question : https://leetcode.com/problems/merge-two-sorted-lists/

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    ListNode* head = NULL;
    
    // if any list is empty
    if(!list1 && !list2)
        return NULL;
    else if(!list1 && list2)
        return list2;
    else if(list1 && !list2)
        return list1;
    
    // if both are non-empty lists
    if(list1 -> val <= list2 -> val)
    {
        head = list1;
        list1 = list1 -> next;
    }
    else
    {
        head = list2;
        list2 = list2 -> next;
    }
    
    // merging both lists
    ListNode* temp = head;
    while(list1 && list2)
    {
        if(list1 -> val <= list2 -> val)
        {
            temp -> next = list1;
            list1 = list1 -> next;
        }
        else
        {
            temp -> next = list2;
            list2 = list2 -> next;
        }
        temp = temp -> next;
    }
    
    // link remaining elements of larger list
    if(list1)
        temp -> next = list1;
    if(list2)
        temp -> next = list2;
    
    return head;
}

/*
Time Complexity: O(min(list1, list2))
Space Complexity: O(1)
*/