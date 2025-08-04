#include <bits/stdc++.h>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;

    return newNode;
}

Node* insertNode(Node* root, int data)
{
    // Makes new node if tree is empty
    if(root == nullptr)
        return createNode(data);

    // Recursively go down the tree
    if(data < root->data)
        root->left = insertNode(root->left, data);
    else if(data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

int main()
{
    Node* root = nullptr;

    root = insertNode(root, 20);
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 25);
    root = insertNode(root, 35);
    root = insertNode(root, 30);
    root = insertNode(root, 40);

    return 0;
}