#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

priority_queue<int, vector<int>, greater<int>> pq;
vector<vector<int>> seq;
vector<int> cnt;

void Solution() {
    while (!pq.empty()) {
        int now = pq.top();
        pq.pop();

        cout << now << " ";

        for (int i = 0; i < seq[now].size(); i++) {
            int next = seq[now][i];
            if (--cnt[next] == 0) pq.push(next);
        }
    }
}

void Input() {
    cin >> N >> M;
    seq.resize(N + 1);
    cnt.resize(N + 1);

    int v1, v2;
    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2;
        seq[v1].push_back(v2);
        cnt[v2]++;
    }

    for (int i = 1; i <= N; i++) {
        if (cnt[i] == 0) pq.push(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}