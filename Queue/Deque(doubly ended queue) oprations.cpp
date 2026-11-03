#include <iostream>
using namespace std;

class Deque {
public:
    int arr[5];
    int front, rear;

    Deque() {
        front = -1;
        rear = -1;
    }

    // Insert at Front
    void insertFront(int value) {
        if (front == 0) {
            cout << "Front is Full" << endl;
        }
        else {
            if (front == -1) {
                front = rear = 0;
            }
            else {
                front--;
            }

            arr[front] = value;
        }
    }

    // Insert at Rear
    void insertRear(int value) {
        if (rear == 4) {
            cout << "Rear is Full" << endl;
        }
        else {
            if (front == -1) {
                front = rear = 0;
            }
            else {
                rear++;
            }

            arr[rear] = value;
        }
    }

    // Delete from Front
    void deleteFront() {
        if (front == -1) {
            cout << "Deque is Empty" << endl;
        }
        else {
            cout << "Deleted: " << arr[front] << endl;

            if (front == rear) {
                front = rear = -1;
            }
            else {
                front++;
            }
        }
    }

    // Delete from Rear
    void deleteRear() {
        if (front == -1) {
            cout << "Deque is Empty" << endl;
        }
        else {
            cout << "Deleted: " << arr[rear] << endl;

            if (front == rear) {
                front = rear = -1;
            }
            else {
                rear--;
            }
        }
    }

    // Display
    void display() {
        if (front == -1) {
            cout << "Deque is Empty";
        }
        else {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    Deque d;

    d.insertRear(10);
    d.insertRear(20);
    d.insertRear(30);

    cout << "Deque: ";
    d.display();

    d.insertFront(5);

    cout << "After Insert Front: ";
    d.display();

    d.deleteRear();

    cout << "After Delete Rear: ";
    d.display();

    d.deleteFront();

    cout << "After Delete Front: ";
    d.display();

    return 0;
}
