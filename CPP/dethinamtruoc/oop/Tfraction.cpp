#include <iostream>
using namespace std;

int UCLN( int a, int b){
	if( a % b == 0){
		return b;
	}
	return UCLN( b , a%b );
}

class Tfraction{
	private:
		int a, b;
	public:
		void input(){
			cin >> a >> b;
		}
		void output(){
			cout << a <<" "<< b<<endl;
		}
		void rutgon(){
			if( a == 0){
				a = a;
				b = b;
			}else{
				int k = UCLN( a,b);
				a = a/k;
				b = b/k;
			}
		}
		Tfraction(){
			a = 0;
			b = 1;
		}
		Tfraction(int a1, int b1){
			a = a1;
			b = b1;
		}
		fraction(Tfraction &t){
			a = t.a;
			b = t.b;
		}
		friend Tfraction operator*( Tfraction t1, Tfraction t2){
			Tfraction kq;
			kq.a = t1.a * t2.a;
			kq.b = t1.b * t2.b;
			kq.rutgon();
			return kq;
		}
		
		friend istream & operator>>( istream &is, Tfraction &t){
			is >> t.a >> t.b;
			return is;
		}
		friend ostream & operator<<( ostream &os, Tfraction &t){
			os << t.a <<"\n"<<"-"<<"\n"<< t.b;
			return os;
		}
		
};


int main(){
	Tfraction t1 , t2;
	cin >> t1 >>t2;
	
	Tfraction kq;
	kq = t1 * t2;
	
	cout << kq;
	

}