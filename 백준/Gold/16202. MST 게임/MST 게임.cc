#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

typedef struct {
    int v1, v2, cost;
}Edge;

int N, M, K;
vector<Edge> edge;
vector<bool> visited;
vector<int> parent, ans;

int GetRoot(int x) {
    if (x == parent[x]) return x;
    return parent[x] = GetRoot(parent[x]);
}

void Union(int a, int b) {
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    int v1, v2, a, b, cost;
    ans.resize(K, 0);
    parent.resize(N + 1);
    visited.resize(M, false);    

    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2;
        edge.push_back({ v1, v2, i + 1 });
    }

    for (int k = 0; k < K; k++) {
        int res = 0, edgeCnt = 0;

        for (int i = 1; i <= N; i++)
            parent[i] = i;

        for (int i = 0; i < edge.size(); i++) {
            if (visited[i]) continue;

            v1 = edge[i].v1;
            v2 = edge[i].v2;
            cost = edge[i].cost;

            a = GetRoot(v1);
            b = GetRoot(v2);

            if (a != b) {
                if (edgeCnt == 0) visited[i] = true;

                edgeCnt++;
                res += cost;
                Union(a, b);    
            }

            if (edgeCnt == N - 1) break;
        }

        if (edgeCnt != N - 1) break;

        ans[k] = res;
    }
    
    for (int n : ans)
        cout << n << " ";
    
    return 0;
}