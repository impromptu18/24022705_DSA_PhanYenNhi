// Xoa phan tu vao vi tri k bat ky trong mang

// Do phuc tap thoi gian: O(n)
// Do phuc tap bo nho: O(1)
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    if (k < 0 || k >= n) {
        cout << "Vi tri k khong hop le!" << endl;
        return 0;
    }
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}