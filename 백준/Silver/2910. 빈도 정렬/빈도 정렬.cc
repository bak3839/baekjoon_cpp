#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using pii = pair<int, int>;

int N, C;

bool cmp(pair<int, pii> p1, pair<int, pii> p2) {
    if (p1.second.first == p2.second.first) return p1.second.second < p2.second.second;

    return p1.second.first > p2.second.first;
}

void Solution() {
    int n;
    map<int, pii> m;
    
    for (int i = 0; i < N; i++) {
        cin >> n;

        if (m.find(n) != m.end()) m[n].first++;
        else m[n] = { 1, i };
    }

    vector<pair<int, pii>> res(m.begin(), m.end());
    sort(res.begin(), res.end(), cmp);

    for (int i = 0; i < res.size(); i++) {
        int cnt = res[i].second.first;

        for (int j = 0; j < cnt; j++)
            cout << res[i].first << " ";
    }
}

void Input() {
    cin >> N >> C;
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