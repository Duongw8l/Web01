#include <iostream>
#include <fstream>
using namespace std;
// dinh nghia kieu du lieu thiet bi
struct ThietBi {
	// thong tin
	int giaTri, soLuong;
};

int main() {
	//Doc du lieu trong file thietbi.inp
	ifstream finp;
	finp.open("thietbi.txt");
	if (finp.fail()) {
		cout << "Mo file khong thanh cong!";
		return 0;
	}
	int n;// n la so luong thiet bi
	finp >> n;//<==> cin >> n; -- doc dong dau tien trong file
	
	// danh sach thiet bi
	ThietBi dstb[100];// mang thiet bi de luu du lieu doc duoc trong file thietbi.inp
	// doc dong so 2 -- cac gia tri cua thiet bi
	for (int i = 0; i < n; i++) {
		finp >> dstb[i].giaTri;
	}
	// doc dong so 3 -- cac so luong cua thiet bi
	for (int i = 0; i < n; i++) {
		finp >> dstb[i].soLuong;
	}

	// xu li yeu cau
	//1. tinh tong cac thiet bi co gia tri >= 100
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (dstb[i].giaTri >= 100) {
			dem++;
		}
	}
	cout << dem << endl;

	//2. Tim thiet bi co gia tri nho nhat
	int thietBiMin = dstb[0].giaTri;
	for (int i = 1; i < n; i++) {
		if (dstb[i].giaTri < thietBiMin) {
			thietBiMin = dstb[i].giaTri;
		}
	}
	//duyet qua cac thiet bi
//	for (int i = 0; i < n; i++) {
//		// kiem tra gia tri cua thiet bi thu i co min hay khong
//		if (dstb[i].giaTri == thietBiMin) {
//			// hien thi so luong
//			cout << dstb[i].soLuong << " ";
//		}
//	}
	//---------------------------------------------------------------------------------------------
	 // 3. Ghi kết quả vào file 'thietbi.out'
    ofstream fout;
    fout.open("thietbi.out");

    if (fout.fail()) {
        cout << "Mở file không thành công!";
        return 0;
    }

    // Ghi số lượng thiết bị có giá trị >= 100
    fout << dem << endl;

    // Ghi số lượng của các thiết bị có giá trị nhỏ nhất
    for (int i = 0; i < n; i++) {
        if (dstb[i].giaTri == thietBiMin) {
            fout << dstb[i].soLuong << " ";
        }
    }
    fout << endl; // Kết thúc dòng cuối cùng

    // Đóng file sau khi ghi
    fout.close();
	return 0;
}
///////////////////////////////////////////////////////////////////
//#include <iostream>
//#define SIZE 999
//using namespace std;
//
//// khai bao ham
//void nhapMang(float A[], int n);
//void hienThi(float A[], int n);
//void hienThiNamAnDuoc(float dd[], float dt[], int n);
//float timDocToMax(float dt[], int n);
//void hienThiNamCoDocToMax(float dd[], float dt[], int n);
//void sapXep(float dd[], float dt[], int n);
//int main() {
//	int n;// n la so loai nam
//	float dd[SIZE], dt[SIZE];
//
//	//1.
//	cout << "Nhap so loai nam: ";
//	cin >> n;
//
//	cout << "Nhap thong muc dinh duong cua n loai nam: ";
//	nhapMang(dd, n);
//	cout << "Nhap thong muc doc to cua n loai nam: ";
//	nhapMang(dt, n);
//
////	int n = 6;
////	float dd[] = { 6, 4, 12, 42, 5, 10 };
////	float dt[] = { 3, 9, 5, 24, 14, 2};
//
//	cout << "\nThong tin cac loai nam an dc la: ";
//	hienThiNamAnDuoc(dd, dt, n);
//	//3
//	cout << "\nThong tin cac loai nam co luong doc to cao nhat la: ";
//	hienThiNamCoDocToMax(dd, dt, n);
//	
//	//4.
//	cout << "\nThong tin cac loai nam sau khi sap xep theo chieu khong giam ve muc do dinh duong la\n";
//	sapXep(dd, dt, n);
//	return 0;
//}
//
//// trien khai ham
//void nhapMang(float A[], int n) {
//	for (int i = 0; i < n; i++) {
//		cin >> A[i];
//	}
//}
//
//void hienThi(float A[], int n) {
//	for (int i = 0; i < n; i++) {
//		cout << A[i] << "\t";
//	}
//}
//
//void hienThiNamAnDuoc(float dd[], float dt[], int n) {
//	//duyet qua tat ca cac loai nam
//	for (int i = 0; i < n; i++) {
//		if (dd[i] >= 2 * dt[i]) {
//			cout << "(" << dd[i] << ", " << dt[i] << ")\t";
//		}
//	}
//}
//
//// tim doc to cao nhat trong mang doc to
//float timDocToMax(float dt[], int n) {
//	float max = dt[0];
//	for (int i = 1; i < n; i++) {
//		if (dt[i] > max) {//cap nhat gia tri max
//			max = dt[i];// 
//		}
//	}
//	return max;
//}
//
//void hienThiNamCoDocToMax(float dd[], float dt[], int n) {
//	float maxDT = timDocToMax(dt, n);
//	// duyet qua cac loai nam
//	for (int i = 0; i < n; i++) {
//		if (dt[i] == maxDT) {
//			cout << "(" << dd[i] << ", " << dt[i] << ")\t";
//		}
//	}
//}
//
////4. sap xep cac loai nam theo chieu khong giam ve dinh duong
//void sapXep(float dd[], float dt[], int n) {
//	for (int i = 0; i < n; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (dd[i] > dd[j]) {
//				//hoan doi muc do dd cua nam
//				float tg = dd[i];
//				dd[i] = dd[j];
//				dd[j] = tg;
//
////				//hoan doi muc do doc to cua nam
////				tg = dt[i];
////				dt[i] = dt[j];
////				dt[j] = tg;
//			}
//		}
//	}
//	// duyet qua cac loai nam
//	for (int i = 0; i < n; i++) {
//		cout << "(" << dd[i] << ", " << dt[i] << ")\t";
//	}
//}

#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

// khai bao kieu du lieu ban ghi
struct NhanVien {
	// thuoc tinh
	string hoTen;
	int soLuong;// so luong may tinh ban dc
};

// khai bao ham
void nhapDSNV(NhanVien dsnv[], int n);
float tbMayBanDuoc(NhanVien dsnv[], int n);
void hienThiNVBanMayTrenTB(NhanVien dsnv[], int n);
void hienThi(NhanVien nv);
string getTen(string hoTen);

int main() {

	NhanVien dsnv[SIZE];
	int n;// n la so nhan vien cua cua hang
	cout << "Nhap so nhan vien cua cua hang: ";
	cin >> n;
	//1. 
	nhapDSNV(dsnv, n);

	//2.
	hienThiNVBanMayTrenTB(dsnv, n);
	return 0;
}

// trien khai ham
void nhapDSNV(NhanVien dsnv[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin nhan vien thu " << i + 1 << endl;
		cout << "Nhap ho ten nhan vien: ";
		cin.ignore();// bo qua phim enter trong bo dem
		getline(cin, dsnv[i].hoTen);
		cout << "Nhap so luong may tinh ban duoc: ";
		cin >> dsnv[i].soLuong;
	}
}

// tinh trung binh so luong may tinh ban dc cua n nhan vien trong cua hang
float tbMayBanDuoc(NhanVien dsnv[], int n) {
	int tongSoMayBan = 0;
	// duyet qua cac nhan vien
	for (int i = 0; i < n; i++) {
		tongSoMayBan += dsnv[i].soLuong;
	}
	float tb = (float)tongSoMayBan / n;
	return tb;
}

void hienThi(NhanVien nv) {
	cout << "\nHo ten: " << nv.hoTen;
	cout << "\nSo luong may tinh ban dc: " << nv.soLuong;

}
//2. hien thi nhan vien ban dc may tinh lon hon so luong tb cua cua hang
void hienThiNVBanMayTrenTB(NhanVien dsnv[], int n) {
	cout << "\nDanh sach nhan vien ban dc may tinh > so luong tb cua cac nv trong cua hang la\n";
	float tb = tbMayBanDuoc(dsnv, n);
	// duyet qua cac nhan vien
	for (int i = 0; i < n; i++) {
		string ten = getTen(dsnv[i].hoTen);// lay ten cua tung nhan vien
		if (dsnv[i].soLuong > tb && (ten == "Huyen"|| ten =="Trung")) {
			// hien thi thong tin
			hienThi(dsnv[i]);
		}
	}
}
// ham tra ve ten trong chuoi hoTen
string getTen(string hoTen) {
	// Nguyen Thanh Huyen
	// vi tri dau cach dau tien tu cuoi xau
	int viTriDauCach = hoTen.rfind(" ");
	// su dung ham substr() lay 1 chuoi con trong chuoi goc
	string ten = hoTen.substr(viTriDauCach + 1);
	return ten;
}
//////////////////////////////////////////////////////////////////
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//string lowercase(string s) {
//    for (int i = 0; i < s.size();i++) {
//        s[i] = tolower(s[i]);
//    }
//    return s;
//}
//
//string uppercase(string s) {
//    for (int i = 0; i < s.size();i++) {
//        s[i] = toupper(s[i]);
//    }
//    return s;
//}
//
//string cew(string s) {
//    for (int i = 0; i < s.length(); i++) {
//        if (i == 0 || s[i-1] == ' ') {
//            s[i] = toupper(s[i]);
//        }
//    }
//    return s;
//}
//
//string tcase(string s) {
//    s = cew(s);
//    for (int i = 0; i < s.size(); i++) {
//        if (isupper(s[i])) {
//            s[i] = tolower(s[i]);
//        } else {
//            s[i] = toupper(s[i]);
//        }
//    }
//    return s;   
//}
//
//int main() {
//    string s;
//    cout << "Moi nhap xau ky tu: ";
//    getline(cin, s);
//    cout << "Xau ky to goc: " << s << endl;
//    cout << "Xau ky tu sau khi lower: " << lowercase(s) << endl;
//    cout << "Xau ky tu sau khi upper: " << uppercase(s) << endl;
//    cout << "Xau ky tu Captitalize Each Word: " << cew(s) << endl;
//    cout << "Xau ky tu tOGGLE cASE: " << tcase(s);
//    return 0;
//}
/////////////////////////////////////////////////////////////////////////////////
#include<iostream>

using namespace std;

string ho(string s) {
    int fstn = s.find(' ');
    return s.substr(0, fstn);
}

string ten(string s) {
    int lstn = s.rfind(' ');
    return s.substr(lstn + 1, s.size());
}

int main() {
	
    string s;
    cout << "Moi nhap ten day du: ";
    getline(cin, s);
    cout << "Ho cua nguoi nay la: " << ho(s) << endl;
    cout << "Ten cua nguoi nay la: " << ten(s) << endl;
    return 0;
}
//////////////////////////////////////////////////////
#include<iostream>
#include<string>

using namespace std;

string anagram(string a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < i ; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    return a;
}

void output(string a, string b) {
    if (anagram(a) == anagram(b) && a.size() == b.size()) {
        cout << "a va b la anagram";
    } else {
        cout << "a va b khong la anagram";
    }
}

int main() {
    string a,b;
    cout << "Nhap chuoi a: "; getline(cin, a);
    cout << "Nhap chuoi b: "; getline(cin, b);
    output(a,b);
    return 0;
}


-------------------
#include <iostream>
#include <cmath> // Thư viện sử dụng sqrt (căn bậc hai)
using namespace std;

bool laSoChinhPhuong(int n) {
    int sqrt_n = sqrt(n);
    return (sqrt_n * sqrt_n == n){
	
}

int main() {
    // Hiển thị các số chính phương nhỏ hơn 10000
    cout << "Các số chính phương nhỏ hơn 10000 là:" << endl;
    for (int i = 1; i < 10000; i++) {
        if (laSoChinhPhuong(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    // Đếm các số chính phương nhỏ hơn 1000
    int count = 0;
    for (int i = 1; i < 1000; i++) {
        if (laSoChinhPhuong(i)) {
            count++;
        }
    }
    cout << "Tổng số số chính phương nhỏ hơn 1000 là: " << count << endl;

    return 0;
}
