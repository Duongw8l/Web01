#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string str;
    std::cout << "Nhập chuỗi: ";
    std::getline(std::cin, str);

    // Chuyển đổi mỗi từ thành chữ hoa
    for (int i = 0; i < str.length(); i++) {
        // Kiểm tra xem ký tự hiện tại có phải là ký tự đầu tiên của một từ không
        if (i == 0 ) {
            str[i] = std::toupper(str[i]);
        }
    }

    std::cout << "chuoi: " << str << std::endl;

    return 0;
}
