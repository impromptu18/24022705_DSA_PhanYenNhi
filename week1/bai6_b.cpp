// Chen phan tu y vao vi tri m trong mang a co n phan tu

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
    int m, y;
    cin >> m >> y;
    if (m < 0 || m > n) {
        cout << "Vi tri m khong hop le!" << endl;
        return 0;
    }
    for (int i = n; i > m; i--) {
        a[i] = a[i - 1];
    }
    a[m] = y;
    n++;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}