#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;
vector<int> A;

void Solution() {
    int n, ans = 0;
    map<int, int> m;

    for (int i = 0; i < N; i++) {
        cin >> n;

        while (n % 2 != 1) {
            n = n / 2;
        }

        m[n]++;
        ans = max(ans, m[n]);
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