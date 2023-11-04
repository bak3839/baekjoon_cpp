#include <iostream>
#include <vector>
#include <string>

using namespace std;

int ans = 999999, N;
string X;
vector<bool> check;

void Search(string num) {
    if (num.size() == X.size()) {
        int res = stoi(num);

        if (res > N) ans = min(ans, res);
        return;
    }

    for (int i = 0; i < X.size(); i++) {
        if (check[i]) continue;
        if (num.size() == 0 && X[i] == '0') continue;

        check[i] = true;
        Search(num + X[i]);
        check[i] = false;
    }
}

void Solution() {
    Search("");

    if (ans == 999999) cout << 0;
    else cout << ans;
}

void Input() {
    cin >> X;

    N = stoi(X);
    check.resize(X.size(), false);
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
