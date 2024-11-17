#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int value)
    {
        this->data = value;
        left = right = NULL;
    }
};
void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        printInorder(root->left);
        printInorder(root->right);
    }
}
void printpreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {

        printpreorder(root->left);
        cout << root->data << " ";
        printpreorder(root->right);
    }
}
void printpostorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {

        printpostorder(root->left);
        printpostorder(root->right);
        cout << root->data << " ";
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    printInorder(root);
    cout << "\n_____________________" << endl;
    printpreorder(root);
    cout << "\n_____________________" << endl;
    printpostorder(root);
    cout << endl;
    return 0;
}