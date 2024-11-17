#include <iostream>
using namespace std;
class twostack
{
private:
    int *stack1;

    int n, top1, top2;

public:
    twostack(int n)
    {
        this->n = n;
        this->top1 = -1;
        this->top2 = n;
        stack1 = new int[n];
    }

    void addNodestack1(int x)
    {
        if (top1 >= top2 - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            stack1[++top1] = x;
        }
    }
    void addNodestack2(int x)
    {
        if (top2 <= top1 + 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            stack1[--top2] = x;
        }
    }
    void popstack1()
    {
        if (top1 < 0)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            top1--;
        }
    }
    void popstack2()
    {
        if (top2 >= n)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            top2++;
        }
    }
    void display()
    {
        cout << "stack 1" << endl;
        for (int i = 0; i <= top1; i++)
        {
            cout << stack1[i] << endl;
        }
        cout << "stack2" << endl;
        for (int i = n - 1; i >= top2; i--)
        {
            cout << stack1[i] << endl;
        }
    }
};

int main()
{
    twostack s(4);
    s.addNodestack1(10);
    s.addNodestack1(20);
    s.addNodestack1(30);
    s.addNodestack2(40);
    s.addNodestack2(50);
    s.display();
    cout << "______________________________" << endl;
    s.popstack1();
    s.display();
    cout << "______________________________" << endl;
    s.popstack2();
    s.display();
    cout << "______________________________" << endl;
    s.addNodestack1(30);
    s.addNodestack1(30);
    s.display();
    cout << "______________________________" << endl;
    s.addNodestack1(43);
}