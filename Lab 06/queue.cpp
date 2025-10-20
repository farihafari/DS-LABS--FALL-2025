#include <iostream>
using namespace std;

const int Max_size = 5;  // fixed queue size
int front = -1;
int rear = -1;
int arr[Max_size];

bool isFull() {
    return rear == Max_size - 1;
}

bool isEmpty() {
    return (front == -1 || front > rear);
}

void enQueue(int value) {
    if (isFull()) {
        cout << "Queue is full, can't add: " << value << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    arr[++rear] = value;
    cout << "Enqueued: " << value << endl;
}

int deQueue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int val = arr[front++];
    cout << "Dequeued: " << val << endl;
    return val;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    enQueue(1);
    enQueue(2);
    enQueue(3);
    display();
	deQueue();
    deQueue();
    display();

    enQueue(4);
    enQueue(5);
    
    display();

    return 0;
}

