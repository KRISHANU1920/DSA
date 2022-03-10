#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // creating a queue
    queue<int> q;
    queue<int> r;

    // pushing values at the end
    q.push(5);
    q.push(10);
    q.push(15);
    q.emplace(20); // constructed inplace (faster than push)

    // checking size of queue
    cout << "Size of the queue: " << q.size() << endl << endl;

    // checking front and back of queue
    cout << "front of queue: " << q.front() << endl;
    cout << "Back of queue: " << q.back() << endl << endl;

    // poping elements from the front
    q.pop();
    q.pop();

    cout << "front of queue: " << q.front() << endl;
    cout << "Back of queue: " << q.back() << endl << endl;

    // checking if queue is empty
    if(q.empty())
        cout << "Queue is Empty" << endl;
    else
        cout << "Queue is not Empty" << endl;

    // swapping values of two queues among them
    swap(q, r);

    cout << "Size of q: " << q.size() << endl;
    cout << "Size of r: " << r.size() << endl;
    cout << q.front() << " " << r.front() << endl;

    return 0;
}

// Time Complexity of all the operations in a Queue is constant i.e. O(1).