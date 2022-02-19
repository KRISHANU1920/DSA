// Question Link : https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

Node *removeDuplicates(Node *head)
{
    // Empty List
    if(head == NULL)
        return NULL;
    
    // Non-Empty List
    Node *curr = head;
    while(curr && curr -> next)
    {
        if((curr -> data) == (curr -> next -> data)) {
            Node* temp = curr -> next;
            curr -> next = curr -> next -> next;
            delete temp;
        }
        else
            curr = curr -> next;
    }
    return head;
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/