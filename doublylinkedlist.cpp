#include <iostream>
using namespace std;
class Node
{
public:
    int employeeid;
    string name;
    Node *next;
    Node *pre;
    Node(int employeeid, string name)
    {
        this->employeeid = employeeid;
        this->name = name;
        this->next = NULL;
        this->pre = NULL;
    }
};
class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }
    void addNode(int employeeid, string name)
    {
        Node *newNode = new Node(employeeid, name);

        if (head == NULL)
        {
            head = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
            return;
        }
    }
    void DeleteNode()
    {

        Node *temp = head;
        if (head == NULL)
        {
            return;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->pre->next = NULL;
        delete temp;
        return;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "employeeid -> " << temp->employeeid << endl;
            cout << "Name -> " << temp->name << endl;

            temp = temp->next;
        }
        return;
    }
};

int main()
{
    LinkedList s;
    s.addNode(21, "Rahul");
    s.addNode(34, "Rohan");
    s.display();
    cout << "_____________________________" << endl;
    s.addNode(55, "Rahul");
    s.display();
    cout << "_____________________________" << endl;
    s.DeleteNode();
    s.display();
    cout << "_____________________________" << endl;
    return 0;
}