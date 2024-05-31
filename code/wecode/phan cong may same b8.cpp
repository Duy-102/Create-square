#include <iostream>
//em có tham khảo trên gemini
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    int soCongViec, soMay;
    cin >> soCongViec >> soMay;
    vector<int> thoiGian(soCongViec);
    for (int i = 0; i < soCongViec; ++i) {
        cin >> thoiGian[i];
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> hangDoiUuTien;
    for (int i = 0; i < soMay; ++i) {
        hangDoiUuTien.push({0, i});
    }

    vector<int> phanCong(soCongViec);
    for (int i = 0; i < soCongViec; ++i) {
        auto [tongThoiGian, may] = hangDoiUuTien.top();
        hangDoiUuTien.pop();
        phanCong[i] = may;
        hangDoiUuTien.push({tongThoiGian + thoiGian[i], may});
    }

    for (int i = 0; i < soCongViec; ++i) {
        cout << phanCong[i] << " ";
    }
    cout << endl;

    return 0;
}
