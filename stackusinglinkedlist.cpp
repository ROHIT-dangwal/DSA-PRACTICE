#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *top;
    LinkedList()
    {
        head = NULL;
        top = NULL;
    }
    void Push(int value)
    {
        Node *newnode = new Node(value);
        if (head == NULL)
        {
            head = newnode;
            top = newnode;
            return;
        }
        top->next = newnode;
        top = newnode;
        return;
    }
    void Pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        if (head == top)
        {
            delete top;
            head = top = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next != top)
        {
            temp = temp->next;
        }
        delete top;
        top = temp;
        top->next = NULL;
    }
    void peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << top->value << endl;
        }
    }
    void traverse()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList l;
    l.Push(10);
    l.traverse();
    cout << "______________________" << endl;
    l.Push(20);
    l.Push(30);
    l.traverse();
    cout << "______________________" << endl;
    l.Pop();
    l.traverse();
    cout << "______________________" << endl;
    l.Pop();
    l.Pop();
    cout << "______________________" << endl;
    l.Pop();
}