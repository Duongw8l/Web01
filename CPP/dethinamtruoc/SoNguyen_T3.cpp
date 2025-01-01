#include <iostream>
#include <fstream>
using namespace std;

bool kiemTraSCP(int n) {
	int x = sqrt(n);
	if (x * x == n) {
		return true;
	}
	else {
		return false;
	}
	// return x * x == n;
}

int main() {
	// Doc du lieu trong file songuyen.inp
	ifstream finp;
	finp.open("songuyen.inp");
	if (finp.fail()) {
		cout << "Mo file khong thanh cong!";
		return 0;
	}
	
	// 1. Tim so luong cac so nguyen trong file
	int arr[100];// mang arr de luu tru gia tri doc duoc o trong file
	int i = 0;//i la chi so cua mang
	//int dem = 0;
	while (!finp.eof()) {
		finp >> arr[i];
		i++;
		//dem++;
	}

	// ghi du lieu vao file
	ofstream fout;
	fout.open("songuyen.out");
	if (fout.fail()) {
		cout << "Tao file khong thanh cong!";
		return 0;
	}

	int n = i;// n la so phan tu cua mang
	fout << n << endl;

	//2. Tim so nho thu 2 trong file
	//2.1 Tim so nho nhat
	int min = arr[0];// gia su phan tu dau tien la min
	// duyet qua cac phan tu con lai
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];// cap nhat gia tri cua min
		}
	}
	//2.2 Tim so lon nhat
	int max = arr[0];// gia su phan tu dau tien la max
	// duyet qua cac phan tu con lai
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];// cap nhat gia tri cua max
		}
	}

	//2.3 Tim so nho thu 2
	int min2 = max;// gan phan tu max cho min2
	for (int i = 0; i < n; i++) {
		if (arr[i] != min && arr[i] < min2) {
			min2 = arr[i];
		}
	}
	if (min2 == max) {
		fout << "-1" << endl;
	}
	else {
		fout << min2 << endl;
	}

	//3. Bien doi day so (mang arr) theo quy luat
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			arr[i] = arr[i] * 2;
		}
		else {
			arr[i] *= 3;
		}
	}

	// duyet qua cac phan tu trong mang arr
	for (int i = 0; i < n; i++) {
		if (kiemTraSCP(arr[i]) == true) {
			fout << arr[i] << " ";
		}
	}

	// dong file
	finp.close();
	fout.close();

	return 0;
}