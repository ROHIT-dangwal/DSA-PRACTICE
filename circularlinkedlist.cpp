#include <iostream>
using namespace std;
class Node
{
public:
    int rollno;
    string name;
    Node *next;
    Node *pre;
    Node(int rollno, string name)
    {
        this->rollno = rollno;
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
    void addNode(int rollno, string name)
    {
        Node *newNode = new Node(rollno, name);

        if (head == NULL)
        {
            head = newNode;
            head->next = head;
            head->pre = head;
            return;
        }
        else
        {
            Node *last = head->pre;
            last->next = newNode;
            newNode->next = head;
            newNode->pre = last;
            head->pre = newNode;

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
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *last = head->pre;
        last->pre->next = head;
        head->pre = last->pre;
        delete last;

        return;
    }
    void display()
    {
        Node *temp = head;
        do
        {
            cout << "employeeid -> " << temp->rollno << endl;
            cout << "Name -> " << temp->name << endl;

            temp = temp->next;
        } while (temp != head);
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