#include <iostream>
using namespace std;

void swim(int *a, int k){
    // doi thanh min heap thi doi dau < thanh >
    while(k > 1 && a[k/2] < a[k]){
        swap(a[k], a[k/2]);
        k = k/2;
    }
}
void insert(int *a, int &n, int x){
    n++;
    a[n] = x;
    swim(a, n);
}

// min heap
// if(j < n && a[j] > a[j+1]) j++;
// if(a[k] <= a[j]) break;
void sink(int *a, int n, int k){
    while(2*k <= n){
        int j = 2*k;
        if(j < n && a[j] < a[j+1]) j++;
        if(a[k] >= a[j]) break;
        swap(a[k], a[j]);
        k = j;
    }
}
int delMax(int *a, int &n){
    int max = a[1];
    swap(a[1], a[n]);
    n--;
    sink(a, n, 1);
    return max;
}
int main(){
    int a[100], n = 0;
    insert(a, n, 5);
    insert(a, n, 10);
    insert(a, n, 3);
    insert(a, n, 8);
    cout << delMax(a, n) << endl; 
    cout << delMax(a, n) << endl; 
    return 0;
}