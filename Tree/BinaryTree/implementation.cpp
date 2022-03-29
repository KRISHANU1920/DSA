#include <iostream>
#include <queue>
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

Node* buildTree(Node *root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;
    root = new Node(data);

    if(data == -1)
        return NULL;
    
    cout << endl << "Enter data for left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << endl << "Enter data for right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void buildLevelOrder(Node* &root)
{
    queue<Node*> q;
    
    int data;
    cout << "Enter data for root node: ";
    cin >> data;
    root = new Node(data);
    q.push(root);


    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftNode;
        cout << "Enter data for left of " << temp -> data << ": ";
        cin >> leftNode;

        if(leftNode != -1) {
            temp -> left = new Node(leftNode);
            q.push(temp -> left);
        }

        int rightNode;
        cout << "Enter data for right of " << temp -> data << ": ";
        cin >> rightNode;

        if(rightNode != -1) {
            temp -> right = new Node(rightNode);
            q.push(temp -> right);
        }
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

    // buildLevelOrder(root);
    // levelOrder(root);

    // creating Tree
    // 1 2 4 -1 -1 5 -1 7 -1 -1 3 6 -1 -1 -1
    root = buildTree(root);

    // Level Order Traversal
    cout << endl << "Level Order Traversal for the inserted Tree: " << endl;
    levelOrder(root);

    // InOrder Traversal
    cout << endl << "In Order Traversal for the inserted Tree: " << endl;
    inOrder(root);

    // preOrder Traversal
    cout << endl << "In Order Traversal for the inserted Tree: " << endl;
    preOrder(root);

    // PostOrder Traversal
    cout << endl << "In Order Traversal for the inserted Tree: " << endl;
    postOrder(root);

    return 0;
}