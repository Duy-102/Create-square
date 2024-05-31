#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

void backtrack(const vector<int>& weights, double target, double current_score, vector<double>& current_weights, int index, vector<vector<double>>& result) {
    // Nếu đã điền đủ n cột điểm và trung bình môn học đạt được target
    if (index == weights.size() && abs(current_score - target) < 1e-9) {
        result.push_back(current_weights);
        return;
    }
    
    // Nếu đã điền đủ n cột điểm nhưng trung bình môn học không đạt được target
    if (index == weights.size()) {
        return;
    }
    
    // Thử tất cả các điểm có thể cho cột điểm hiện tại
    for (int i = 0; i <= 10; ++i) {
        current_weights[index] = i * 0.25;
        double new_score = current_score + i * weights[index] * 0.25;
        // Nếu điểm trung bình không vượt quá target thì tiếp tục thử
        if (new_score <= target) {
            backtrack(weights, target, new_score, current_weights, index + 1, result);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    
    double target;
    cin >> target;
    
    vector<vector<double>> result;
    vector<double> current_weights(n);
    
    // Gọi hàm backtracking để tìm tất cả các cách ghi điểm
    backtrack(weights, target, 0, current_weights, 0, result);
    
    // In ra kết quả
    for (const auto& r : result) {
        for (int i = 0; i < n; ++i) {
            cout << fixed << setprecision(2) << r[i];
            if (i < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
