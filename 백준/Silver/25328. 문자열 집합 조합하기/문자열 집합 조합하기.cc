#include <bits/stdc++.h>

using namespace std;

int k;
vector<string> ans;
map<string, int> m;

void Combiantion(int x, string s, string tmp) {
    if (tmp.size() == k) {
        m[tmp]++;
        return;
    }

    for (int i = x; i < s.size(); i++) {
        tmp.push_back(s[i]);
        Combiantion(i + 1, s, tmp);
        tmp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool pass = false;
    string s, sub;
    vector<string> str(3);

    for (int i = 0; i < 3; i++)
        cin >> str[i];
    cin >> k;

    for (int i = 0; i < 3; i++) {
        Combiantion(0, str[i], "");
    }

    for (auto p : m) {
        if (p.second > 1) {
            cout << p.first << "\n";
            pass = true;
        }
    }

    if (!pass) cout << -1;
    return 0;
}
