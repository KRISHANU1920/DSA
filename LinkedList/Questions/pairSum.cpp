// Question Link : https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/

// Sorted DLL - By Two Pointers Approach (Optimized)
void pairSum(struct Node *head, int x)
{
    // Set two pointers, first to the beginning of DLL
    // and second to the end of DLL.
    Node *first = head;
    Node *second = head;
    while (second -> next != NULL)
        second = second -> next;
 
    // To track if we find a pair or not
    bool found = false;
 
    // The loop terminates when two pointers
    // cross each other (second->next
    // == first), or they become same (first == second)
    while (first != second && second -> next != first)
    {
        // pair found
        if ((first -> data + second -> data) == x)
        {
            found = true;
            cout << "(" << first->data<< ", "
                << second -> data << ")" << endl;
 
            // move first in forward direction
            first = first -> next;
 
            // move second in backward direction
            second = second -> prev;
        }
        else
        {
            if ((first -> data + second -> data) < x)
                first = first -> next;
            else
                second = second -> prev;
        }
    }
 
    // if pair is not present
    if (found == false)
        cout << "No pair found";
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/


/*

For Un-Sorted DLL

Approach 1: sort first then apply two pointers [TC: O(NlogN), SC: O(1)]
Approach 2: If space is not a constraint then apply Hashing [TC: O(N), SC: O(N)]

*/