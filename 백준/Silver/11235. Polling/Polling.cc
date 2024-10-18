#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using psi = pair<string, int>;

int N;
map<string, int> m;

bool cmp(psi p1, psi p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}

void Solution() {
    vector<psi> res(m.begin(), m.end());
    sort(res.begin(), res.end(), cmp);

    cout << res[0].first << "\n";

    for (int i = 1; i < N; i++) {
        if (res[i].second < res[0].second) break;

        cout << res[i].first << "\n";
    }
}

void Input() {
    string name;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> name;
        m[name]++;
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