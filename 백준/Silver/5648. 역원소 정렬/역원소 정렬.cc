#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<long long> res;
vector<string> s;

void Solution() {
    for (int i = 0; i < N; i++) {
        string n = s[i];
        string ans = "";

        for (int j = n.size() - 1; j >= 0; j--) {
            if (ans.size() == 0 && n[j] == '0') continue;

            ans.push_back(n[j]);
        }

        res[i] = stoll(ans);
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < N; i++)
        cout << res[i] << "\n";
}

void Input() {
    cin >> N;

    s.resize(N);
    res.resize(N);

    for (int i = 0; i < N; i++)
        cin >> s[i];
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