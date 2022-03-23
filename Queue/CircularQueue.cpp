// Circular Queue Implementation using Array
class CircularQueue{
    public:
    	int *arr;
    	int front;
    	int rear;
    	int size;
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. 
    // Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // check if queue is full
        if((front == 0 && rear == size-1) || (front == rear + 1))
        {
            // Queue is full
            return false;
        }
        
        // if queue is empty
        if(front == -1)
        {
            front = rear = 0;
        }
        // to maintain circular nature
        else if(rear == size-1 && front != 0) {
            rear = 0;
        }
        // normal case
        else
            rear++;
        
        arr[rear] = value;
        return true;        
    }

    // Dequeues top element from queue. 
    // Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // check if queue is empty
        if(front == -1) {
            // Queue is empty
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
            
        // if only 1 element present
        if(front == rear) {
            front = rear = -1;
        }
        // to maintain circular nature
        else if(front == size - 1) {
            front = 0;
        }
        // normal case
        else
            front++;
        
        return ans;
    }
};