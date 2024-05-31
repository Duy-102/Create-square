#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

// Hàm heuristic để phân công công việc cho các máy
vector<int> phanCongCongViec(int n, int m, const vector<vector<int>>& thoiGian) {
    vector<int> phanCong(n, -1);  // Mảng kết quả: máy được phân công cho từng công việc
    vector<int> tongThoiGian(m, 0);  // Tổng thời gian công việc hiện tại của mỗi máy

    // Priority queue để lưu các máy với tổng thời gian công việc hiện tại, máy nào có tổng thời gian ít hơn sẽ đứng trước
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int may = 0; may < m; ++may) {
        pq.emplace(0, may);
    }

    for (int congViec = 0; congViec < n; ++congViec) {
        int thoiGianNganNhat = INT_MAX;
        int mayTotNhat = -1;
        for (int may = 0; may < m; ++may) {
            if (thoiGian[may][congViec] >= 0 && thoiGian[may][congViec] < thoiGianNganNhat) {
                thoiGianNganNhat = thoiGian[may][congViec];
                mayTotNhat = may;
            }
        }

        if (mayTotNhat != -1) {
            phanCong[congViec] = mayTotNhat;
            tongThoiGian[mayTotNhat] += thoiGian[mayTotNhat][congViec];
        }
    }

    return phanCong;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> thoiGian(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> thoiGian[i][j];
        }
    }

    vector<int> ketQua = phanCongCongViec(n, m, thoiGian);
    for (int i = 0; i < n; ++i) {
        cout << ketQua[i] << " ";
    }
    cout << endl;

    return 0;
}
