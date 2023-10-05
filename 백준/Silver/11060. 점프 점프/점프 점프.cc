#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, ans = -1;
vector<int> map;
vector<bool> visit;

void bfs() {
    queue<pii> q;
    q.push({0, 0});
    visit[0] = true;

    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (now == N - 1) {
            ans = cnt;
            break;
        }

        for (int i = 1; i <= map[now]; i++) {
            int next = now + i;

            if (next >= N) break;
            if (visit[next]) continue;

            q.push({ next, cnt + 1 });
            visit[next] = true;
        }
    }
}

void Solution() {
    bfs();
    cout << ans;
}

void Input() {
    cin >> N;

    map.resize(N);
    visit.resize(N, false);

    for (int i = 0; i < N; i++)
        cin >> map[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
