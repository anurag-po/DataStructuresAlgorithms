#include <iostream>
using namespace std;
class CircularQueue {
private:
    int arr[10];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((rear + 1) % 10 == front);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % 10;
        arr[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int data = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % 10;
        }
        return data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " <-- ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % 10;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(11);
    q.enqueue(13);

    q.display();

    return 0;
}
