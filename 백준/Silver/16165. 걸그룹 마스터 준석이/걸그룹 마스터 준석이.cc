#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<string, vector<string>> group;
map<string, string> name;
int N, M;

void Solution() {
    int n;
    string s;

    for (auto& v : group) {
        sort(v.second.begin(), v.second.end());
    }

    for (int i = 0; i < M; i++) {
        cin >> s >> n;

        if (n == 0) {
            for (int i = 0; i < group[s].size(); i++)
                cout << group[s][i] << "\n";
        }

        else {
            cout << name[s] << "\n";
        }
    }
}

void Input() {
    cin >> N >> M;

    int n;
    string s, str;

    for (int i = 0; i < N; i++) {
        cin >> s >> n;

        for (int j = 0; j < n; j++) {
            cin >> str;

            group[s].push_back(str);
            name[str] = s;
        }
    }
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
