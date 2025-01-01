#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m; //khai báo n,m

    // a. Nhập n, m và ma trận từ bàn phím
    cout << "Nhập số hàng n: ";
    cin >> n;
    cout << "Nhập số cột m: ";
    cin >> m;

   

    int matrix[n][m];
    cout << "Nhập các phần tử của ma trận:\n";
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            cin >> matrix[i][j];
        }
    }

    // b. Hiển thị ma trận đã nhập
    cout << "\nMa trận đã nhập:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // c. Đếm số lượng số chẵn khác nhau trong ma trận
    set<int> evenNumbers; // Tập hợp để lưu các số chẵn duy nhất
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] % 2 == 0) {
                evenNumbers.insert(matrix[i][j]); // Thêm số chẵn vào tập hợp
            }
        }
    }

    cout << "\nSố lượng số chẵn khác nhau trong ma trận: " << evenNumbers.size() << endl;

    return 0;
}
