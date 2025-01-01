#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
struct diemthi{
	string thanhpho;
	float diemthi2022;
	float diemthi2023;
	float chenhlech;
};
void input(diemthi dt[], int n, ifstream &finp){
	finp.ignore();
	for( int i = 0; i < n; i++){
		finp.ignore();
		getline(finp,dt[i].thanhpho);
		finp >> dt[i].diemthi2022;
		finp >> dt[i].diemthi2023;
		dt[i].chenhlech = abs(dt[i].diemthi2022 - dt[i].diemthi2023);
	}
}
void caua(int n, diemthi dt[], ofstream &fout){
	float min = dt[0].chenhlech;
	for(int i = 0; i<n; i++){
		if(dt[i].chenhlech < min){
			min = dt[i].chenhlech;
		}
	}
	for (int i = 0; i < n; i++){
		if (dt[i].chenhlech == min){
			fout << dt[i].thanhpho << " " << dt[i].chenhlech << endl;
		}
	}
}
void sapxep(int n, diemthi dt[], ofstream &fout){
	for (int i = 0; i< n - 1; i++){
		for(int j = i+1; j < n; j++){
			if(dt[i].chenhlech < dt[j].chenhlech){
				swap(dt[i].chenhlech,dt[j].chenhlech);
			}
		}
	}
	for (int i = 0; i< n;i++){
		fout << dt[i].thanhpho << " " << dt[i].chenhlech << endl;
	}
}
int main (){
	ifstream finp;
	ofstream fout;
	finp.open("diemthi.inp");
	fout.open("diemthi.out");
	if (!finp){
		cout << "mo file khong thanh cong " << endl;
		return 1;
	}else{
		cout << "mow file thanh cong " << endl;
	}
	if (!fout){
		cout << "ghi file khong thanh cong " << endl;
		return 1;
	}else{
		cout << "ghi file thanh cong " << endl;
	}
	int n;
	finp >> n;
	diemthi dt[n];
	input(dt,n,finp);
	caua(n,dt,fout);
	sapxep(n,dt,fout);
	finp.close();
	fout.close();
	return 0;
}
