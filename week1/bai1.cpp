// viet chuong trinh nhap vap 1 day N phan tu, tinh tong N phan tu do

// Do phuc tap thoi gian: O(n)

// Do phuc tap bo nho: O(1)
#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Nhap so luong phan tu N: ";
    cin >> n;
    int a[1000];
    int sum = 0;
    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    cout << "Tong cac phan tu trong day la: " << sum << endl;
    return 0;
}