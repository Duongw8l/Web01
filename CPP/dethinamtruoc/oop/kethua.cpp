#include <iostream>
using namespace std;

class ConNguoi{
	//thuoc tinh //thanh phan du lieu
	private:
		string hoTen;
		int tuoi;
	public:
		//1.Ham tao
		ConNguoi(){
			hoTen = "Nguyen Van A";
			tuoi = 24;
		}
		//2.Ham tao co tham so
		ConNguoi(string hoTen, int tuoi){
			this ->hoTen = hoTen;
			this ->tuoi = tuoi;
		}
		//3. Ham huy
		~ConNguoi(){
		}
		
		
		//4.Ham nhap du lieu
		void nhapDuLieu()	{
			cout << "Nhap ho ten: ";
			getline(cin, hoTen);
			cout << "Nhap tuoi: ";
			cin >> tuoi;
		}
		
		//5.Ham hien thi du lieu
		void hienThi(){
			cout << "Ho ten: " 	<<hoTen;
			cout << " Tuoi: " 	<<tuoi;
		}
};

//khai bao lop con kee thhua lop cha
class SinhVien : public ConNguoi{
		//thuoc tinh/thanh phan
		private:
			string chuyenNganh, tenTruong;
			//phuong thuc
		public:
			//1.Ham khoi tao khong tham so
			SinhVien() :ConNguoi(){
				chuyenNganh = "Cntt";
				tenTruong = "HNUE";
			}
			//2.Ham tao co tham so
			SinhVien(string hoTen, int tuoi, string chuyenNganh, string tenTruong):ConNguoi(hoTen, tuoi){
				this -> chuyenNganh = chuyenNganh;
				this -> tenTruong = tenTruong; 
			}
			
			void hienThi(){
				ConNguoi::hienThi();
				cout << ", chuyen nganh: " << chuyenNganh << ", ten truong: " << tenTruong;
			}
			
};



int main(){
	SinhVien sv;
	sv.hienThi();
	cout << endl;
	SinhVien sv1("Nguyen Van B",20,"Toan", "HNUE");
	sv1.hienThi();
	return 0;
}