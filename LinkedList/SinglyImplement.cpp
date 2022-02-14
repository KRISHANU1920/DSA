#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this -> data = data;
            this -> next = NULL;
        }
        // destructor
        ~Node()
        {
            // memory free
            if(this -> next != NULL) {
                delete next;
                this -> next = NULL;
            }
            cout << "Memory freed for Node with value " << this -> data << endl;
        }
};

void insertAtHead(int d, Node* &head)
{
    // create new node
    Node *temp = new Node(d);
    temp -> next = head; 
    head = temp;
}

void insertAtTail(int d, Node* &tail)
{
    // create new node
    Node *temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void insertAtPostion(int d, int pos, Node* &head, Node* &tail)
{
    Node *temp = head;
    
    // insert at start position
    if(pos == 1) {
        insertAtHead(d, head);
        return ;
    }

    // move pointer to previous node of inserting position
    int count = 1;
    while(count < pos-1)
    {
        temp = temp -> next;
        count++;
    }

    // insert at end position
    if(temp -> next == NULL) {
        insertAtTail(d, tail);
        return ;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteByPosition(Node* &head, int pos)
{
    // delete first node 
    if(pos == 1)
    {
        Node *temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    // delete any middle or end node 
    else {
        int count = 1;
        Node *prev = NULL, *curr = head;
        while(curr != NULL && count < pos) {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        if(curr == NULL)
            cout << "Positon doesn't exist\n";
        else {
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
        }
    }
}

void deleteByValue(Node* &head, int d)
{
    Node *prev = NULL, *curr = head;
    int count = 1;
    while(curr != NULL) {
        if(d == curr -> data) 
            break;
        prev = curr;
        curr = curr -> next;
        count++;
    }
    // if value not present
    if(curr == NULL)
        cout << "Value Doesn't Exist\n";
    // if value present at start node
    else if(count == 1)
        head = head -> next;
    // if value present at any middle or end node
    else 
        prev -> next = curr -> next;
    // free memory
    curr -> next = NULL;
    delete curr;
}

void print(Node* &head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

int main()
{
    // create first node
    Node *newNode = new Node(10);

    Node *head = newNode;
    Node *tail = newNode;

    // insertion
    insertAtHead(5, head);
    insertAtTail(20, tail);
    insertAtPostion(15, 3, head, tail);
    print(head);

    // print head & tail data
    cout << head -> data << endl;
    cout << tail -> data << endl;

    // deletion
    deleteByPosition(head, 2);
    deleteByValue(head, 15);
    print(head);

    return 0;
}