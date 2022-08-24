#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

template<typename T> class Stack
{
    int top;

public:
    T* arr;

    Stack()
    {
        arr = new T[MAX];
        top = -1;
    }

    bool push(T x)
    {
        if (top >= (MAX-1))
        {
            cout << "Stack overflow" << endl;
            return false;
        }
        arr[++top] = x;
        cout << x << " pushed into stack" << endl;
        return true;
    }

    T pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow" << endl;
            return 0;
        }
        T x = arr[top--];
        return x;
    }

    T peek()
    {
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        T x = arr[top];
        return x;
    }

    bool isEmpty()
    {
        return (top < 0);
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";

    //print top element of stack after poping
    cout << "Top element is : " << s.peek() << endl;

    //print all elements in stack :
    cout <<"Elements present in stack : ";
    while(!s.isEmpty())
    {
        // print top element in stack
        cout << s.peek() <<" ";
        // remove top element in stack
        s.pop();
    }
    cout << endl;

    Stack<char> chs;
    chs.push('a');
    chs.push('b');
    chs.push('c');
    cout << chs.pop() << " Popped from stack\n";

    //print top element of stack after poping
    cout << "Top element is : " << chs.peek() << endl;

    //print all elements in stack :
    cout <<"Elements present in stack : ";
    while(!chs.isEmpty())
    {
        // print top element in stack
        cout << chs.peek() <<" ";
        // remove top element in stack
        chs.pop();
    }
    return 0;
}
