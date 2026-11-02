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

    void enqueue(int value) {

        if (rear == 4) {
            cout << "Queue is Full";
        }
        else {
            if (front == -1) {
                front = 0;
            }

            rear++;
            arr[rear] = value;

            cout << value << " Inserted" << endl;
        }
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.display();

    return 0;
}
