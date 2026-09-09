#include <iostream>
using namespace std;

#define SIZE 5

int stack[SIZE];
int top = -1;


void push(int value)
{
    if (top == SIZE - 1)
        cout << "Stack Overflow\n";
    else
    {
        top++;
        stack[top] = value;
        cout << value << " pushed into stack\n";
    }
}

void pop()
{
    if (top == -1)
        cout << "Stack Underflow\n";
    else
    {
        cout << stack[top] << " popped from stack\n";
        top--;
    }
}


void display()
{
    if (top == -1)
        cout << "Stack is empty\n";
    else
    {
        cout << "Stack elements are:\n";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

    return 0;
}
