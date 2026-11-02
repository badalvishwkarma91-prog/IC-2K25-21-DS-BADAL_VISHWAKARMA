#include <iostream>
using namespace std;

class Queue {
public:
    int arr[5];
    int front, rear;

    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue
    void enqueue(int value) {
        if (rear == 4) {
            cout << "Queue is Full" << endl;
        }
        else {
            if (front == -1) {
                front = 0;
            }

            rear++;
            arr[rear] = value;
        }
    }

    // Dequeue
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty" << endl;
        }
        else {
            cout << "Deleted: " << arr[front] << endl;

            front++;

            if (front > rear) {
                front = rear = -1;
            }
        }
    }

    // Display
    void display() {
        if (front == -1) {
            cout << "Queue is Empty";
        }
        else {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();

    cout << "Queue: ";
    q.display();

    return 0;
}
