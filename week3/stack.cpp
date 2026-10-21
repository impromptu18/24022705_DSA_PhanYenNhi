
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* head;

    Stack() {
        head = nullptr;
    }

    // Kiem tra Stack rong
    bool isEmpty() {
        return head == nullptr;
    }

    // Them phan tu vao dau
    void push(int item) {
        Node* p = new Node;
        p->data = item;
        p->next = head;
        head = p;
    }

    // Xoa va tra ve phan tu o tren cung
    int pop() {
        if (isEmpty()) {
            return -1;
        }

        Node* p = head;
        int value = p->data;
        head = head->next;
        delete p;

        return value;
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

    // Lay gia tri o tren cung Stack, khong xoa
    int top() {
        if (isEmpty()) {
            cout << "Stack rong\n";
            return -1;
        }

        return head->data;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.size() << '\n';
    cout << s.top() << '\n';
    cout << s.pop() << '\n';
    cout << s.top() << '\n';
    cout << s.isEmpty() << '\n';

    return 0;
}
