// Question Link : https://www.codingninjas.com/codestudio/problems/count-triplets-in-a-sorted-doubly-linked-list-whose-sum-is-equal-to-a-given-value-x_985286?leftPanelTab=1

int countTriplets(DLLNode* head, int x)
{
    DLLNode *tail = head, *first = head;
	int count = 0;
	
	while(tail -> next != NULL)
		tail = tail -> next;
	
	while(first -> next -> next != NULL)
	{
		DLLNode *second = first -> next;
		DLLNode *third = tail;
		
		while(second != third && second -> prev != third)
		{
			int sum = first -> data + second -> data + third -> data;
			
			if(sum == x)
			{
				count++;
				second = second -> next;
				third = third -> prev;
			}
			else if(sum < x)
				second = second -> next;
			else
				third = third -> prev;
		}
		first = first -> next;
	}
	return count;
}  

/*

Time Complexity: O(N^2)
Space Complexity: O(1)

*/