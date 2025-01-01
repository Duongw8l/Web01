#include <iostream>
using namespace std;

class ConNguoi{
	private:
		string hoten, diachi;
		int tuoi;
	public:
		void input(){
			cout << "Nhap ho ten: ";
			getline(cin, hoten);
			cout << "nhap dia chi: ";
			getline(cin, diachi);
			cout << "Nhap tuoi: ";
			cin >> tuoi;
		}
		ConNguoi(){
			hoten = "nguyen minh duong";
			diachi = "58, tran binh";
		}
		ConNguoi(string hoten1, string diachi1, int tuoi1){
			hoten = hoten1;
			diachi = diachi1;
			tuoi = tuoi1;
		}
		ConNguoi(ConNguoi &c){
			hoten = c.hoten;
			diachi = c.diachi;
			tuoi = c.tuoi
		}
		
		
};
class hocsinh : public ConNguoi{
		//thuoc tinh/thanh phan
		private:
			float diemToan, diemLy, diemHoa;
			//phuong thuc
		public:
			//1.Ham khoi tao khong tham so
			hocsinh() :ConNguoi(){
				diemToan = 10;
				diemLy   = 10;
				diemHoa  = 10;
			}
			//2.Ham tao co tham so
			SinhVien(int diemToan, int diemLy, int diemHoastring hoTen, string diachi, int tuoi):ConNguoi(diemToan, diemLy, diemHoa){
				this -> diemToan = diemToan;
				this -> diemLy = diemLy;
				this -> diemHoa = diemHoa;
			}
			
			void hienThi(){
				ConNguoi::hienThi();
				cout << "diem toan: " << diemToan << "; diem ly " << diemLy << "; diem hoa" << diemHoa;
			}
			float diemTB(int a, int b, int c){
				int diemTB = (a*3 + b*2 + c) / 63;
				return diemTB;
			}
			
};