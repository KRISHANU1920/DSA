// Queue Implementation Using Array

#include <iostream>
using namespace std;

class Queue
{
    private:
        int *arr;
        int front;
        int rear;
        int size;
    
    public:
        Queue(int len)
        {
            this -> size = len;
            arr = new int[len];
            front = 0;
            rear = 0;
        }

        void push(int data)
        {
            // Queue Overflow
            if(rear == size)
                cout << "Queue Overflow" << endl << endl;
            else
            {
                arr[rear] = data;
                rear++;
            }
        }

        void pop()
        {
            // Queue Underflow
            if(front == rear)
                cout << "Queue Underflow" << endl << endl;
            else 
            {
                arr[front] = -1;
                front++;
                
                if(front == rear) {
                    front = 0;
                    rear = 0;
                }
            }
        }

        int Front()
        {
            // if Queue is empty
            if(front == rear)
                return -1;
            else
                return arr[front];
        }

        int Back()
        {
            // if Queue is empty
            if(front == rear)
                return -1;
            else
                return arr[rear-1];
        }

        bool Empty()
        {
            if(front == rear)
                return true;
            else
                return false;
        }

        int Size()
        {
            return (rear - front);
        }
};

int main()
{
    // creating a queue
    Queue q(3);

    // pushing values at the end
    q.push(5);
    q.push(10);
    q.push(15);

    // checking size of queue
    cout << "Size of the queue: " << q.Size() << endl << endl;

    // checking front and back of queue
    cout << "front of queue: " << q.Front() << endl;
    cout << "Back of queue: " << q.Back() << endl << endl;

    // poping elements from the front
    q.pop();
    q.pop();

    cout << "front of queue: " << q.Front() << endl;
    cout << "Back of queue: " << q.Back() << endl << endl;

    q.pop();
    q.pop();

    // checking if queue is empty
    if(q.Empty())
        cout << "Queue is Empty" << endl;
    else
        cout << "Queue is not Empty" << endl;

    return 0;
}

// Time Complexity of all the operations in a Queue is constant i.e. O(1).