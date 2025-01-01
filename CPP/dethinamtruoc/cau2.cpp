#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// Struct để lưu thông tin của mỗi tỉnh/thành phố
struct TinhThanh {
    string name;  // Tên tỉnh/thành phố
    double diff;  // Chênh lệch điểm trung bình
};

// Hàm so sánh để sắp xếp chênh lệch tăng dần
bool compareDiff(const TinhThanh &a, const TinhThanh &b) {
    return a.diff < b.diff;
}

int main() {
    ifstream input("diemthi.inp");  // Mở file input
    ofstream output("diemthi.out"); // Mở file output

    if (!input || !output) {
        cerr << "Loi mo file!" << endl;
        return 1;
    }

    int n;
    input >> n; // Đọc số lượng tỉnh/thành phố

    vector<TinhThanh> listTinhThanh; // Danh sách lưu thông tin tỉnh/thành phố

    // Đọc dữ liệu từ file
    for (int i = 0; i < n; ++i) {
        TinhThanh tt;
        double diem2022, diem2023;

        input.ignore(); // Loại bỏ ký tự xuống dòng còn lại
        getline(input, tt.name); // Đọc tên tỉnh/thành phố
        input >> diem2022 >> diem2023; // Đọc điểm 2022 và 2023

        tt.diff = abs(diem2023 - diem2022); // Tính chênh lệch điểm tuyệt đối
        listTinhThanh.push_back(tt); // Thêm vào danh sách
    }

    // Sắp xếp danh sách theo chênh lệch điểm tăng dần
    sort(listTinhThanh.begin(), listTinhThanh.end(), compareDiff);

    // Ghi top 3 tỉnh/thành phố có chênh lệch nhỏ nhất
    for (int i = 0; i < min(3, (int)listTinhThanh.size()); ++i) {
        output << listTinhThanh[i].name << " " << listTinhThanh[i].diff << endl;
    }

    // Ghi toàn bộ danh sách đã sắp xếp theo yêu cầu b
    for (const auto &tt : listTinhThanh) {
        output << tt.name << endl;
    }

    // Đóng file
    input.close();
    output.close();

    return 0;
}