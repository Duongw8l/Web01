#include <iostream>
#include <fstream>
using namespace std;

int main(){
	//doc du liệu trong file
	ifstream finp;
	finp.open("songuyen.txt");
	if(finp.fail()){
		cout << "mo file fail";
		return 0;
	}
	int n;
	finp >> n; //đọc dòng đầu tiên và lưu vào biến n
	
	//đọc dòng 2
	int arr[100]; // khai báo amngr số nguyên
	int i = 0;
	while(!finp.eof()){ //kiểm tra xem đọc đến cuối file hay chưa, nếu chưa
		finp >> arr[i];
		if(finp.eof()){
			break;
		}
		i++;
	}
	int sophantucuamang = i;
	
	cout << "cac phan tu cua mang la: ";
	for( int i = 0; i < sophantucuamang; i++){
		cout << arr[i] << endl;
	}
	
	//tỉnh tổng các phần tử ở vị trí lẻ
	int tong = 0;
	for(int i =0; i < sophantucuamang; i++){
		if((i+1) / 2 != 0){
			tong += arr[i];
		}
	}
	
	//ghi ket qua vào file
	ofstream fout;
	fout.open("nguyenout.txt");
	if(fout.fail()){
		cout << "tao file fail";
		return 0 ;
	}
	fout << tong << endl;
	
	//tìm số nguyên khác nhau
	int brr[100];
	brr[0] = arr[0];
	int j = 1; // j là chỉ số của mảng brr
	for( int i = 1; i < sophantucuamang; i++){
		int dem = 0;
		
		//duyệt qua phần tử của brr
		for(int k = 0; k < j; k++){
			if(arr[i] = brr[k]){
				dem++;
				break;
			}
			if(dem = 0){
				brr[j] = arr[i];
				j++;
			}
		}
	}
	
	//hiển thị brr
	cout << "hien thi mang b: ";
	for(int i = 0; i < j; i++){
		fout << brr[i];
	}
	
	
}