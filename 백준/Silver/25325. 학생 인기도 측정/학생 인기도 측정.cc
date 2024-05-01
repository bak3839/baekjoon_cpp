#include <iostream>
#include <vector>
#include <map>
#include <sstream>
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
    string str, name;
    
    for (int i = 0; i < N; i++) {
        getline(cin, str);
        stringstream ss(str);

        while (ss >> name) {
            m[name]++;
        }
    }

    vector<psi> res(m.begin(), m.end());
    sort(res.begin(), res.end(), cmp);

    for (int i = 0; i < N; i++)
        cout << res[i].first << " " << res[i].second << "\n";
}

void Input() {
    string name;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> name;
        m[name] = 0;
    }
    cin.ignore();
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