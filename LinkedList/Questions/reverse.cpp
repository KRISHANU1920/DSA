// Question Link : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1/

// Iterative Approach:
struct Node* reverseList(struct Node *head)
{
    struct Node *prev = NULL, *next = NULL, *curr = head;
    while(curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/

// Recursive Approach:
struct Node* reverseList(struct Node *head)
{
    // base case
    if(head == NULL || head -> next == NULL)
        return head;
        
    // recursive call for rest part  
    Node* rest = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return rest;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/