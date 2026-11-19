#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename Key, typename Value>
class ST {
private:
    struct Node {
        Key key;
        Value value;
        Node* next;
    };

    Node* head;
    int n;

public:
    // Khoi tao Symbol Table rong
    ST() {
        head = NULL;
        n = 0;
    }

    // Them hoac cap nhat Key-Value
    void put(Key key, Value val) {
        Node* p = head;

        // Kiem tra Key da ton tai chua
        while (p != NULL) {
            if (p->key == key) {
                p->value = val;
                return;
            }

            p = p->next;
        }

        // Tao Node moi
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = val;

        // Them vao dau Linked List
        newNode->next = head;
        head = newNode;

        n++;
    }

    // Tim Value theo Key
    Value get(Key key) {
        Node* p = head;

        while (p != NULL) {
            if (p->key == key) {
                return p->value;
            }

            p = p->next;
        }

        return Value();
    }

    // Kiem tra Key co ton tai
    bool contains(Key key) {
        Node* p = head;

        while (p != NULL) {
            if (p->key == key) {
                return true;
            }

            p = p->next;
        }

        return false;
    }

    // Xoa Key va Value
    void remove(Key key) {
        Node* p = head;
        Node* prev = NULL;

        while (p != NULL) {
            if (p->key == key) {

                // Xoa Node dau tien
                if (prev == NULL) {
                    head = p->next;
                }
                // Xoa Node o giua hoac cuoi
                else {
                    prev->next = p->next;
                }

                delete p;
                n--;
                return;
            }

            prev = p;
            p = p->next;
        }
    }

    // Kiem tra bang rong
    bool isEmpty() {
        return n == 0;
    }

    // Tra ve so cap Key-Value
    int size() {
        return n;
    }

    // Tra ve tat ca Key
    vector<Key> getKeys() {
        vector<Key> result;

        Node* p = head;

        while (p != NULL) {
            result.push_back(p->key);
            p = p->next;
        }

        return result;
    }

    // Hien thi Symbol Table
    void display() {
        Node* p = head;

        while (p != NULL) {
            cout << p->key << " : " << p->value << endl;
            p = p->next;
        }
    }

    // Giai phong bo nho
    ~ST() {
        Node* p = head;

        while (p != NULL) {
            Node* temp = p;
            p = p->next;
            delete temp;
        }
    }
};

int main() {
    ST<string, int> st;

    st.put("A", 10);
    st.put("B", 20);
    st.put("C", 30);

    cout << "Symbol Table:\n";
    st.display();

    cout << "\nGia tri cua B: " << st.get("B");

    cout << "\nB co ton tai? " << st.contains("B");

    st.put("A", 100);

    cout << "\n\nSau khi cap nhat A:\n";
    st.display();

    st.remove("B");

    cout << "\nSau khi xoa B:\n";
    st.display();

    cout << "\nSize: " << st.size();

    return 0;
}