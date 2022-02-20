// Question Link : https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

Node * removeDuplicates( Node *head) 
{
    if(head == NULL)
        return NULL;
    map<int, bool> mp;
    Node *curr = head, *prev = NULL;
    while(curr != NULL)
    {
        if(mp[curr->data] == false) {
            mp[curr->data] = true;
            prev = curr;
            curr = curr -> next;
        }
        else {
            prev -> next = curr -> next;
            Node * temp = curr;
            curr = curr -> next;
            delete temp;
        }
    }
    return head;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/