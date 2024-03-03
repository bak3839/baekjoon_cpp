#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> sub;

void Solution() {
    int p, t;

    
    for (int i = 0; i < M; i++) {
        vector<bool> time(51, false);
        int ans = 0;
        cin >> p;

        for (int j = 0; j < p; j++) {
            cin >> t;
            time[t] = true;
        }

        for (int j = 0; j < N; j++) {
            bool pass = true;

            for (int k = 0; k < sub[j].size(); k++) {
                if (!time[sub[j][k]]) {
                    pass = false;
                    break;
                }
            }

            if (pass) ans++;
        }

        cout << ans << "\n";
    }
}

void Input() {
    int cnt, t;
    cin >> N;

    sub.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> cnt;

        for (int j = 0; j < cnt; j++) {
            cin >> t;
            sub[i].push_back(t);
        }
    }

    cin >> M;
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
