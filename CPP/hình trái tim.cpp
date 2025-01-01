
#include<iostream>
using namespace std;

int main() {
    int n = 8; // Kích thước của hình trái tim
    
    // Vẽ phần trên của hình trái tim
    for (int i = n/2; i <= n; i += 2) {
        // Vẽ khoảng trắng
        for (int j = 1; j < n-i; j += 2) {
            cout << " ";
        }
  
        // Vẽ phần trái của hình trái tim
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
  
        // Vẽ khoảng trắng giữa hai phần của hình trái tim
        for (int j = 1; j <= n-i; j++) {
            cout << " ";
        }
  
        // Vẽ phần phải của hình trái tim
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
  
        cout << endl;
    }
  
    // Vẽ phần dưới của hình trái tim
    for (int i = n; i >= 1; i--) {
        // Vẽ khoảng trắng
        for (int j = i; j < n; j++) {
            cout << " ";
        }
  
        // Vẽ phần trái của hình trái tim
        for (int j = 1; j <= (i*2)-1; j++) {
            cout << "*";
        }
  
        cout << endl;
    }
    cout<<"Nhan ngay 20-10 to xin chuc cac ban va cac chj trong lsfr hanh phuc moi ngay"<<"\n ngay cang xinh dep, van may toi nhieu va luon luon co nguoi thuong ben minh."<<"\n <3"<<"\n <3"<<"\n <3";
  
    return 0;
}
