#include <bits/stdc++.h>
#define prev aaa

using namespace std;

const int MAX = 500000;

int N, K;
bool visited[2][MAX + 1];

void bfs() {
    int time = 1, bro, size, here;
    queue<int> q;
    q.push(N);
    visited[0][N] = true;

    while (q.size()) {
        bro = K + (time * (time + 1)) / 2;

        if (bro > MAX) break;

        if (visited[time % 2][bro]) {
            cout << time;
            return;
        }

        size = q.size();

        while (size--) {
            here = q.front();
            q.pop();

            for (int next : {here + 1, here - 1, here * 2}) {
                if (next < 0 || next > MAX || visited[time % 2][next]) continue;

                if (next == bro) {
                    cout << time;
                    return;
                }

                q.push(next);
                visited[time % 2][next] = true;
            }
        }

        time++;
    }

    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    if (N == K) cout << 0;
    else bfs();

    return 0;
}
