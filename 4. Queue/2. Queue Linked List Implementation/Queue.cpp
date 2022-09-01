#include <bits/stdc++.h>
using namespace std;

template<typename T> struct QNode
{
    T data;
    QNode* next;

    QNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template<typename T> struct Queue
{
    QNode<T> *front, *rear;

    Queue()
    {
        front = rear = NULL;
    }

    void enQueue(T data)
    {
        QNode<T>* temp = new QNode<T>(data);
        if (rear == NULL)
        {
            rear = front = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void deQueue()
    {
        if (front == NULL)
        {
            return;
        }

        QNode<T>* temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete(temp);
    }
};

int main()
{
    Queue<int> q;
    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.deQueue();
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.deQueue();
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data << endl;

    Queue<char> chq;
    chq.enQueue('a');
    chq.enQueue('b');
    chq.deQueue();
    chq.deQueue();
    chq.enQueue('c');
    chq.enQueue('d');
    chq.enQueue('e');
    chq.deQueue();
    cout << "Queue Front : " << (chq.front)->data << endl;
    cout << "Queue Rear : " << (chq.rear)->data;
    return 0;
}
