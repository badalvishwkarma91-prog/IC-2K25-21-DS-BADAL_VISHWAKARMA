#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front, rare, size, capacity;

public:
    Queue(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
        front = 0;
        rare = -1;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isempty() {
        return size == 0;
    }

    void enquee(int data) {
        if (isFull()) {
            cout << "queue is full";
            return;
        }
        else {
            rare++;
            arr[rare] = data;
            size++;
        }
    }

    void dequeue() {
        if (isempty()) {
            cout << "queue is empty";
            return;
        }
        else {
            cout << "Deleted element: " << arr[front] << endl;
            front++;
            size--;
        }
    }

    int peek() {
        if (isempty()) {
            cout << "queue is empty";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isempty()) {
            cout << "queue is empty";
            return;
        }

        for (int i = front; i <= rare; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);

    q.enquee(10);
    q.enquee(20);
    q.enquee(30);
    q.enquee(40);

    cout << "Queue elements: ";
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();

    cout << "Queue after dequeue: ";
    q.display();

    return 0;
}
