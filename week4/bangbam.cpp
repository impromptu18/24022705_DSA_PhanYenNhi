
#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
    int key;
    Node* next;

    Node(int k) {
        key = k;
        next = nullptr;
    }
};

struct HashTable {
    Node* table[SIZE];

    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = nullptr;
        }
    }

    // Ham bam
    int hashFunction(int key) {
        return ((key % SIZE) + SIZE) % SIZE;
    }

    // Them key vao bang bam
    void insert(int key) {
        int index = hashFunction(key);

        // Khong them key trung lap
        if (search(key)) {
            cout << "Key da ton tai!\n";
            return;
        }

        Node* p = new Node(key);
        p->next = table[index];
        table[index] = p;
    }

    // Tim kiem key
    bool search(int key) {
        int index = hashFunction(key);
        Node* p = table[index];

        while (p != nullptr) {
            if (p->key == key) {
                return true;
            }
            p = p->next;
        }

        return false;
    }

    // Xoa key khoi bang bam
    void remove(int key) {
        int index = hashFunction(key);
        Node* p = table[index];
        Node* prev = nullptr;

        while (p != nullptr) {
            if (p->key == key) {
                if (prev == nullptr) {
                    table[index] = p->next;
                } else {
                    prev->next = p->next;
                }

                delete p;
                cout << "Da xoa " << key << '\n';
                return;
            }

            prev = p;
            p = p->next;
        }

        cout << "Khong tim thay key!\n";
    }

    // In bang bam
    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";

            Node* p = table[i];
            while (p != nullptr) {
                cout << p->key << " -> ";
                p = p->next;
            }

            cout << "NULL\n";
        }
    }

    // Giai phong bo nho
    ~HashTable() {
        for (int i = 0; i < SIZE; i++) {
            Node* p = table[i];

            while (p != nullptr) {
                Node* temp = p;
                p = p->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable h;

    h.insert(10);
    h.insert(15);
    h.insert(17);
    h.insert(24);
    h.insert(31);

    h.display();

    cout << "\nTim 17: " << h.search(17) << '\n';
    cout << "Tim 20: " << h.search(20) << '\n';

    h.remove(17);

    cout << "\nBang bam sau khi xoa:\n";
    h.display();

    return 0;
}
