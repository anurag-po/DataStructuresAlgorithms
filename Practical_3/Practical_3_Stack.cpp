// Write a program to implement stack using array. Demonstrate the following operations on stack: push( ), pop( ), peek( ) and display( )

#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int a)
    {
        if (top >= 99)
        {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = a;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return -1;
        }

        int k = arr[top];
        top--;
        return k;
    }

    void peek()
    {
        if(top == -1)
        {
            cout << "Stack Empty\n";
            return;
        }

        cout << arr[top] << endl;
    }

    void display()
    {
        for(int i = top; i >= 0; i--)
            cout << arr[i] << " -> ";

        cout << endl;
    }
};


int main()
{
    Stack newstack;

    newstack.push(10);
    newstack.push(20);
    newstack.push(30);

    newstack.peek();

    newstack.display();

    newstack.pop();

    newstack.display();

    cout << newstack.pop() << endl;

    return 0;
}
