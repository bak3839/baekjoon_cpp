#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, T, G;
vector<bool> check(100000, false);

void Solution() {
    if (N == G) {
        cout << 0;
        return;
    }

    bool finish = false;
    int cnt = 0;
    queue<int> q;
    q.push(N);

    check[N] = true;

    while (!q.empty()) {
        int size = q.size();

        if (cnt == T) break;

        for (int i = 0; i < size; i++) {
            int num = q.front();
            q.pop();

            if (num + 1 <= 99999 && !check[num + 1]) {
                if (num + 1 == G) {
                    finish = true;
                    break;
                }

                q.push(num + 1);
                check[num + 1] = true;
            }

            if (num * 2 <= 99999 && num != 0) {
                string snum = to_string(num * 2);
                snum[0] = snum[0] - 1;

                if (snum[0] == '0') snum.substr(1);

                int next = stoi(snum);

                if (check[next]) continue;

                if (next == G) {
                    finish = true;
                    break;
                }

                q.push(next);
                check[next] = true;
            }
        }

        cnt++;
        if (finish) break;
    }

    if (finish) cout << cnt;
    else cout << "ANG";
}

void Input() {
    cin >> N >> T >> G;
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
