// em co tham khao tren GEMINI 
#include <iostream>
#include <vector>
using namespace std;

void printPermutation(const vector<int>& perm) {
    for (int i = 0; i < perm.size(); ++i) {
        cout << perm[i] << (i < perm.size() - 1 ? " " : "\n") ;
    }
}

void generatePermutations(vector<int>& perm, vector<bool>& used, int n, int pos) {
    if (pos == n) {
        printPermutation(perm);
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            perm[pos] = i;
            used[i] = true;
            generatePermutations(perm, used, n, pos + 1);
            used[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> perm(n);
    vector<bool> used(n + 1, false);

    generatePermutations(perm, used, n, 0);

    return 0;
}
