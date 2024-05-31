#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grades(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grades[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        int count = 0;
        vector<int> column_indices;
        for (int j = 0; j < n; ++j) {
            if (grades[i][j] == 1) {
                column_indices.push_back(j + 1);
                count++;
            }
        }
        if (count > 0) {
            cout << (i + 1) << " -> ";
            for (int index : column_indices) {
                cout << index << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
