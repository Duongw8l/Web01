#include<iostream>
using namespace std;
int main()
{
	int n, a[10], b[10];
	cout<<"n = ";
	cin>>n;
	cout<<"Nhap mang a: ";
	//y 1 
	for(int i = 0; i < n; i++)
	{
		cin>>a[i]; 
	} 
	cout<<"Nhap mang b:"; 
	for(int i = 0; i < n; i++)
	{
		cin>>b[i]; 
	}
	cout<<"Nam co the an duoc: "<<endl; 
	for(int i = 0; i < n; i++)
	{
		if(a[i]>=b[i]*2)
		{
			cout<<"("<<a[i]<<", "<<b[i]<<")"<<" "; 
		}
	}
	cout<<endl; 
	int max = b[0];
	for(int i = 0; i < n; i++)
	{
		if(b[i]>max)
		{
			max = b[i]; 
		}		 
	}
	cout<<"nam co doc to lon nhat la: "; 
	for(int i = 0; i < n; i++)
	{
		if(b[i]==max)
		{
			cout<<"("<<a[i]<<", "<<b[i]<<")";
		}		 
	}
	cout<<endl; 
	cout<<"Sap xep a: ";
	for(int i = n - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++){
			if(a[j]>a[j+1])
			{
				int tmp = a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;	 
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		if() 
	} 
	return 0; 
}