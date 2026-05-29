#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:

    vector<int> arr;

    int front;
    int rear;
    int size;
    int capacity;

    MyCircularQueue(int k) {

        arr.resize(k);

        front = 0;
        rear = -1;
        size = 0;
        capacity = k;
    }

    bool enQueue(int value) {

        if(isFull()) {
            return false;
        }

        rear = (rear + 1) % capacity;

        arr[rear] = value;

        size++;

        return true;
    }

    bool deQueue() {

        if(isEmpty()) {
            return false;
        }

        front = (front + 1) % capacity;

        size--;

        return true;
    }

    int Front() {

        if(isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    int Rear() {

        if(isEmpty()) {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty() {

        return size == 0;
    }

    bool isFull() {

        return size == capacity;
    }
};

int main() {

    MyCircularQueue q(5);

    cout << q.enQueue(10) << endl;
    cout << q.enQueue(20) << endl;
    cout << q.enQueue(30) << endl;

    cout << "Front Element: " << q.Front() << endl;
    cout << "Rear Element: " << q.Rear() << endl;

    q.deQueue();

    cout << "After Dequeue" << endl;

    cout << "Front Element: " << q.Front() << endl;
    cout << "Rear Element: " << q.Rear() << endl;

    cout << q.enQueue(40) << endl;
    cout << q.enQueue(50) << endl;
    cout << q.enQueue(60) << endl;

    cout << "Is Full: " << q.isFull() << endl;

    return 0;
}