#include <iostream>
using namespace std;

class TCirle {
	private:
		int x, y, r;
	public:
		void input(){
			cin >> x >> y >> r;
		}
		void output(){
			cout << x <<" "<< y <<" "<< r << endl;
		}
		TCirle(){ // tạo không tham số
			x = 0;
			y = 0;
			r = 0;
		}
		TCirle(int x1, int y1, int r1){ // tạo có tham số
			x = x1;
			y = y1;
			r = r1;
		}
		TCirle(TCirle &t){ //tạo sao chép
			x = t.x;
			y = t.y;
			r = t.r;
		}
		friend bool operator>(TCirle t1, TCirle t2){
			float s1 , s2;
			s1 = 3,14 * t1.r * t1.r;
			s2 = 3,14 * t2.r * t2.r;
			if(s1 > s2){
				return true;
			}
			return false;
		}
		friend bool operator<(TCirle t1, TCirle t2){
			float s1 , s2;
			s1 = 3,14 * t1.r * t1.r;
			s2 = 3,14 * t2.r * t2.r;
			if(s1 < s2){
				return false;
			}
			return true;
		}
		friend istream & operator>>(istream &is, TCirle &t){
			is >> t.x >> t.y >> t.r;
			return is;
		}
		friend ostream & operator<<(ostream &os, TCirle &t){
			os << t.x << t.y << t.r;
			return os;
		}
};

int main(){
	TCirle t1, t2, t3;
	cin >> t1>>t2>>t3;
	TCirle min;
	min = t1;
	if(t2 < min){
		t2 = min;
	}
	if(t3 < min){
		t3 = min;
	}
	cout << min;
}