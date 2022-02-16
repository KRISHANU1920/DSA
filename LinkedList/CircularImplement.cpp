#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        // Constructor
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }

        // Destructor
        ~Node() {
            if(this -> next != NULL) {
                delete next;
                this -> next = NULL;
            }
            cout << "Memory freed for Node with value " << this -> data << endl;
        }
};

void insertNode(Node* &tail, int element, int d)
{
    Node *newNode = new Node(d);
    // if list is Empty
    if(tail == NULL) {
        tail = newNode;
        newNode -> next = newNode;
    }
    else {
        // non empty list
        // assuming that element is present in the list
        Node *curr = tail;
        while(curr -> data != element)
        {
            curr = curr -> next;
        }
        newNode -> next = curr -> next;
        curr -> next = newNode;
    }
}

void deleteNode(Node* &tail, int element)
{
    // Empty List
    if(tail == NULL) {
        cout << "Empty List" << endl << endl;
        return;
    }
    else {
        // Non-Empty List
        // assuming that element is present in the list
        Node *prev = tail, *curr = prev -> next;
        while(curr -> data != element) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        // 1 Node List
        if(curr == prev) {
            tail = NULL;
        }
        else if(curr == tail){
            tail = prev;
        }

        // free memory
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* tail)
{
    Node *temp = tail;
    if(tail == NULL) {
        cout << "Empty List" << endl << endl;
        return;
    }
    else {
        do {
            cout << tail -> data << " ";
            tail = tail -> next;
        } while(tail != temp);
        cout << endl << "tail: " << tail -> data << endl << endl;
    }
}

int main()
{
    // Node *newNode = new Node(5);
    // newNode -> next = newNode;
    Node *tail = NULL;
    print(tail);

    insertNode(tail, 5, 10);
    print(tail);
    insertNode(tail, 10, 20);
    print(tail);
    insertNode(tail, 10, 3);
    print(tail);
    insertNode(tail, 20, 5);
    print(tail);

    deleteNode(tail, 20);
    print(tail);
    deleteNode(tail, 10);
    print(tail);
    deleteNode(tail, 3);
    print(tail);
    deleteNode(tail, 5);
    print(tail);
    return 0;
}