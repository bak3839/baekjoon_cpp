#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, ans;
vector<int> row;

bool Check(int n) {
    for (int i = 0; i < n; i++) {
        if (row[i] == row[n] || n - i == abs(row[i] - row[n])) return false;
    }

    return true;
}

void Search(int x) {
    if (x == N) {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        row[x] = i;

        if (Check(x)) Search(x + 1);
    }
}

void Solution() {
    Search(0);
    cout << ans;
}

void Input() {
    cin >> N;

    row.resize(N, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}