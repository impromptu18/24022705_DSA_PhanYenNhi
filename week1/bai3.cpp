// viet chuong trinh nhap vao 1 so n , tinh n!

// Do phuc tap thoi gian: O(n)
// Do phuc tap bo nho: O(1)
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int t=1;
    if(n<0){
        cout<< "Khong tinh duoc giai thua cua so am";
        return 0;
    }else if(n==0){
        cout<< "Giai thua cua 0 la 1";
        return 0;
    } else{
    for(int i = 1; i <= n; i++) {
        t*=i;
    }
    cout<< t;
    return 0;
    }
}