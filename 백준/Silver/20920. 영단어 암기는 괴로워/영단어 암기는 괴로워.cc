#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
using psi = pair<string, int>;

int N, M;

bool cmp(psi p1, psi p2) {
    if (p1.second > p2.second) return true;
    else if (p1.second < p2.second) return false;


    if (p1.first.size() > p2.first.size()) return true;
    else if (p1.first.size() < p2.first.size()) return false;

    return p1.first < p2.first;
}

void Solution() {
    map<string, int> m;
    string s;

    for (int i = 0; i < N; i++) {
        cin >> s;

        if (s.size() < M) continue;

        m[s]++;
    }

    vector<psi> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
        cout << v[i].first << "\n";
}

void Input() {
    cin >> N >> M;
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
