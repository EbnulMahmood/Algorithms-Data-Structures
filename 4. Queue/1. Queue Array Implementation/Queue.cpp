#include <bits/stdc++.h>
using namespace std;

template<typename T> class Queue
{
    int front, rear, size;
    unsigned capacity;
    T* arr;

public:
    Queue* createQueue(unsigned capacity)
    {
        Queue* queue = new Queue();
        queue->capacity = capacity;
        queue->front = queue->size = 0;
        queue->rear = capacity - 1;
        queue->arr = new T[queue->capacity];
        return queue;
    }

    int isFull(Queue* queue)
    {
        return (queue->size == queue->capacity);
    }

    int isEmpty(Queue* queue)
    {
        return (queue->size == 0);
    }

    void enqueue(Queue* queue, T item)
    {
        if (isFull(queue)) return;

        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->arr[queue->rear] = item;
        queue->size = queue->size + 1;
        cout << item << " enqueued to queue" << endl;
    }

    T dequeue(Queue* queue)
    {
        if (isEmpty(queue)) return INT_MIN;

        T item = queue->arr[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size = queue->size - 1;
        return item;
    }

    T Front(Queue* queue)
    {
        if (isEmpty(queue)) return INT_MIN;

        return queue->arr[queue->front];
    }

    T Rear(Queue* queue)
    {
        if (isEmpty(queue)) return INT_MIN;

        return queue->arr[queue->rear];
    }
};

int main()
{
    Queue<int> q;
    Queue<int>* queue = q.createQueue(1000);

    q.enqueue(queue, 10);
    q.enqueue(queue, 20);
    q.enqueue(queue, 30);
    q.enqueue(queue, 40);

    cout << q.dequeue(queue)
         << " dequeued from queue\n";

    cout << "Front item is "
         << q.Front(queue) << endl;
    cout << "Rear item is "
         << q.Rear(queue) << endl;

    cout << endl;

    Queue<char> chq;
    Queue<char>* chqueue = chq.createQueue(1000);

    chq.enqueue(chqueue, 'a');
    chq.enqueue(chqueue, 'b');
    chq.enqueue(chqueue, 'c');
    chq.enqueue(chqueue, 'd');

    cout << chq.dequeue(chqueue)
         << " dequeued from queue\n";

    cout << "Front item is "
         << chq.Front(chqueue) << endl;
    cout << "Rear item is "
         << chq.Rear(chqueue) << endl;
    return 0;
}
