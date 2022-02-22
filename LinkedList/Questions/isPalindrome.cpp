// Question Link : https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#

/* Approach 1: Store the elements of the Linked List in an array and 
              check the array is palindrom or not by two pointer method

    Time Complexity: O(N)
    Space Complexity: O(N) */

// Approach 2: Optimized 
Node* reverse(Node* head)
{
    Node *curr = head, *prev = NULL, *forward = NULL;
    while(curr != NULL)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    // searching the middle element
    Node *slow = head, *fast = head -> next;
    while(fast && fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    // creating two halves
    Node *head1 = head;
    Node *head2 = slow -> next;
    head2 = reverse(head2);
    
    // comparing the two halves
    Node *curr1 = head1, *curr2 = head2;
    while(curr2 != NULL)
    {
        if(curr1 -> data != curr2 -> data)
            return false;
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }
    // converting the list back to it's original form (optional)
    slow -> next = reverse(head2);
    
    return true;
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/