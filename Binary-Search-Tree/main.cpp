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

// Recursively print all the nodes
void inorderTraversal(Node* root)
{
    if(root != nullptr)
    {
        inorderTraversal(root->left);
        std::cout << root->data  << " ";
        inorderTraversal(root->right);
    }
}

Node* searchNode(Node* root, int key)
{
    if(root == nullptr || root->data == key)
        return root;

    if(root->data < key)
        return searchNode(root->right, key);
    
    return searchNode(root->left, key);
}

//find the leaf furthest on the left
Node* minValueNode(Node* node)
{
    Node* current = node;
    while(current && current->left != nullptr)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int data)
{
    if(root == nullptr)
        return root;

    if(data < root->data)
        root->left = deleteNode(root->left, data);
    else if(data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        //if node has 1 or 0 children
        if(root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //if node has 2 children
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

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

    std::cout << "\nInorder traversal of the tree: ";
    inorderTraversal(root);
    
    root = deleteNode(root, 35);
    std::cout << "\nInorder traversal after deleting 35: ";
    inorderTraversal(root);  
    
    root = insertNode(root, 50);
    std::cout << "\nInorder traversal after inserting 50: ";
    inorderTraversal(root);   

    if(searchNode(root, 15))
        std::cout << "\nValue 15 found in the tree";
    else
        std::cout << "\nValue 15 not found in the tree";

    return 0;
}