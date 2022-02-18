// Question Link : https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

bool detectLoop(Node* head)
{
    Node *slow = head, *fast = head;
    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
            return true;
    }
    return false;
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/