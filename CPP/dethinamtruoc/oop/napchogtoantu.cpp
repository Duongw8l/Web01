#include<iostream>
using namespace std;

class TTime{
	private: //khai báo thuộc tính
		int h, m, s; 
	public: //khai báo phương thức
		void input(){
			cin>>h>>m>>s;   //phương thức nhập
		}
		void output(){
			cout<<h<<" "<<m<<" "<<s<<endl;   //phương thức xuất
		}
		
		
		TTime(){ //phương thức khởi tạo không có tham số
			h=0;
			m=0;
			s=0;
		}
		TTime( int h1, int m1, int s1){ //phương thức có tham số
			h = h1;
			m = m1;
			s = s1;
		}
		
		//---------------------------------------------------------------------------
		friend bool operator>(TTime t1, TTime t2){ //hàm bạn so sánh
			int TTime_t1 = t1.h*3600 + t1.m*60 + t1.s;
			int TTime_t2 = t2.h*3600 + t2.m*60 + t2.s;
			if( TTime_t1 > TTime_t2){
				return true;
			} 
			return false;
		}
		friend bool operator<(TTime t1, TTime t2){
			int TTime_t1 = t1.h*3600 + t1.m*60 + t1.s;
			int TTime_t2 = t2.h*3600 + t2.m*60 + t2.s;
			if( TTime_t1 < TTime_t2){
				return true;
			} 
			return false;
		}
		//---------------------------------------------------------------------------
		
		friend istream & operator>>(istream &is, TTime &t){//hàm bạn nhập xuất
			is >> t.h >> t.m >> t.s;
			return is;
		}
		friend ostream & operator<<(ostream &os, TTime &t){
		
			os << t.h << t.m << t.s;
			return os;
		}
		
		
		
};

int main(){
	TTime t1, t2, t3;
	cin >> t1 >> t2 >> t3;
	TTime max;
	max = t1;
	if(t2 < max){
		max = t2;
	}
	if(t3 < max){
		max = t3;
	}
	cout << max;
	
}