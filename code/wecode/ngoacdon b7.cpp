//em co tham khao tren mangg a
#include <iostream>
#include <vector>
using namespace std;

void quayLui(int mo, int dong, int n, string chuoi, vector<string> &ketQua) {
    if (chuoi.length() == 2 * n) {
        ketQua.push_back(chuoi);
        return;
    }
    if (mo < n) quayLui(mo + 1, dong, n, chuoi + "(", ketQua);
    if (dong < mo) quayLui(mo, dong + 1, n, chuoi + ")", ketQua);
}

vector<string> phatSinhNgoacDon(int n) {
    vector<string> ketQua;
    quayLui(0, 0, n, "", ketQua);
    return ketQua;
}

int main() {
    int n;
    cin >> n;
    vector<string> ketQua = phatSinhNgoacDon(n);
    for (const string &chuoi : ketQua) cout << chuoi << endl;
    return 0;
}
