// Question Link: https://www.geeksforgeeks.org/efficiently-implement-k-queues-single-array/


// Approach 1: Divide the array into slots of k/n size each


// Approach 2: Space optimized 
#include <bits/stdc++.h>
using namespace std;

class kQueue
{
    private:
        int n;
        int k;
        int *arr;
        int *front;
        int *rear;
        int *next;
        int freeSpot;
    
    public:
        kQueue(int n, int k)
        {
            this -> n = n;
            this -> k = k;

            arr = new int[n];

            front = new int[k];
            rear = new int[k];

            for(int i=0; i<k; i++)
            {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i<n-1; i++)
                next[i] = i+1;
            next[n-1] = -1;

            freeSpot = 0;
        }

        void enQueue(int qn, int x)
        {
            // checking OverFlow
            if(freeSpot == -1)
                cout << "Queue OverFlow" << endl;

            // getting free index
            int index = freeSpot;

            // update freeSpot
            freeSpot = next[index];

            // check if first element
            if(front[qn-1] == -1)
                front[qn-1] = index;
            else {
                // link current element with previous element
                next[rear[qn-1]] = index;
            }
            
            // update next 
            next[index] = -1;

            // update rear
            rear[qn-1] = index;

            // push element into arr
            arr[index] = x;
        }

        int deQueue(int qn)
        {
            // checking UnderFlow
            if(front[qn-1] == -1)
                return -1;
            
            // storing index to the front of queue
            int index = front[qn-1];

            // updating front 
            front[qn-1] = next[index];

            // updating freeSlots
            next[index] = freeSpot;
            freeSpot = index;

            return arr[index];
        }
};

int main()
{
    // creating queue
    kQueue q(5,3);

    // pushing elements into queues
    q.enQueue(1, 5);
    q.enQueue(1, 10);
    q.enQueue(2, 15);
    q.enQueue(3, 20);
    q.enQueue(2, 25);
    q.enQueue(1, 30);

    // poping elements from queues
    cout << endl;
    cout << q.deQueue(1) << endl;
    cout << q.deQueue(3) << endl;
    cout << q.deQueue(1) << endl;
    cout << q.deQueue(2) << endl;
    cout << q.deQueue(2) << endl;
    cout << q.deQueue(1) << endl;
}


/*

 Time Complexity: O(1)
 Space Complexity: O(1)

*/