#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Lớp Author
class Author {
protected:
    string authorName;
    string email;
public:
    // Hàm cấu tử không tham số
    Author() : authorName(""), email("") {}

    // Hàm cấu tử có tham số
    Author(string name, string mail) : authorName(name), email(mail) {}

    // Phương thức nhập thông tin tác giả
    void inputAuthor() {
        cout << "Nhap ten tac gia: ";
        cin.ignore();
        getline(cin, authorName);
        cout << "Nhap email cua tac gia: ";
        cin >> email;
    }

    // Phương thức trả về tên tác giả
    string getAuthorName() const {
        return authorName;
    }

    // Phương thức hiển thị thông tin tác giả
    void displayAuthor() const {
        cout << "Ten tac gia: " << authorName << ", Email: " << email << endl;
    }
};

// Lớp Book kế thừa từ Author
class Book : public Author {
private:
    string bookName;
    float price;
public:
    // Hàm cấu tử không tham số
    Book() : Author(), bookName(""), price(0.0) {}

    // Hàm cấu tử có tham số
    Book(string bName, float bPrice, string aName, string aEmail)
        : Author(aName, aEmail), bookName(bName), price(bPrice) {}

    // Phương thức nhập thông tin sách
    void inputBook() {
        cout << "Nhap ten sach: ";
        cin.ignore();
        getline(cin, bookName);
        cout << "Nhap gia sach: ";
        cin >> price;

        // Gọi phương thức nhập thông tin tác giả từ lớp cha
        inputAuthor();
    }

    // Phương thức hiển thị thông tin sách
    void displayBook() const {
        cout << "Ten sach: " << bookName << ", Gia: " << price << endl;
        displayAuthor();
    }

    // Trả về giá sách
    float getPrice() const {
        return price;
    }

    // Trả về tên sách
    string getBookName() const {
        return bookName;
    }
};

int main() {
    int n;
    cout << "Nhap so luong sach: ";
    cin >> n;

    vector<Book> books(n);

    // Nhập danh sách sách
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin cho cuon sach thu " << i + 1 << ":\n";
        books[i].inputBook();
    }

    // Tìm sách có giá cao nhất
    float maxPrice = books[0].getPrice();
    for (int i = 1; i < n; ++i) {
        if (books[i].getPrice() > maxPrice) {
            maxPrice = books[i].getPrice();
        }
    }

    cout << "\nCac cuon sach co gia cao nhat la:\n";
    for (int i = 0; i < n; ++i) {
        if (books[i].getPrice() == maxPrice) {
            books[i].displayBook();
        }
    }

    // Tìm sách theo tên tác giả
    string searchAuthor;
    cout << "\nNhap ten tac gia can tim kiem: ";
    cin.ignore();
    getline(cin, searchAuthor);

    bool found = false;
    cout << "\nCac cuon sach cua tac gia \"" << searchAuthor << "\" la:\n";
    for (int i = 0; i < n; ++i) {
        if (books[i].getAuthorName() == searchAuthor) {
            books[i].displayBook();
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay cuon sach nao cua tac gia \"" << searchAuthor << "\".\n";
    }

    return 0;
}
