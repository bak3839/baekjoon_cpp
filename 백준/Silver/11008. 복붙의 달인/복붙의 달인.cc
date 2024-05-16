#include <iostream>
#include <string>

using namespace std;

string s, p;

void Solution() {
    int ans = s.size(), index = 0;

    while (1) {
        if (s.find(p, index) == string::npos) break;

        index = s.find(p, index) + p.size();
        ans -= (p.size() - 1);
    }

    cout << ans << "\n";
}

void Input() {
    cin >> s >> p;
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}