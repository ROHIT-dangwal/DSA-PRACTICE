#include <iostream>
using namespace std;
class Node
{
public:
	int rollno;
	string name;
	int marks;
	Node *next;
	Node(int rollno, string name, int marks)
	{
		this->rollno = rollno;
		this->marks = marks;
		this->name = name;
	}
};
class LinkedList
{
public:
	Node *head;
	Node *tail;

	LinkedList()
	{
		head = NULL;
	}
	void addNode(int position, int rollno, string name, int marks)
	{
		Node *newNode = new Node(rollno, name, marks);

		if (position == 1)
		{

			newNode->next = head;
			head = newNode;
			return;
		}

		Node *current = head;
		for (int i = 1; i < position - 1 && current != NULL; i++)
		{
			current = current->next;
		}
		if (current == NULL)
		{
			cout << "Position out of bounds.\n";
			return;
		}
		newNode->next = current->next;
		current->next = newNode;
		return;
	}
	void DeleteNode(int rollno)
	{
		if (head == NULL)
		{
			cout << "List is empty.\n";
			return;
		}
		if (head->rollno == rollno)
		{
			Node *temp = head;
			head = head->next;
			delete temp;
			return;
		}
		for (Node *current = head; current->next->rollno == rollno && current->next != NULL;)
		{
			if (current->next->rollno == rollno)
			{
				Node *temp = current->next;
				current->next = current->next->next;
				delete temp;
				return;
			}
			current = current->next;
		}
	}
	void display()
	{
		Node *temp = head;
		while (temp != NULL)
		{
			cout << "Rollno -> " << temp->rollno << endl;
			cout << "Name -> " << temp->name << endl;
			cout << "Marks -> " << temp->marks << endl;
			temp = temp->next;
		}
		return;
	}
};

int main()
{
	LinkedList s;
	s.addNode(1, 21, "Rahul", 90);
	s.addNode(2, 34, "Rohan", 85);
	s.display();
	cout << "_____________________________" << endl;
	s.addNode(2, 56, "Rahul", 95);
	s.display();
	cout << "_____________________________" << endl;
	s.DeleteNode(56);
	s.display();
	cout << "_____________________________" << endl;
	return 0;
}