#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;

void Solution() {
    map<string, int> m;
    string fruit, ans = "NO";
    int cnt;

    for (int i = 0; i < N; i++) {
        cin >> fruit >> cnt;
        m[fruit] += cnt;
    }

    for (auto res : m) {
        if (res.second == 5) {
            ans = "YES";
            break;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}