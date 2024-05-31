//em có tham khoa tren wed 
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void quayLui(string& digits, int index, set<string>& permutations) {
    if (index == digits.size()) {
        permutations.insert(digits);
        return;
    }

    for (int i = index; i < digits.size(); ++i) {
        swap(digits[index], digits[i]);
        quayLui(digits, index + 1, permutations);
        swap(digits[index], digits[i]);  // quay lui
    }
}

int main() {
    string n;
    cin >> n;

    set<string> uniquePermutations;
    quayLui(n, 0, uniquePermutations);

    vector<string> sortedPermutations(uniquePermutations.begin(), uniquePermutations.end());
    sort(sortedPermutations.rbegin(), sortedPermutations.rend());

    for (const string& perm : sortedPermutations) {
        cout << perm << endl;
    }

    return 0;
}
