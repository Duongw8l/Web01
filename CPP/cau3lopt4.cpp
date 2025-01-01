#include <iostream>
#include <cctype>


using namespace std;
/*
int main() {
    string text = " d d dddd dđ ";
    int lower_count = 0;
    int digit_count = 0;
    int special_count = 0;

    for (char c : text) {
        if (islower(c)) { //kiểm tra xem kí tự có phải là chữ cái thường hay không
            lower_count++;
        } else if (isdigit(c)) { //kiểm tra xem kí tự có phải là chữ số hay không
            digit_count++;
        } else if (!isspace(c)) { //kiểm tra xem kí tự có phải là dấu cách hay không
            special_count++;
        }
    }

    cout << "Number of lowercase letters: " << lower_count << endl;
    cout << "Number of digits: " << digit_count << endl;
    cout << "Number of special characters: " << special_count << endl;

    return 0;
}
 
#include <iostream>
using namespace std;
*/
int main() {
    string text = "deptry2 !@#special characters";
    int lower_count = 0;
    int digit_count = 0;
    int special_count = 0;

    for (char c : text) {
        if (c >= 'a' && c <= 'z') {
            lower_count++;
        } else if (c >= '0' && c <= '9') {
            digit_count++;
        } else if (c = ' ') {
            special_count++;
        }
    }

    cout << "Number of lowercase letters: " << lower_count << endl;
    cout << "Number of digits: " << digit_count << endl;
    cout << "Number of special characters: " << special_count << endl;

    return 0;
}
