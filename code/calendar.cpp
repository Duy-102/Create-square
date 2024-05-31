#include <iostream>
using namespace std;

// Hàm kiểm tra năm nhuận
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
// Hàm in lịch cho một tháng
void printMonth(int month, int year) {
    cout << "Thang " << month << ", " << year << endl;
    cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;

    // Số ngày trong mỗi tháng
    int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Tính ngày bắt đầu của tháng
    int startDay = (year * 365 + year / 4 - year / 100 + year / 400) % 7;
    for (int i = 0; i < startDay; ++i) {
        cout << "    ";
    }

    for (int day = 1; day <= daysInMonth[month - 1]; ++day) {
        cout << (day < 10 ? " " : "") << day << " ";
        if ((startDay + day) % 7 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    int month, year;
    cout << "Nhap thang (1-12): ";
    cin >> month;
    cout << "Nhap nam: ";
    cin >> year;

    printMonth(month, year);

    return 0;
}
