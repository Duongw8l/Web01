#include<iostream>
#include<string>
#include<cctype>

int main(){
	string s;
	getline(cin,s);
	
	//1
	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ")+1);
	
	std::cout<<s;
	
	//2
	int so_luong_tu = o;
	bool trong_tu= false;
	for(char c: s){
		if(isalpha(c)){
			if (!tron_tu){
				++so_luong_tu;
				trong_tu=true;
			}
			else{
				trong_tu=false;
			}
		}
		std::cout<<so_luon_tu;
	}
	//3
	int main(){
	std::string s;
	std::cout<<" Nhap chuoi: ";
	std::getline(std::cin,s);
	
	for(int i=0; i < s.length(); i++){
		if(i==0 || s[i-1]==' '){
			s[i]=std::toupper(s[i]);
		}
		else{
			s[i]=std::tolower(s[i]);
		}
	}
	std::cout<<" Chuoi: "<<s<<std::endl;
}
	
}