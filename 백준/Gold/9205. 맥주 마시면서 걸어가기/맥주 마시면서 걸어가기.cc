#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

vector<pii> coor;
bool visit[103];
vector<int> graph[103];

bool dist(pii p1, pii p2) {
    int diff_x = abs(p1.first - p2.first);
    int diff_y = abs(p1.second - p2.second);

    if (diff_x + diff_y <= 1000) return true;
    return false;
}

void dfs(int x) {
    visit[x] = true;

    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visit[y]) {
            dfs(y);
        }
    }
}

void Connect(int n) {
    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) { 
            if (dist(coor[i], coor[j])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
}

void Input(int n) {
    int x, y;

    for (int i = 0; i < n + 2; i++) {
        cin >> x >> y;
        coor.push_back({ x, y });
    }
}

void clear(int n) {
    coor.clear();
    for (int i = 0; i < n + 2; i++) graph[i].clear();
    memset(visit, false, sizeof(visit));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, n;
    cin >> T;

    while (T--) {
        cin >> n;
        Input(n);
        Connect(n);
        dfs(0);
        if (visit[n + 1]) cout << "happy\n";
        else cout << "sad\n";
        clear(n);
    }

    return 0;
}