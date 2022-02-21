// Question Link : https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#

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

void insertAtTail(Node* &head, Node* &tail, int val)
{
    Node* temp = new Node(val);
    if(head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    else {
        tail -> next = temp;
        tail = temp;
    }
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    Node *ansHead = NULL, *ansTail = NULL;
    int carry = 0;
    
    // reverse both the lists
    first = reverse(first);
    second = reverse(second);
    
    // adding two lists
    while(first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if(first != NULL)
            val1 = first -> data;
        
        int val2 = 0;
        if(second != NULL)
            val2 = second -> data;
        
        int sum = carry + val1 + val2;
        int digit = sum % 10;
        
        insertAtTail(ansHead, ansTail, digit);
        
        carry = sum / 10;
        
        if(first != NULL)
            first = first -> next;
        if(second != NULL)
            second = second -> next;
    }
    
    ansHead = reverse(ansHead);
    return ansHead;
}

/*

Time Complexity: O(M+N)
Space Complexity: O(max(M,N))

*/