//Viết chương trình nhận đầu vào là mảng 2 chiều có kích thước N×M

//Viết hàm xóa dòng thứ i trong mảng 2 chiều
// Do phuc tap thoi gian: O(N*M)
// Do phuc tap bo nho: O(1)
#include <iostream>
using namespace std;
void xoaDong(int arr[][100], int& N, int M, int i) {
    if (i < 0 || i >= N) {
        cout << "Dong khong hop le!" << endl;
        return;
    }
    for (int row = i; row < N - 1; row++) {
        for (int col = 0; col < M; col++) {
            arr[row][col] = arr[row + 1][col];
        }
    }
    N--; 
} 
int main() {
    int N, M;
    cin >> N >> M;
    int arr[100][100]; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    
    int i;
    cin >> i; 
    xoaDong(arr, N, M, i);
    
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    
    return 0;
}