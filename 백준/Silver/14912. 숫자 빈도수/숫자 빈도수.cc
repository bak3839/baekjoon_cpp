#include <iostream>
#include <string>

using namespace std;

int n, d;

void Solution() {
    int ans = 0;
    char ch = d + '0';

    for (int i = 1; i <= n; i++) {
        string s = to_string(i);

        for (int j = 0; j < s.size(); j++)
            if (s[j] == ch) ans++;
    }

    cout << ans;
}

void Input() {
    cin >> n >> d;
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
