// viet chuong trinh nhap vao 1 phan so a/b, rut gon phan so do

// Do phuc tap thoi gian: O(log(min(a,b)))
// Do phuc tap bo nho: O(1)
#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b){
        int tmp;
        if(a>b){
            tmp = a%b;
        } else {tmp = b%a;
        }
        if(tmp == 0) return min(a,b);
        gcd(tmp , min(a,b)); 
}
void rutGonPhanSo(int& a, int& b) {
    if (b == 0) {
        cout << "Mau so khong the bang 0!" << endl;
        return;
    }
    int ucln = gcd(a, b);
    a /= ucln;
    b /= ucln;
    
    if (b < 0) {
        a = -a;
        b = -b;
    }
}

int main() {
    int a, b;
    cout << "Nhap tu so a va mau so b: ";
    cin >> a >> b;
    
    rutGonPhanSo(a, b);
    if (b != 0) {
        cout << "Phan so toi gian la: " << a << "/" << b << endl;
    }
    return 0;
}