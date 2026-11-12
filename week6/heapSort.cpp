
#include <iostream>
using namespace std;

// Dieu chinh Max Heap
void heapify(int *a, int n, int k) {
    while(2*k <= n) {
        int j = 2*k;

        if(j < n && a[j] < a[j+1])
            j++;

        if(a[k] >= a[j])
            break;

        swap(a[k], a[j]);
        k = j;
    }
}

// Xay dung Max Heap
void buildHeap(int *a, int n) {
    for(int k = n/2; k >= 1; k--) {
        heapify(a, n, k);
    }
}

// Sap xep tang dan
void heapSort(int *a, int n) {
    buildHeap(a, n);

    while(n > 1) {
        swap(a[1], a[n]);
        n--;
        heapify(a, n, 1);
    }
}

// In mang
void printArray(int *a, int n) {
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[100] = {0, 5, 10, 3, 8, 2, 7};
    int n = 6;

    cout << "Mang ban dau: ";
    printArray(a, n);

    buildHeap(a, n);

    cout << "Sau Build Heap: ";
    printArray(a, n);

    heapSort(a, n);

    cout << "Sau Heap Sort: ";
    printArray(a, n);

    return 0;
}
