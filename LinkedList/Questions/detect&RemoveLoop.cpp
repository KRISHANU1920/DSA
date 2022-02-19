// Question Link : https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

void detectAndRemoveLoop(Node* head)
{
    Node *slow = head, *fast = head;
    
    // detecting loop 
    while(fast && fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
            break;
    }
    // if loop not present then return
    if(slow != fast)
        return;
    
    // detecting start of loop
    slow = head;
    while(slow != fast)
    {
        fast = fast -> next;
        slow = slow -> next;
    }
    // currently slow represents start of loop

    // deleting loop
    Node *temp = slow;
    while(temp -> next != slow) {
        temp = temp -> next;
    }
    temp -> next = NULL;
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/