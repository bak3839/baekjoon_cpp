#include <iostream>
#include <vector>

using namespace std;

int ans, N, K;
vector<string> word;
vector<bool> learn;

void Search(int x, int cnt) {
    if (cnt == 0) {
        int res = 0;

        for (auto s : word) {
            res++;

            for (int i = 0; i < s.size(); i++) {
                if (!learn[s[i] - 'a']) {
                    res--;
                    break;
                }
            }
        }

        ans = max(ans, res);
        return;
    }

    for (int i = x; i < 26; i++) {
        if (learn[i]) continue;

        learn[i] = true;
        Search(i + 1, cnt - 1);
        learn[i] = false;
    }
}

void Solution() {
    if (K < 5) {
        cout << 0;
        return;
    }

    Search(0, K - 5);
    cout << ans;
}

void Input() {
    string s, w = "antic";
    learn.resize(26, false);
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> s;
        word.push_back(s.substr(4, s.size() - 8));
    }

    for (int i = 0; i < 5; i++) 
        learn[w[i] - 'a'] = true;
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
