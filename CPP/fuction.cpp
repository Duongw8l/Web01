#include<iostream>

 float show_heath(float h, float w ) { // hàm 
 	float BMI = w / (h*h);
 	
 	
 	if(BMI<=18.5){
 		std::cout<<" thieu can";
	 }
	else if(BMI>18.5 && BMI<=24.9){
		std::cout<<" binh thuong";
	}
		
	else{
		std::cout<<"thua can";
	}
	return 0;
	
 	
 }

int main(){
	
	float weight;
	float height;
	
	std::cout<<" weight= ";
	std::cin>>weight;
	
	std::cout<<" height= ";
	std::cin>>height;
	
	std::cout<<"nam 1: ";
	show_heath(height,weight);
	std::cout<<show_heath;
	
	std::cout<<"\n"<<"nam 2: ";
	weight += 1;
	show_heath(height,weight);
	std::cout<<show_heath;
	
}
/* BMI = nặng/(cao^2)
<18,5: thiếu cân
18,5-24,9: bình thường
>25: thừa*/