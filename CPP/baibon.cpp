#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string s;
    std::cout << "nhap chuoi ";
    std::getline(std::cin, s);

    // Chuyển đổi mỗi từ thành chữ hoa
    for (int i = 0; i < s.length(); i++) {
        // Kiểm tra xem ký tự hiện tại có phải là ký tự đầu tiên của một từ không
        if (i == 0 || s[i - 1] == ' ') {
            s[i] = std::toupper(s[i]);
        }
        else{
        	s[i]= std::tolower(s[i]);
		}
    }

    std::cout << "chuoi: " << s << std::endl;

    return 0;
}
