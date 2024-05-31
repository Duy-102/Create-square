//em co tham khao trên wed ạ
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Kiểm tra nếu phân đoạn của địa chỉ IP là hợp lệ
bool laPhanDoanHopLe(const string &phanDoan) {
    if (phanDoan.length() > 3 || phanDoan.empty()) {
        return false;
    }
    // Loại bỏ các phân đoạn bắt đầu bằng '0' nhưng không phải là '0' duy nhất
    if (phanDoan[0] == '0' && phanDoan.length() > 1) {
        return false;
    }
    // Chuyển chuỗi sang số và kiểm tra giá trị trong khoảng 0-255
    int so = stoi(phanDoan);
    if (so > 255) {
        return false;
    }
    return true;
}

// Hàm backtracking chính để tìm địa chỉ IP
void timDiaChiIP(const string &s, int batDau, vector<string> &diaChiHienTai, vector<string> &tatCaDiaChi) {
    if (diaChiHienTai.size() == 4) {
        if (batDau == s.length()) {
            tatCaDiaChi.push_back(diaChiHienTai[0] + "." + diaChiHienTai[1] + "." + diaChiHienTai[2] + "." + diaChiHienTai[3]);
        }
        return;
    }

    for (int doDai = 1; doDai <= 3 && batDau + doDai <= s.length(); ++doDai) {
        string phanDoan = s.substr(batDau, doDai);
        if (laPhanDoanHopLe(phanDoan)) {
            diaChiHienTai.push_back(phanDoan);
            timDiaChiIP(s, batDau + doDai, diaChiHienTai, tatCaDiaChi);
            diaChiHienTai.pop_back();
        }
    }
}

// Hàm khởi động quá trình backtracking
vector<string> khoiPhucDiaChiIP(string s) {
    vector<string> tatCaDiaChi;
    vector<string> diaChiHienTai;
    timDiaChiIP(s, 0, diaChiHienTai, tatCaDiaChi);
    return tatCaDiaChi;
}

int main() {
    string s;
    cout << "Nhập dãy số của bạn: ";
    cin >> s;
    vector<string> diaChiIPs = khoiPhucDiaChiIP(s);
    for (const string &ip : diaChiIPs) {
        cout << ip << endl;
    }
    return 0;
}
