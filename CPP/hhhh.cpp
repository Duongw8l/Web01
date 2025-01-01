#include <iostream>

int main(){
	int number[10];
	int x,n;
	
	std::cout<<"n= ";//só phần tử nhập vào
	std::cin>>n;
	
	std::cout<<" nhap mang: ";
	
	for(int i=0; i < n; i++){ // vòng lặp kiểm tra nhập các các phần tử
		std::cin>>number[i];
		
	}
	std::cout<<"x= "; // phần tử được thêm vào cuối
	std::cin>>x;
	
	
	number[n] = x;n++;
	std::cout<<"mang sau khi: ";
	for(int i = 0; i < n; i++){
		std::cout<<number[i]<<" ";
	}
	
}