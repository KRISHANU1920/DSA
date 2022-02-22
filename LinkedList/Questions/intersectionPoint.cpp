// Question Link : https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#

int intersectPoint(Node* head1, Node* head2)
{
    Node *h1 = head1, *h2 = head2;
    int count1 = 0, count2 = 0;
    
    // counting number of nodes of list1
    while(h1 != NULL)
    {
        h1 = h1 -> next;
        count1++;
    }
    
    // counting number of nodes of list2
    while(h2 != NULL)
    {
        h2 = h2 -> next;
        count2++;
    }
    
    // difference in length
    int diff = abs(count1 - count2);
    
    h1 = head1, h2 = head2;
    
    // equalize length of both list by skipping larger list nodes
    if(count1 < count2) {
        for(int i=0; i<diff; i++)
            h2 = h2 -> next;
    }
    else {
        for(int i=0; i<diff; i++)
            h1 = h1 -> next;
    }
    
    // finding Intersection point
    while(h1 != NULL)
    {
        if(h1 == h2)
            return h1 -> data;
        h1 = h1 -> next;
        h2 = h2 -> next;
    }
    return -1;
}

/*

Time Complexity: O(M+N)
Space Complexity: O(1)

*/