// Question Link : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

struct node *reverse (struct node *head, int k)
{ 
    if(head == NULL)
        return NULL;
    node *prev = NULL, *curr = head, *temp = NULL;
    int count = 1;
    while(curr != NULL && count <= k)
    {
        temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
        count++;
    }
    node *rest = reverse(curr, k);
    head -> next = rest;
    return prev;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/