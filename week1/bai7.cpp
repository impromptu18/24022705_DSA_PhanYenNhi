// Viết chương trình nhận đầu vào là mảng 2 chiều có kích thước N×M

// Viết hàm tính tổng các phần tử trong mảng

// Do phuc tap thoi gian: O(N*M)
// Do phuc tap bo nho: O(1)
#include <iostream> 
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    int arr[100][100]; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum += arr[i][j];
        }
    }
    
    cout << "Tong cac phan tu trong mang la: " << sum << endl;
    return 0;
}