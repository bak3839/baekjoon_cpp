#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K, ans = 100001;
int mv[2] = { -1, 1 };
vector<int> pre(100005, -1);

void solve(int n) {
    if (n != N) {
        solve(pre[n]);
    }
    cout << n << " ";
}

void search() {
    queue<pair<int, int>> q;
    q.push({ N, 0 });

    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (now == K) {
            ans = cnt;
            break;
        }

        if (now > 100001 || now < 0) continue;

        for (int i = 0; i < 3; i++) {
            int next;
            if (i == 0) {
                if (now == 0) continue;
                next = now * 2;
            }
            else next = now + mv[i - 1];

            if (0 <= next && next < 100005) {
                if (pre[next] == -1) {
                    pre[next] = now;
                    q.push({ next, cnt + 1 });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    pre[N] = -1;

    if (N > K) {
        cout << N - K << "\n";
        for (int i = N; i >= K; i--) cout << i << " ";
    }

    else {
        search();
        cout << ans << "\n";
        solve(K);
    }

    return 0;
}