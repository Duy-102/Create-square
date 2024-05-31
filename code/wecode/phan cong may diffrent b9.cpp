//em co tham khao tre mang ạ
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Cấu trúc để lưu thông tin công việc của mỗi máy
struct CongViec {
    int tongThoiGian; // Tổng thời gian các công việc mà máy đã thực hiện
    int may;          // Chỉ số của máy
    bool operator<(const CongViec& cv) const {
        return tongThoiGian > cv.tongThoiGian; // Min-heap dựa trên tổng thời gian
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    // Ma trận thời gian thực hiện công việc của mỗi máy
    vector<vector<int>> thoiGian(m, vector<int>(n));
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            cin >> thoiGian[j][i];
        }
    }

    // Hàng đợi ưu tiên để lưu máy dựa trên tổng thời gian hiện tại
    priority_queue<CongViec> hangDoiUuTien;
    for (int j = 0; j < m; ++j) {
        hangDoiUuTien.push({0, j});
    }

    // Mảng kết quả lưu máy được phân công cho từng công việc
    vector<int> phanCong(n);

    // Phân công từng công việc
    for (int i = 0; i < n; ++i) {
        CongViec cv = hangDoiUuTien.top();
        hangDoiUuTien.pop();
        phanCong[i] = cv.may; // Gán công việc i cho máy này
        cv.tongThoiGian += thoiGian[cv.may][i]; // Cập nhật tổng thời gian của máy
        hangDoiUuTien.push(cv); // Đưa máy trở lại hàng đợi với tổng thời gian mới
    }

    // Xuất kết quả
    for (int i = 0; i < n; ++i) {
        cout << phanCong[i] << " ";
    }
    cout << endl;

    return 0;
}
