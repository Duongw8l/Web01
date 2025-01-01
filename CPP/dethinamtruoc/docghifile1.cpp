#include <iostream>
#include <fstream>
using namespace std;

int main(){
	//doc du liệu trong file
	ifstream finp;
	finp.open("songuyen.inp");
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
	
	
}