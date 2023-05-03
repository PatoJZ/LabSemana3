#include <iostream>
#include <string>

using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else
    {
        if (data < root->data)
        {
            root->left = insertNode(root->left, data);
        }
        else
        {
            root->right = insertNode(root->right, data);
        }
    }
    cout << root->data << endl;
    return root;
}
void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}
bool search(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }else{
        if (root->data == data)
        {
            cout << "ha sido encontrado " << root->data << endl;
        }
        else{ 
            if (root->data > data)
            {
                return search(root->left, data);
            }else
            {
               return search(root->right, data);
            }
        }
  }
    return false;
}
int findmin(Node* root)
{
    if (root -> left == NULL)
    {
        return root -> data;
    }
    return findmin(root->left);
}
int findMax(Node* root)
{
    if (root -> right == NULL)
    {
        return root -> data;
    }
    return findmin(root-> right);
}
Node* delete(Node* root, int deletevalue)
{
       if (root == NULL)
    {
        return false;
    }else{
        if (root->data == data)
        {
            cout << "ha sido encontrado " << root->data << endl;
        }
        else{ 
            if (root->data > data)
            {
               
            {
               
            }
        }
  }
    return false;
}
}
int main()
{
    int busqueda = 0;
    Node *root = NULL;
    root = insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 5);
    insertNode(root, 7);
    insertNode(root, 9);
    printTree(root);
    cout << "ponga numero a buscar" << endl;
    cin >> busqueda;
    if (search(root, busqueda))
    {
        cout << "ha sido encontrado" << endl;
    }else{
        cout << "No ha sido encontrado" << endl;
    }

    return 0;
}