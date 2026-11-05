#include<iostream>
using namespace std;
// Do phuc tap thoi gian cua merge sort la O(n log n) trong moi truong hop.
// Do phuc tap khong gian la O(n)
void merge(int *a, int l, int m, int r){
    int * b, *c;
    b = new int[m-l+1];
    c = new int[r-m];
    for(int i = l; i<=r; i++){
        if(i<=m){
            b[i-l] = a[i];
        }else{
            c[i-m-1] = a[i];
        }
    }
    int i=0, j=0, k=l;
    while(i<m-l+1 && j<r-m){
        if(b[i]<c[j]){
            a[k] = b[i++];
        }else{
            a[k] = c[j++];
        }
        k++;
    }
    while(i<m-l+1){
        a[k++] = b[i++];
    }
    while(j<r-m){
        a[k++] = c[j++];
    }
    delete[] b;
    delete[] c;
} 
void sort(int *a, int l, int r){
    if(r<=l){
        return ;
    }
    int m = (l+r)/2;
    sort(a,l,m);
    sort(a, m+1, r);
    merge(a,l,m,r);
}
int main(){
    int a[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);

    sort(a, 0, n-1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}