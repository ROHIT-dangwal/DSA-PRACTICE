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

class queue1
{
public:
    Node *front, *rear;
    queue1()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int value)
    {
        Node *newnode = new Node(value);
        if (rear == NULL && front == NULL)
        {
            front = newnode;
            rear = newnode;
            return;
        }
        rear->next = newnode;
        rear = newnode;
        return;
    }
    void dequeue()
    {
        if (rear == NULL && front == NULL)
        {
            cout << "queue is empty" << endl;
            return;
        }
        if (front == rear)
        {
            delete front;
            front = rear = NULL;
            return;
        }
        Node *temp = front->next;
        delete front;
        front = temp;
    }
    void display()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    queue1 q;
    q.enqueue(10);
    q.display();
    cout << "______________________" << endl;
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "______________________" << endl;
    q.dequeue();
    q.display();
    cout << "______________________" << endl;
    q.dequeue();
    q.dequeue();
    cout << "______________________" << endl;
    q.dequeue();
}