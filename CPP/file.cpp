#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("dayso.txt"); // Mở file để đọc dữ liệu
    if (!file) {
        std::cout << "Khong the mo file." << std::endl;
        return 0;
    }

    int count = 0; // Biến đếm số chẵn

    int number;
    while (file >> number) { // Đọc từng số trong file
        if (number % 2 == 0) { // Kiểm tra số chẵn
            count++;
        }
    }

    file.close(); // Đóng file

    std::cout << "So luong so chan trong file: " << count << std::endl; // In kết quả

    return 0;
}
