#include <iostream>

using namespace std;

class Queue {
    public:
        int *arr;
        int capacity;
        int front;
        int rear;
        int count;

    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    
    void enQueue(int item) {
        if (isFull()){
            cout << "Overflow: Queue is full";
            // exit(EXIT_FAILURE);
        }
        // rear = (rear + 1);
        arr[++rear] = item;
        count++;
    }
    
    int deQueue() {
        if (isEmpty()){
            cout << "Underflow: Queue is empty";
            // exit(EXIT_FAILURE);
        }
        int x = arr[front];
        front = (front+1)%capacity;
        count--;
        return x;
    }

    int getFront() {
        if (isEmpty()){
            cout << "Underflow: Queue is empty";
            // exit(EXIT_FAILURE);
        }
        return arr[front];
    }

    int getBack() {
        if (isEmpty()){
            cout << "Underflow: Queue is empty";
            // exit(EXIT_FAILURE);
        }
        return arr[rear];
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return (size() == 0);
    }
    
    bool isFull() {
        return (size() == capacity);
    }
};

int main() {
    Queue q(5);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.deQueue();
    cout << "The front element is " << q.getFront() << endl;
}