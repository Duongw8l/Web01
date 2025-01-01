#include <iostream>
#include <cmath> // Thư viện sử dụng sqrt (căn bậc hai)
using namespace std;
int n;

void nhapDL(){
	
	cout << "nhap so nguyen duong: ";
	cin >> n;

}

bool laSoChinhPhuong(int n) {
    int sqrt_n = sqrt(n);
     if(sqrt_n * sqrt_n == n){
     	return true;
	 }else{
	 	return false;
	 }
}

void so(){
	// Hiển thị các số chính phương nhỏ hơn 10000
    cout << "cac so chinh phuong nho :" << endl;
    for (int i = 1; i < 10000; i++) {
        if (laSoChinhPhuong(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void dem(){
	// Đếm các số chính phương nhỏ hơn 1000
    int count = 0;
    for (int i = 1; i < 1000; i++) {
        if (laSoChinhPhuong(i)) {
            count++;
        }
    }
    cout << "Tong cac so chinh phuong nho " << count << endl;

}

int main() {
	nhapDL();
	so();
    dem();

    
    return 0;
}
