#include <iostream>
#include <string>
using namespace std;

class Automobile
{
public:
    string type;
    string company;
    int year;

    Automobile(string t, string c, int y) : type(t), company(c), year(y) {}
};

class Node
{
public:
    Automobile data;
    Node *left;
    Node *right;

    Node(Automobile autoData) : data(autoData), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
public:
    Node *root;

    BinarySearchTree() : root(nullptr) {}

    Node *insert(Node *node, Automobile autoData)
    {
        if (node == nullptr)
            return new Node(autoData);
        if (autoData.year < node->data.year)
            node->left = insert(node->left, autoData);
        else if (autoData.year > node->data.year)
            node->right = insert(node->right, autoData);
        return node;
    }

    Node *findMin(Node *node)
    {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node *deleteNode(Node *node, int year)
    {
        if (!node)
            return node;
        if (year < node->data.year)
            node->left = deleteNode(node->left, year);
        else if (year > node->data.year)
            node->right = deleteNode(node->right, year);
        else
        {
            if (!node->left)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data.year);
        }
        return node;
    }

    void inorder(Node *node)
    {
        if (node)
        {
            inorder(node->left);
            cout << node->data.type << " | " << node->data.company << " | " << node->data.year << endl;
            inorder(node->right);
        }
    }

    void preorder(Node *node)
    {
        if (node)
        {
            cout << node->data.type << " | " << node->data.company << " | " << node->data.year << endl;
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node *node)
    {
        if (node)
        {
            postorder(node->left);
            postorder(node->right);
            cout << node->data.type << " | " << node->data.company << " | " << node->data.year << endl;
        }
    }
};

int main()
{
    BinarySearchTree bst;

    bst.root = bst.insert(bst.root, Automobile("SUV", "Toyota", 2015));
    bst.root = bst.insert(bst.root, Automobile("Sedan", "Honda", 2018));
    bst.root = bst.insert(bst.root, Automobile("Truck", "Ford", 2012));
    bst.root = bst.insert(bst.root, Automobile("Hatchback", "Hyundai", 2020));

    cout << "Inorder Traversal:" << endl;
    bst.inorder(bst.root);

    cout << "Preorder Traversal:" << endl;
    bst.preorder(bst.root);

    cout << "Postorder Traversal:" << endl;
    bst.postorder(bst.root);

    bst.root = bst.deleteNode(bst.root, 2018);
    cout << "Inorder Traversal after Deletion:" << endl;
    bst.inorder(bst.root);

    return 0;
}