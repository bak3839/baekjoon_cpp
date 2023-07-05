#include <iostream>
#include <vector>

using namespace std;

typedef pair<char, int> pci;

int N;
bool goal;
vector<bool> visit;
vector<pci> type;
vector<vector<int>> map;

void dfs(int x, int money) {
    visit[x] = true;
   
    if (type[x].first == 'L' && money < type[x].second) money = type[x].second;
    if (type[x].first == 'T') money -= type[x].second;

    if (money < 0) {
        visit[x] = false;
        return;
    }

    if (x == N) return;

    for (int i = 0; i < map[x].size(); i++) {
        int next = map[x][i];
        if (visit[next]) continue;

        dfs(next, money);
    }

    visit[x] = false;
}

void Solution() {
    dfs(1, 0);

    if (visit[N]) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    map.clear();
    type.clear();
    visit.clear();
}

void Input() {
    char t;
    int cost, room;

    goal = false;
    map.resize(N + 1);
    type.resize(N + 1);
    visit.resize(N + 1, false);
    

    for (int i = 1; i <= N; i++) {
        cin >> type[i].first >> type[i].second;

        while (1) {
            cin >> room;
            if (room == 0) break;

            map[i].push_back(room);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (1) {
        cin >> N;
        if (N == 0) break;

        Input();
        Solution();
    }

    return 0;
}