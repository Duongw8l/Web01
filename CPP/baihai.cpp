#include<iostream>
using namespace std;
int main(){
	float n, arr[10];
	cout<<"n = ";
	cin>>n;
	cout<<"Nhap mang: "; 
	for(int i = 0; i < n; i++){
		cin>>arr[i]; 
	}
	cout<<"In mang: "; 
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" "; 
	}
	cout<<endl; 
	int sum=0; 
	for(int i = 0; i < n; i++){
		if(arr[i]>=0){
			sum+=arr[i];	
		} 	 
	}
	cout<<"sum = "<<sum;
	int min=arr[0]; 
	for(int i = 0; i < n; i++){
		if(min>arr[i]){
			min=arr[i]; 
		} 
	}
	cout<<endl; 
	cout<<"vi tri so co gt nho nhat: "; 
	for(int i = 0; i < n; i++){
		if(min==arr[i]){
			cout<<i<<" "; 
		} 
	} 
	 
	return 0;	 
}