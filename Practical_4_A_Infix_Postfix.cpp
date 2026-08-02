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
        if(top >= 99)
        {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = a;
    }

    int pop()
    {
        if(top == -1)
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

        cout << (char)arr[top] << endl;
    }

    int topElement()
    {
        if(top == -1)
            return -1;
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

int precedence(char op)
{
    if(op == '^')
        return 3;
    if(op == '*' || op == '/')
        return 2;
    if(op == '+' || op == '-')
        return 1;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int j = 0;

    Stack s;

    cout << "Enter infix expression: ";
    cin >> infix;

    for(int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            postfix[j++] = ch;
        }
        else if(ch == '(')
        {
            s.push(ch);
        }
        else if(ch == ')')
        {
            while(!s.empty() && s.topElement() != '(')
                postfix[j++] = (char)s.pop();

            s.pop(); // Remove '('
        }
        else
        {
            while(!s.empty() && precedence((char)s.topElement()) >= precedence(ch))
                postfix[j++] = (char)s.pop();

            s.push(ch);
        }
    }

    while(!s.empty())
        postfix[j++] = (char)s.pop();

    postfix[j] = '\0';

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
