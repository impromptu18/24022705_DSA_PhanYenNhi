#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename Key, typename Value>
class ST {
private:
    static const int MAX = 100;
    Key keys[MAX];
    Value values[MAX];
    int n;

public:
    // Khoi tao Symbol Table rong
    ST() {
        n = 0;
    }

    // Them hoac cap nhat Key-Value
    void put(Key key, Value val) {
        for (int i = 0; i < n; i++) {
            if (keys[i] == key) {
                values[i] = val;
                return;
            }
        }

        if (n == MAX) {
            cout << "Symbol Table da day!\n";
            return;
        }

        keys[n] = key;
        values[n] = val;
        n++;
    }

    // Tim Value theo Key
    Value get(Key key) {
        for (int i = 0; i < n; i++) {
            if (keys[i] == key) {
                return values[i];
            }
        }

        return Value();
    }

    // Kiem tra Key co ton tai
    bool contains(Key key) {
        for (int i = 0; i < n; i++) {
            if (keys[i] == key) {
                return true;
            }
        }

        return false;
    }

    // Xoa Key va Value
    void remove(Key key) {
        for (int i = 0; i < n; i++) {
            if (keys[i] == key) {
                for (int j = i; j < n - 1; j++) {
                    keys[j] = keys[j + 1];
                    values[j] = values[j + 1];
                }

                n--;
                return;
            }
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

        for (int i = 0; i < n; i++) {
            result.push_back(keys[i]);
        }

        return result;
    }

    // Hien thi bang
    void display() {
        for (int i = 0; i < n; i++) {
            cout << keys[i] << " : " << values[i] << endl;
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