#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<string> word;

bool cmp(string s1, string s2) {
    if (s1.size() == s2.size()) return s1 < s2;

    return s1.size() < s2.size();
}

void Solution() {
    vector<string> ans;

    for (string s : word) {
        string num = "";

        for (char ch : s) {
            if (ch < '0' || ch > '9') {
                if (!num.empty()) {
                    while (num.size() > 1 && num[0] == '0') {
                        num.erase(0, 1);
                    }

                    ans.push_back(num);
                }
                num = "";
                continue;
            }

            num.push_back(ch);
        }

        if (!num.empty()) {
            while (num.size() > 1 && num[0] == '0') {
                num.erase(0, 1);
            }

            ans.push_back(num);
        }
    }

    sort(ans.begin(), ans.end(), cmp);

    for (string res : ans)
        cout << res << "\n";
}

void Input() {
    cin >> N;

    word.resize(N);

    for (int i = 0; i < N; i++)
        cin >> word[i];
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