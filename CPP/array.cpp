
#include <iostream>
/*
// MẢNG bài 1
int main(){
	int a[3] = {1, 2, 3};
	a[0] *=10;
	
	 // std::cout<< a; in ra địa chỉ của biến a( point )
	std::cout << a[0] << a[1] << a[2];
}
// dấu ngoặc vuông[] được sử dụng khi KHAI BÁO và index( chỉ mục) các phần tử
*/




// mảng bài2: duyệt mảng bằng for
/*int main(){
	int a[5] = {5, 10, 15, 20, 25};
	for(int i=0; i < 5; i++){
		std::cout<< a[i];
	}	
}*/




//mảng baif3: range base for
int main(){
	int a[5] = {1, 3, 5, 7, 9};
	for(int& z:a){
		z+=10;
		std::cout<<z<<"\n";
	}
}

