#include <bits/stdc++.h>
using namespace std;

template<typename T> class StackNode
{
    T data;
    StackNode* next;

public:
    StackNode* newNode(T data)
    {
        StackNode* stackNode = new StackNode();
        stackNode->data = data;
        stackNode->next = NULL;
        return stackNode;
    }

    T isEmpty(StackNode* root)
    {
        return !root;
    }

    void push(StackNode** root, T data)
    {
        StackNode* stackNode = newNode(data);
        stackNode->next = *root;
        *root = stackNode;
        cout << data << " pushed into stack" << endl;
    }

    T pop(StackNode** root)
    {
        if (isEmpty(*root)) return INT_MIN;
        StackNode* temp = *root;
        *root = (*root)->next;
        T popped = temp->data;
        free(temp);
        return popped;
    }

    T peek(StackNode* root)
    {
        if (isEmpty(root)) return INT_MIN;
        return root->data;
    }
};

int main()
{
    StackNode<int> s;
    StackNode<int>* root = NULL;

    s.push(&root, 10);
    s.push(&root, 20);
    s.push(&root, 30);

    cout << s.pop(&root) << " popped from stack\n";

    cout << "Top element is " << s.peek(root) << endl;

    cout <<"Elements present in stack : ";
     //print all elements in stack :
    while(!s.isEmpty(root))
    {
        // print top element in stack
        cout << s.peek(root) <<" ";
        // remove top element in stack
        s.pop(&root);
    }
    cout << endl;

    StackNode<char> chs;
    StackNode<char>* croot = NULL;

    chs.push(&croot, 'a');
    chs.push(&croot, 'b');
    chs.push(&croot, 'c');

    cout << chs.pop(&croot) << " popped from stack\n";

    cout << "Top element is " << chs.peek(croot) << endl;

    cout <<"Elements present in stack : ";
     //print all elements in stack :
    while(!chs.isEmpty(croot))
    {
        // print top element in stack
        cout << chs.peek(croot) <<" ";
        // remove top element in stack
        chs.pop(&croot);
    }
    return 0;
}
