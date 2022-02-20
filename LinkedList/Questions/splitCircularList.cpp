// Question Link : https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1#

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow = head, *fast = head;
    *head1_ref = head;
    while(fast -> next != head && fast -> next -> next != head)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    *head2_ref = slow -> next;
    slow -> next = *head1_ref;
    
    Node *temp = *head2_ref;
    while(temp -> next != head) {
        temp = temp -> next;
    }
    temp -> next = *head2_ref;
}

/* 

Time Complexity: O(N)
Space Complexity: O(1)

*/