// Question Link : https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#

Node* reverse(Node *head)
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

Node* addOne(Node *head) 
{
    int carry = 1;
    
    // reverse the list
    head = reverse(head);
    Node *curr = head;

    // adding one to the list
    while(curr != NULL || carry != 0)
    {
        int sum = carry + (curr -> data);
        int digit = sum % 10;
        curr -> data = digit;
        carry = sum / 10;
        
        if((curr -> next == NULL) && carry) {
            Node *temp = new Node(1);
            curr -> next = temp;
            break;
        }
        curr = curr -> next;
    }
    
    // reverse back to get original list 
    head = reverse(head);
    return head;
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/