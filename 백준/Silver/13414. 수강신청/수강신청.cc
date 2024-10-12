#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
using psi = pair<string, int>;

int K, L;

bool cmp(psi p1, psi p2) {
    return p1.second < p2.second;
}

void Solution() {
    string num;
    map<string, int> m;

    for(int i = 0; i < L; i++) {
        cin >> num;
        m[num] = i;
    }

    vector<psi> res(m.begin(), m.end());
    sort(res.begin(), res.end(), cmp);

    for(int i = 0; i < K; i++) {
        if(i >= res.size()) break;
        cout << res[i].first << "\n";
    }
}

void Input() {
    cin >> K >> L;   
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