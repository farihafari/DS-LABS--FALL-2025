#include <iostream>
using namespace std;

const int size = 4;
int current_size = 0;
int front = 0;
int rear = -1;
int arr[size];

bool isFull() {
    return current_size == size;
}

bool isEmpty() {
    return current_size == 0;
}

void enQueue(int val) {
    if (isFull()) {
        cout << "Queue is full! Cannot insert " << val << endl;
        return;
    }

    rear = (rear + 1) % size;
    arr[rear] = val;
    current_size++;
    cout << "Enqueued: " << val << endl;
}

int deQueue() {
    if (isEmpty()) {
        cout << "Queue is empty! Nothing to dequeue." << endl;
        return -1;
    }

    int x = arr[front];
    front = (front + 1) % size;
    current_size--;
    cout << "Dequeued: " << x << endl;
    return x;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue elements: ";
    int i = rear; // start from rear now
    for (int count = 0; count < current_size; count++) {
        cout << arr[i] << " ";
        i = (i + 1) % size;
    }
    cout << endl;
}

int main() {
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    display();

    deQueue();
    display();

    enQueue(5);
    display();

deQueue();
    display();
    
    enQueue(6);
    display();

    return 0;
}

