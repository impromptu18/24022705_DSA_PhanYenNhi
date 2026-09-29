// In ra các giá trị lớn hơn hoặc bằng giá trị trung bình của dãy

// Do phuc tap thoi gian: O(n)

// Do phuc tap bo nho: O(1)
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    double a[1000];
    double sum = 0;
    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    double average = (double)sum / n;
    cout << "Cac gia tri lon hon hoac bang trung binh la: ";
    for (int i = 0; i < n; i++) {
        if (a[i] >= average) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}