#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class DoThi {
private:
    unordered_map<string, unordered_set<string>> danhSachKe;

public:
    void themDinh(string dinh) {
        if (danhSachKe.find(dinh) != danhSachKe.end()) {
            cout << "DUP" << endl;
        } else {
            danhSachKe[dinh] = unordered_set<string>();
            cout << "ADD" << endl;
        }
    }

    void themCanh(string batDau, string ketThuc) {
        if (danhSachKe.find(batDau) == danhSachKe.end()) {
            themDinh(batDau);
        }
        if (danhSachKe.find(ketThuc) == danhSachKe.end()) {
            themDinh(ketThuc);
        }

        if (danhSachKe[batDau].count(ketThuc) > 0) {
            cout << "DUP2" << endl;
        } else {
            danhSachKe[batDau].insert(ketThuc);
            cout << "ADD3" << endl;
        }
    }

    void laKe(string u, string v) {
        if (danhSachKe.find(u) == danhSachKe.end() || danhSachKe.find(v) == danhSachKe.end()) {
            cout << "FALSE" << endl;
        } else if (danhSachKe[u].count(v) > 0 || danhSachKe[v].count(u) > 0) {
            cout << "TRUE" << endl;
        } else {
            cout << "FALSE" << endl;
        }
    }

    void timDinhLanCan(string dinh) {
        if (danhSachKe.find(dinh) == danhSachKe.end()) {
            cout << 0 << endl;
        } else {
            cout << danhSachKe[dinh].size() << endl;
        }
    }
};

int main() {
    DoThi dothi;

    while (true) {
        int lenh;
        cin >> lenh;

        if (lenh == 0) {
            break;
        }

        if (lenh == 1) {
            string dinh;
            cin >> dinh;
            dothi.themDinh(dinh);
        } else if (lenh == 2) {
            string batDau, ketThuc;
            cin >> batDau >> ketThuc;
            dothi.themCanh(batDau, ketThuc);
        } else if (lenh == 3) {
            string u, v;
            cin >> u >> v;
            dothi.laKe(u, v);
        } else if (lenh == 4) {
            string dinh;
            cin >> dinh;
            dothi.timDinhLanCan(dinh);
        }
    }

    return 0;
}
