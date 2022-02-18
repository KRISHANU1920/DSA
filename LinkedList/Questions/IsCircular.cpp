// Question Link : https://practice.geeksforgeeks.org/problems/circular-linked-list/1

bool isCircular(Node *head)
{
   if(head == NULL)
        return true;
        
   Node *curr = head;
   while(curr -> next != NULL)
   {
       curr = curr -> next;
       if(curr == head)
            return true;
   }
   return false;
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/