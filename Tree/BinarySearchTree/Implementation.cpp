#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int d)
        {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node* insertIntoBST(Node *root, int d)
{
    // base case
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }
    
    if(d <= root -> data)
        root -> left = insertIntoBST(root -> left, d);
    else
        root -> right = insertIntoBST(root -> right, d);
    
    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        // taking input from user and insertin in BST
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrder(Node *start)
{
    queue<Node*> q;
    q.push(start);
    q.push(NULL);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            // last level completely traversed
            cout << endl;

            if(!q.empty()) {
                // queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp -> data << " ";
            if(temp -> left)
                q.push(temp -> left);
            
            if(temp -> right)
                q.push(temp -> right);
        }
    }
}

void inOrder(Node *root)
{
    // base case
    if(root == NULL)
        return;
    
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

void preOrder(Node *root)
{
    // base case
    if(root == NULL)
        return;
    
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void postOrder(Node *root)
{
    // base case
    if(root == NULL)
        return;
    
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

int main()
{
    Node *root = NULL;

    // create new Node of BST
    takeInput(root);

    // Level Order Traversal
    cout << endl << "Level Order Traversal for the inserted Tree: " << endl;
    levelOrder(root);

    // InOrder Traversal
    cout << endl << "In Order Traversal for the inserted Tree: " << endl;
    inOrder(root);

    // preOrder Traversal
    cout << endl << "Pre Order Traversal for the inserted Tree: " << endl;
    preOrder(root);

    // PostOrder Traversal
    cout << endl << "Post Order Traversal for the inserted Tree: " << endl;
    postOrder(root);

    return 0;
}