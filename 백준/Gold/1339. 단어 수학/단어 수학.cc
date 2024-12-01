#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;
using pci = pair<char, int>;

int N;
vector<char> num;
vector<string> word;

void ChangeToNumber() {
    int ans = 0;

    for (auto w : word) {
        for (int i = 0; i < w.size(); i++)
            w[i] = num[w[i] - 'A'];

        ans += stoi(w);
    }

    cout << ans;
}

void SeekNumber() {
    map<char, int> m;

    for (auto w : word) {
        int res = 1;

        for (int i = w.size() - 1; i >= 0; i--) {
            m[w[i]] += res;
            res *= 10;
        }
    }

    vector<pci> ans(m.begin(), m.end());
    sort(ans.begin(), ans.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    char n = '9';

    for (auto r : ans) {
        num[r.first - 'A'] = n--;
    }
}

void Solution() {
    SeekNumber();
    ChangeToNumber();
}

void Input() {
    cin >> N;

    word.resize(N);
    num.resize(26, '0');

    for (int i = 0; i < N; i++)
        cin >> word[i];
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