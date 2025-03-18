#include <bits/stdc++.h>
#define prev aaa

using namespace std;

const int MAX = 200001;

int N, K, prev[MAX];
bool visited[MAX];
vector<int> v;

void bfs() {
    queue<int> q;
    q.push(N);
    visited[N] = true;

    while (q.size()) {
        int here = q.front();
        q.pop();

        if (here == K) {
            break;
        }

        for (int next : {here + 1, here - 1, here * 2}) {
            if (next < 0 || next >= MAX || visited[next]) continue;

            q.push(next);
            prev[next] = here;
            visited[next] = true;
        }
    }

    for (int i = K; i != N; i = prev[i]) {
        v.push_back(i);
    }
    v.push_back(N);

    reverse(v.begin(), v.end());

    cout << v.size() - 1 << "\n";
    for (int i : v)
        cout << i << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    bfs();

    return 0;
}
