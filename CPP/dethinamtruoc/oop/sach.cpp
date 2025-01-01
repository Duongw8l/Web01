#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class sach {
private:
    string tensach, tenXB;
    int namXB, soluong;
    bool trangthai;

public:
    // Constructor mặc định
    sach() {
        tensach = "";
        tenXB = "";
        namXB = 0;
        soluong = 0;
        trangthai = false;
    }

    // Constructor có tham số
    sach(string tensach, string tenXB, int namXB, int soluong, bool trangthai) {
        this->tensach = tensach;
        this->tenXB = tenXB;
        this->namXB = namXB;
        this->soluong = soluong;
        this->trangthai = trangthai;
    }

    // Hàm nhập dữ liệu
    void input() {
        cin.ignore(); // Xử lý ký tự xuống dòng còn sót
        cout << "Nhập tên sách: ";
        getline(cin, tensach);

        cout << "Nhập tên nhà xuất bản: ";
        getline(cin, tenXB);

        cout << "Nhập năm xuất bản: ";
        cin >> namXB;

        cout << "Nhập số lượng: ";
        cin >> soluong;

        cout << "Nhập trạng thái (1: có sẵn, 0: không có sẵn): ";
        cin >> trangthai;
    }

    // Hàm hiển thị dữ liệu
    void output() const {
        cout << "Tên sách: " << tensach << "\n";
        cout << "Tên nhà xuất bản: " << tenXB << "\n";
        cout << "Năm xuất bản: " << namXB << "\n";
        cout << "Số lượng: " << soluong << "\n";
        cout << "Trạng thái: " << (trangthai ? "Có sẵn" : "Không có sẵn") << "\n";
    }

    // Getter cho tên sách
    string getTenSach() const {
        return tensach;
    }

    // Getter cho năm xuất bản
    int getNamXB() const {
        return namXB;
    }
};

// Hàm sắp xếp danh sách sách theo tên (tăng dần)
void sapXepTheoTen(vector<sach>& list) {
    sort(list.begin(), list.end(), [](const sach& a, const sach& b) {
        return a.getTenSach() < b.getTenSach();
    });
    cout << "\nDanh sách sách sau khi sắp xếp theo tên:\n";
    for (const auto& s : list) {
        s.output();
        cout << "-------------------------\n";
    }
}

// Hàm lấy danh sách sách xuất bản trước năm 1990
void laySachTruoc1990(const vector<sach>& list) {
    cout << "\nDanh sách các sách xuất bản trước năm 1990:\n";
    bool found = false;
    for (const auto& s : list) {
        if (s.getNamXB() < 1990) {
            s.output();
            cout << "-------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Không có sách nào xuất bản trước năm 1990.\n";
    }
}

int main() {
    vector<sach> list; // Danh sách chứa các quyển sách
    int n;

    cout << "Số lượng sách cần nhập: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nNhập thông tin sách thứ " << i + 1 << ":\n";
        sach s;
        s.input();
        list.push_back(s);
    }

    cout << "\nDanh sách sách vừa nhập:\n";
    for (int i = 0; i < list.size(); i++) {
        cout << "\nThông tin sách thứ " << i + 1 << ":\n";
        list[i].output();
        cout << "-------------------------\n";
    }

    // Gọi hàm sắp xếp theo tên sách
    sapXepTheoTen(list);

    // Gọi hàm lấy các sách xuất bản trước năm 1990
    laySachTruoc1990(list);

    return 0;
}
