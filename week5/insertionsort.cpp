#include<iostream>
using namespace std;
// Do phuc tap thoi gian cua insertion sort la O(n^2) trong truong hop xau nhat va trung binh
// va O(n) trong truong hop tot nhat (khi mang da duoc sap xep)
// Do phuc tap khong gian o(1)
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main() {
    int a[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);

    insertionSort(a, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}