// Question Link : https://practice.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1/#

void deleteNode(struct Node **head, int key)
{
    Node *curr = *head;
    
    while(curr -> next != *head)
    {
        if(curr -> next -> data == key)
        {
            curr -> next = curr -> next -> next;
            return;
        }
        curr = curr -> next;
    }
}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{
    Node *curr = *head_ref, *prev = NULL, *succ = NULL;
    
    while(curr -> next != *head_ref)
    {
        succ = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = succ;
    }
    curr -> next -> next = curr;
    curr -> next = prev;
    *head_ref = curr;
    
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/