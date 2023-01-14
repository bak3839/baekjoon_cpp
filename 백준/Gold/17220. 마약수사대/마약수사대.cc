#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> graph;
bool visited[27];
bool origin[27];
int cnt[27];

int N, M, org;

void dfs(int x) {
    if (cnt[x] == 0) {
        visited[x] = true;

        if (origin[x]) --N;

        for (int i = 0; i < graph[x].size(); i++) {
            int nx = graph[x][i];
            if (!visited[nx]) {
                --cnt[nx];
                dfs(nx);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    
    cin >> N >> M;
    graph.resize(N + 1);

    char ch1, ch2;

    for (int i = 0; i < M; i++) {
        cin >> ch1 >> ch2;
        origin[ch2 - 64] = true;
        cnt[ch2 - 64]++;
        graph[ch1 - 64].push_back(ch2 - 64);
    }

    for (int i = 1; i <= N; i++) {
        if (!origin[i]) org++;
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; i++) {
        cin >> ch1;
        if (!visited[ch1 - 64]) {
            cnt[ch1 - 64] = 0;
            dfs(ch1 - 64);
        }
    }

    cout << N - org;
    return 0;
}