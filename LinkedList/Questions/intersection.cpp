// Question Link : https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

void insertAtTail(Node* &head, Node* &tail, int value)
{
    Node *temp = new Node(value);
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

Node* findIntersection(Node* head1, Node* head2)
{
    Node *head = NULL, *tail = NULL;
    while(head1 && head2)
    {
        if(head1 -> data == head2 -> data) {
            insertAtTail(head, tail, head1->data);
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        else if(head1 -> data < head2 -> data)
            head1 = head1 -> next;
        else
            head2 = head2 -> next;
    }
    return head;
}

/*

Time Complexity: O(M+N)
Space Complexity: O(M+N)

*/