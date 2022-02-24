// Question Link : https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1#

Node* findMid(Node* head)
{
    Node *slow = head;
    Node *fast = head -> next;
    
    while(fast && fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node* merge(Node* left, Node* right)
{
    if(!left)
        return right;
    
    if(!right)
        return left;
        
    Node *ans = new Node(-1);
    Node *temp = ans;
        
    while(left && right)
    {
        if(left -> data <= right -> data) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    if(left)
        temp -> next = left;
    
    if(right)
        temp -> next = right;
    
    ans = ans -> next;
    return ans;
}

Node* mergeSort(Node* head) 
{
    // base case
    if(head == NULL || head -> next == NULL)
        return head;
    
    // divide list into two halves
    Node *mid = findMid(head);
    
    Node *left = head;
    Node *right = mid -> next;
    mid -> next = NULL;
    
    // sort the left and right halves by recursion
    left = mergeSort(left);
    right = mergeSort(right);
    
    // merge the two sorted halves
    Node *ans = merge(left, right);
    
    return ans;
}

/*

Time Complexity: O(N.Log(N))
Space Complexity: O(Log(N))

*/