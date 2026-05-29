#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:

    vector<int> arr;

    int front;
    int rear;
    int size;
    int capacity;

    MyCircularDeque(int k) {

        arr.resize(k);

        capacity = k;

        front = 0;
        rear = -1;

        size = 0;
    }
    
    bool insertFront(int value) {

        if(isFull()) {
            return false;
        }

        front = (front - 1 + capacity) % capacity;

        arr[front] = value;

        if(size == 0) {
            rear = front;
        }

        size++;

        return true;
    }
    
    bool insertLast(int value) {

        if(isFull()) {
            return false;
        }

        rear = (rear + 1) % capacity;

        arr[rear] = value;

        if(size == 0) {
            front = rear;
        }

        size++;

        return true;
    }
    
    bool deleteFront() {

        if(isEmpty()) {
            return false;
        }

        front = (front + 1) % capacity;

        size--;

        return true;
    }
    
    bool deleteLast() {

        if(isEmpty()) {
            return false;
        }

        rear = (rear - 1 + capacity) % capacity;

        size--;

        return true;
    }
    
    int getFront() {

        if(isEmpty()) {
            return -1;
        }

        return arr[front];
    }
    
    int getRear() {

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

    MyCircularDeque dq(5);

    cout << dq.insertLast(10) << endl;
    cout << dq.insertLast(20) << endl;

    cout << dq.insertFront(5) << endl;
    cout << dq.insertFront(2) << endl;

    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;

    dq.deleteFront();

    cout << "After deleteFront()" << endl;

    cout << "Front: " << dq.getFront() << endl;

    dq.deleteLast();

    cout << "After deleteLast()" << endl;

    cout << "Rear: " << dq.getRear() << endl;

    return 0;
}