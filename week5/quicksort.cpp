#include<iostream>
using namespace std;
// Do phuc tap thoi gian cua quick sort la O(n log n) trong truong hop trung binh va tot nhat
// va O(n^2) trong truong hop xau nhat (khi mang da duoc sap xep hoac gan nhu sap xep)
// Do phuc tap khong gian la O(1) 
int partition(int a[], int left, int right) {
    int pivot = a[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);
    return i + 1;
}
void quickSort(int a[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(a, left, right);
        quickSort(a, left, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, right);
    }
}
int main() {
    int a[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
