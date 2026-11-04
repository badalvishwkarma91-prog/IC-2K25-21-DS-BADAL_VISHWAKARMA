#include <iostream>
using namespace std;

class CircularQueue {
public:
    int arr[5];
    int front, rear;
    int size;

    CircularQueue() {
        front = -1;
        rear = -1;
        size = 5;
    }

    // Enqueue Operation
    void enqueue(int value) {
        if ((rear + 1) % size == front) {
            cout << "Queue is Full" << endl;
        }
        else {
            if (front == -1) {
                front = 0;
            }

            rear = (rear + 1) % size;
            arr[rear] = value;

            cout << value << " Inserted" << endl;
        }
    }

    // Dequeue Operation
    void dequeue() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
        }
        else {
            cout << "Deleted: " << arr[front] << endl;

            if (front == rear) {
                front = rear = -1;
            }
            else {
                front = (front + 1) % size;
            }
        }
    }

    // Display Operation
    void display() {
        if (front == -1) {
            cout << "Queue is Empty";
        }
        else {
            int i = front;

            while (true) {
                cout << arr[i] << " ";

                if (i == rear) {
                    break;
                }

                i = (i + 1) % size;
            }
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.display();

    q.dequeue();

    cout << "After Dequeue: ";
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << "Final Queue: ";
    q.display();

    return 0;
}
