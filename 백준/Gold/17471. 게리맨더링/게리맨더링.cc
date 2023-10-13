#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, sum, ans = 1000000001;

vector<int> people;
vector<bool> visit;
vector<bool> choice;
vector<vector<int>> graph;

bool check(int x, int total) {
    queue<int> q;
    q.push(x);
    visit[x] = true;

    int cnt = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if (visit[next]) continue;

            visit[next] = true;
            q.push(next);
            cnt++;
        }
    }

    if (cnt + total == N) return true;
    return false;
}

void bfs(int x, int total, int sub) {
    queue<int> q;
    q.push(x);
    visit[x] = true;

    int cnt = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if (visit[next] || !choice[next]) continue;

            visit[next] = true;
            q.push(next);
            cnt++;
        }
    }

    if (cnt == total) {
        bool pass = false;

        for (int i = 1; i <= N; i++) {
            if (!choice[i]) {
                pass = check(i, total);
                break;
            }
        }

        if(pass) ans = min(ans, abs(sum - (2 * sub)));
    }
    fill(visit.begin(), visit.end(), false);
}

void Search(int cnt, int target, int x, int sub) {
    if (cnt == target) {
        bfs(x, target, sub);
        return;
    }

    for (int i = x; i <= N; i++) {
        if (choice[i]) continue;

        choice[i] = true;
        Search(cnt + 1, target, i, sub + people[i]);
        choice[i] = false;
    }
}

void Solution() {
    for (int i = 1; i <= N / 2 + N % 2; i++) {
        Search(0, i, 1, 0);
        fill(choice.begin(), choice.end(), false);
    }

    if (ans != 1000000001) cout << ans;
    else cout << -1;
}

void Input() {
    cin >> N;

    graph.resize(N + 1);
    people.resize(N + 1);
    visit.resize(N + 1, false);
    choice.resize(N + 1, false);        

    for (int i = 1; i <= N; i++) {
        cin >> people[i];
        sum += people[i];
    }       

    for (int i = 1; i <= N; i++) {
        int node, n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> node;
            graph[i].push_back(node);
            graph[node].push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
