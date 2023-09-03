#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> dist;
vector<bool> visit;

void Solution() {
    int start, ans = 1;
    cin >> start;

    queue<int> q;
    q.push(start);
    visit[start] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now + dist[now] <= N && !visit[now + dist[now]]) {
            visit[now + dist[now]] = true;
            q.push(now + dist[now]);
            ans++;
        }

        if (now - dist[now] > 0 && !visit[now - dist[now]]) {
            visit[now - dist[now]] = true;
            q.push(now - dist[now]);
            ans++;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N;
    dist.resize(N + 1);
    visit.resize(N + 1, false);

    for (int i = 1; i <= N; i++) 
        cin >> dist[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
