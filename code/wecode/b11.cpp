//bai này em copy trên copilot ạ
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Cấu trúc để đại diện một máy
struct May {
    int thoi_gian; // Thời gian hiện tại của máy
    int id; // Số thứ tự của máy
};

// Hàm so sánh cho hàng đợi ưu tiên (min-heap)
struct so_sanh {
    bool operator()(const May& a, const May& b) {
        return a.thoi_gian > b.thoi_gian;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> thoi_gian_cong_viec(n);
    for (int i = 0; i < n; ++i) {
        cin >> thoi_gian_cong_viec[i];
    }

    // Hàng đợi ưu tiên để quản lý các máy, sử dụng min-heap
    priority_queue<May, vector<May>, so_sanh> hang_doi;

    // Khởi tạo các máy với thời gian ban đầu là 0
    for (int i = 0; i < m; ++i) {
        hang_doi.push({0, i});
    }

    vector<int> phan_cong(n);

    // Phân công từng công việc
    for (int i = 0; i < n; ++i) {
        // Lấy máy có thời gian hoàn thành hiện tại nhỏ nhất
        May may = hang_doi.top();
        hang_doi.pop();

        // Gán công việc cho máy đó
        phan_cong[i] = may.id;

        // Cập nhật thời gian hoàn thành của máy đó
        may.thoi_gian += thoi_gian_cong_viec[i];

        // Đưa máy trở lại hàng đợi
        hang_doi.push(may);
    }

    // In kết quả phân công
    for (int i = 0; i < n; ++i) {
        cout << phan_cong[i] << " ";
    }

    return 0;
}
