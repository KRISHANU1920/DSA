#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *prev;
        Node *next;

        // constructor
        Node(int d) {
            this -> data = d;
            this -> prev = NULL;
            this -> next = NULL;
        }

        //destructor
        ~Node() {
            if(this -> next != NULL) {
                delete next;
                this -> next = NULL;
            }
            cout << "Memory freed for node with value " << this -> data << endl;
        }
};

void insertAtHead(Node* &head, Node* &tail, int d)
{
    Node *temp = new Node(d);
    if(head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        temp -> next = head;
        temp -> next -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int d)
{
    Node *temp = new Node(d);
    if(tail == NULL) {
        tail = temp;
        head = temp;
    }
    else {
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int d)
{
    // insert at start position
    if(pos == 1) {
        insertAtHead(head, tail, d);
        return ;
    }

    int count = 1;
    Node *temp = head;
    while(temp != NULL && count < pos-1) {
        temp = temp -> next;
        count++;
    }
    if(temp == NULL) {
        cout << "Invalid Position\n";
        return;
    }
    // insert at end position
    else if(temp -> next == NULL) {
        insertAtTail(head, tail, d);
        return ;
    }
    else {
        Node *insertAtNode = new Node(d);
        insertAtNode -> next = temp -> next;
        temp -> next -> prev = insertAtNode;
        insertAtNode -> prev = temp;
        temp -> next = insertAtNode;
    }
}

void deleteByPosition(Node* &head, Node* &tail, int pos)
{
    // delete first node
    if(pos == 1) {
        Node *temp = head;
        head = head -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;
    }
    // delete any middle or end node
    else {
        Node *prev = NULL, *curr = head;
        int count = 1;
        while(curr != NULL && count < pos)
        {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        if(curr == NULL)
            cout << "Postion Doesn't Exist\n";

        // delete last node
        else if(curr -> next == NULL) {
            prev -> next = curr -> next;
            tail = prev;
        }
        else {
            prev -> next = curr -> next;
            curr -> next -> prev = prev;
        }
        // free memory
        curr -> next = NULL;
        curr -> prev = NULL;
        delete curr;
    }
}

void deleteByValue(Node* &head, Node* &tail, int value)
{
    Node *curr = head, *prev = NULL;
    int count = 1;
    while(curr != NULL) {
        if(value == curr -> data)
            break;
        prev = curr;
        curr = curr -> next;
        count++;
    }
    // if value doesn't exist
    if(curr == NULL) {
        cout << "Value Doesn't Exist\n";
        return;
    }
    // value present in first node
    else if(count == 1) {
        head = head -> next;
        head -> prev = NULL;
    }
    // value present in last node
    else if(curr -> next == NULL) {
        prev -> next = curr -> next;
        tail = prev;
    }
    // value present in any middle node
    else {
        prev -> next = curr -> next;
        curr -> next -> prev = prev;
    }
    // free memory
    curr -> next = NULL;
    curr -> prev = NULL;
    delete curr;
}

void print(Node* head, Node* tail)
{
    Node *temp = head;
    if(temp == NULL) {
        cout << "Empty List" << endl;
        return ;
    }
    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
    cout << "Head: " << head -> data << endl;
    cout << "Tail: " << tail -> data << endl << endl;
}

int main()
{
    Node *newNode = new Node(10);
    Node *head = newNode;
    Node *tail = newNode;

    // Node *head = NULL;
    // Node *tail = NULL;

    print(head, tail);
    insertAtHead(head, tail, 20);
    print(head, tail);
    insertAtTail(head, tail, 30);
    print(head, tail);
    insertAtPosition(head, tail, 2, 40);
    print(head, tail);
    insertAtPosition(head, tail, 5, 50);
    print(head, tail);

    deleteByPosition(head, tail, 5);
    print(head, tail);
    deleteByValue(head, tail, 40);
    print(head, tail);
    return 0;
}