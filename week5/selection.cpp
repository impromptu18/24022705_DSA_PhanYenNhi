#include<iostream>
using namespace std;

// Do phuc tap thoi gian cua selection sort la O(n^2) trong truong hop xau nhat, trung binh va tot nhat. 
// Do phuc tap bo nho la O(1)
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // danh dau vi tri min
        int minIndex = i;
        // tim vi tri min
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}
int main() {
    int a[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);

    selectionSort(a, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}