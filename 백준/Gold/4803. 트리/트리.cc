#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[501];
vector<bool> visit;
bool pass;

void Dfs(int x, int prev) {
    visit[x] = true;

    for (int i = 0;i < graph[x].size();i++) {
        int next = graph[x][i];
        if (!visit[next]) Dfs(next, x);
        else if (visit[next] && next != prev) pass = false;
    }
}

int Search(int N) {
    int cnt = 0;
    for (int i = 1;i <= N;i++) {
        pass = true;
        if (!visit[i]) {
            Dfs(i, 0);
            if (pass) cnt++;
        }
    }

    return cnt;
}

void Input(int N, int M) {
    int a, b;
    visit.resize(N + 1, false);

    for (int i = 0;i < M;i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void Clear(int N) {
    visit.clear();
    for (int i = 1;i <= N;i++) graph[i].clear();
}

void Print(int T, int cnt) {
    if (cnt == 0) cout << "Case " << T << ": No trees.\n";
    else if(cnt == 1) cout << "Case " << T << ": There is one tree.\n";
    else cout << "Case " << T << ": A forest of " << cnt << " trees.\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0, cnt;
    while (1) {
        int N, M;
        cin >> N >> M;
        if (!N && !M) break;

        Input(N, M);
        Print(++T, Search(N));
        Clear(N);
    }
    
    return 0;
}