#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
using psi = pair<string, int>;

int N;
map<string, int> m;

bool cmp(psi p1, psi p2) {
    return p1.second > p2.second;
}

void Solution() {
    vector<psi> ans(m.begin(), m.end());
    sort(ans.begin(), ans.end(), cmp);

    cout << ans[0].second;
}

void Input() {
    string ans = "";
    vector<string> res(3);
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> res[j];
        }

        sort(res.begin(), res.end());

        for (auto s : res) {
            ans.append(s + " ");
        }

        m[ans]++;
        ans = "";
    }
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