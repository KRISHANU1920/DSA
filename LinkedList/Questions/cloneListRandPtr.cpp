// Question Link : https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

// Approach 1: Using Mapping
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

Node *copyList(Node *head)
{
    Node *cloneHead = NULL, *cloneTail = NULL;
    Node *originalHead = head;
    
    // cloning the original list
    while(originalHead != NULL)
    {
        insertAtTail(cloneHead, cloneTail, originalHead -> data);
        originalHead = originalHead -> next;
    }
    
    Node *head1 = head;
    Node *head2 = cloneHead;
    
    // creating mapping
    unordered_map<Node*, Node*> mapping;
    while(head1 != NULL)
    {
        mapping[head1] = head2;
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    
    head1 = head;
    head2 = cloneHead;
    
    // cloning random pointers
    while(head1 != NULL)
    {
        head2 -> arb = mapping[head1 -> arb];
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    
    return cloneHead;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/

// Appoach 2: Changing Links
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

Node *copyList(Node *head)
{
    Node *cloneHead = NULL, *cloneTail = NULL;
    
    // cloning the original list
    Node *temp = head;
    while(temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    }
    
    // inserting between original list
    Node *originalNode = head;
    Node *cloneNode = cloneHead;
    while(originalNode != NULL)
    {
        temp = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = temp;
        
        temp = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode = temp;
    }
    
    // copying random pointers
    temp = head;
    while(temp != NULL)
    {
        if(temp -> next != NULL) {
            if(temp -> arb != NULL)
                temp -> next -> arb = temp -> arb -> next;
            else
                temp -> next -> arb = temp -> arb;  // NULL
        }
        temp = temp -> next -> next;
    }
    
    // revert back to original state
    originalNode = head;
    cloneNode = cloneHead;
    while(originalNode != NULL)
    {
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;
        
        if(originalNode != NULL)
            cloneNode -> next = originalNode -> next;
            
        cloneNode = cloneNode -> next;
    }
    
    // return clone list
    return cloneHead;
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/