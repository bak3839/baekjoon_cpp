#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;
map<string, vector<string>> m;

void Solution() {
    int count = 0;
    string p, s;
    vector<pair<string, string>> ans;

    for (int i = 0; i < N; i++) {
        cin >> p >> s;

        if (s == "-") continue;

        m[s].push_back(p);
    }

    for (auto res : m) {
        if (res.second.size() != 2) continue;

        count++;
        ans.push_back({ res.second[0], res.second[1] });
    }

    cout << count << "\n";

    for (auto name : ans) {
        cout << name.first << " " << name.second << "\n";
    }
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