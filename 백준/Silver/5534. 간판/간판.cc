#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
string target;
vector<string> sign;

void Solution() {
    int ans = 0, len = target.size();

    for (int i = 0; i < N; i++) {
        bool pass = false;
        string s = sign[i];

        if (s.size() < len) continue;

        for (int x = 0; x < s.size(); x++) {
            
            for (int j = 0; j < s.size(); j++) {
                int tIndex = 0, sIndex = j;

                while (tIndex < len) {
                    if (sIndex >= s.size() || target[tIndex] != s[sIndex]) break;

                    tIndex++; sIndex += x + 1;
                }

                if (tIndex == len) {
                    ans++;
                    pass = true;
                    break;
                }
            }

            if (pass) break;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> target;

    sign.resize(N);

    for (int i = 0; i < N; i++)
        cin >> sign[i];
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