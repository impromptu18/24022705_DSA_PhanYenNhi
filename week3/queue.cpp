#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* head;
    Node* tail;

    Queue() {
        head = tail = nullptr;
    }

    // Kiem tra rong
    bool isEmpty() {
        return head == nullptr;
    }

    // Them phan tu vao cuoi 
    void enqueue(int item) {
        Node* p = new Node;
        p->data = item;
        p->next = nullptr;

        if (isEmpty()) {
            head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    // Xoa va tra ve phan tu dau 
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong!\n";
            return -1;
        }

        Node* p = head;
        int value = p->data;

        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete p;
        return value;
    }

    // Lay phan tu dau, khong xoa
    int top() {
        if (isEmpty()) {
            cout << "Queue rong!\n";
            return -1;
        }

        return head->data;
    }

    // Dem so phan tu
    int size() {
        int count = 0;
        Node* p = head;

        while (p != nullptr) {
            count++;
            p = p->next;
        }

        return count;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Phan tu dau: " << q.top() << endl;
    cout << "So phan tu: " << q.size() << endl;

    cout << "Lay ra: " << q.dequeue() << endl;
    cout << "Phan tu dau sau khi xoa: " << q.top() << endl;

    return 0;
}