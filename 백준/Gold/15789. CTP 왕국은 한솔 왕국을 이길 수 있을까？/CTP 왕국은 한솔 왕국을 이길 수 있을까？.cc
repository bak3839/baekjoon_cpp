#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N, M, C, H, K;
vector<int> parent;
vector<pii> cnt;
vector<pii> team;

int getRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
}

void Union(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);

    if (a == b) return;

    if (b == C || b == H) parent[a] = b;
    else if(a == C || a == H) parent[b] = a;
    else if(a > b) parent[a] = b;
    else parent[b] = a;
}

void Solution() {
    for (int i = 0; i < M; i++) 
        Union(team[i].first, team[i].second);

    for (int i = 1; i <= N; i++) {
        int root = getRoot(i);
        cnt[root].first++;
    }

    int idx = 0, ans = cnt[C].first;

    sort(cnt.begin(), cnt.end(), greater<pii>());   

    while (K--) {
        if (idx >= N || cnt[idx].first == 0) break;

        if (cnt[idx].second == H || cnt[idx].second == C) {
            K++; idx++;
            continue;
        }

        ans += cnt[idx++].first;
    }

    cout << ans;
}

void Input() {
    int a, b;
    cin >> N >> M;

    parent.resize(N + 1);
    cnt.resize(N + 1);
    team.resize(M);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        cnt[i] = { 0, i };
    }
    cnt[0] = { -1, 0 };

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        team[i] = { a, b };
    }

    cin >> C >> H >> K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}