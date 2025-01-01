#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Lớp Employee
class Employee {
protected:
    string name;       // Họ tên
    double baseSalary; // Lương cơ bản

public:
    // Hàm cấu tử không tham số
    Employee() {
        name = "";
        baseSalary = 0.0;
    }

    // Hàm cấu tử có tham số
    Employee(string name, double baseSalary) {
        this->name = name;
        this->baseSalary = baseSalary;
    }

    // Phương thức nhập thông tin nhân viên
    virtual void input() {
        cin.ignore();
        cout << "Nhập họ tên: ";
        getline(cin, name);
        cout << "Nhập lương cơ bản: ";
        cin >> baseSalary;
    }

    // Phương thức trả về lương cơ bản
    double getBaseSalary() const {
        return baseSalary;
    }

    // Phương thức hiển thị thông tin nhân viên
    virtual void output() const {
        cout << "Họ tên: " << name << "\nLương cơ bản: " << baseSalary << endl;
    }
};

// Lớp Manager kế thừa từ Employee
class Manager : public Employee {
private:
    double bonus;  // Thưởng
    int seniority; // Thâm niên (số năm)

public:
    // Hàm cấu tử không tham số
    Manager() : Employee() {
        bonus = 0.0;
        seniority = 0;
    }

    // Hàm cấu tử có tham số
    Manager(string name, double baseSalary, double bonus, int seniority)
        : Employee(name, baseSalary) {
        this->bonus = bonus;
        this->seniority = seniority;
    }

    // Phương thức nhập thông tin Manager
    void input() override {
        Employee::input();
        cout << "Nhập tiền thưởng: ";
        cin >> bonus;
        cout << "Nhập thâm niên (năm): ";
        cin >> seniority;
    }

    // Phương thức tính và trả về lương tổng của Manager
    double getSalary() const {
        return baseSalary + bonus;
    }

    // Phương thức hiển thị thông tin Manager
    void output() const override {
        Employee::output();
        cout << "Tiền thưởng: " << bonus << "\nThâm niên: " << seniority
             << "\nLương tổng: " << getSalary() << endl;
    }

    // Lấy thâm niên của Manager
    int getSeniority() const {
        return seniority;
    }

    // Lấy họ tên của Manager
    string getName() const {
        return name;
    }
};

// Hàm so sánh để sắp xếp theo lương giảm dần
bool compareBySalary(const Manager &a, const Manager &b) {
    return a.getSalary() > b.getSalary();
}

int main() {
    int n;
    cout << "Nhập số lượng Manager: ";
    cin >> n;

    vector<Manager> managers;

    // Nhập danh sách Manager
    for (int i = 0; i < n; ++i) {
        cout << "\nNhập thông tin Manager " << i + 1 << ":\n";
        Manager m;
        m.input();
        managers.push_back(m);
    }

//    // Hiển thị danh sách Manager theo chiều giảm dần về lương
//    sort(managers.begin(), managers.end(), compareBySalary);
//    cout << "\nDanh sách Manager theo chiều giảm dần về lương:\n";
//    for (const auto &m : managers) {
//        m.output();
//        cout << "---------------------------\n";
//    }
//
//    // Tìm và hiển thị Manager có thâm niên là một số nhập từ bàn phím
//    int searchSeniority;
//    cout << "\nNhập số thâm niên cần tìm: ";
//    cin >> searchSeniority;
//
//    bool found = false;
//    for (const auto &m : managers) {
//        if (m.getSeniority() == searchSeniority) {
//            cout << "\nManager có thâm niên " << searchSeniority << ":\n";
//            m.output();
//            cout << "---------------------------\n";
//            found = true;
//        }
//    }
//
//    if (!found) {
//        cout << "Không có Manager nào có thâm niên là " << searchSeniority << endl;
//    }

    return 0;
}
