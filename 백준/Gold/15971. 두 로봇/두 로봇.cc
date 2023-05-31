#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int N, s, e;
vector<vector<pii>> map;
vector<int> visit;
vector<int> ans;
bool flag;

void dfs(int x) {
    visit[x] = true;

    if (x == e) {
        ans.push_back(x);
        flag = true;
        return;
    }

    for (int i = 0; i < map[x].size(); i++) {
        int next = map[x][i].first;

        if (!visit[next]) dfs(next);

        if (flag) {
            ans.push_back(x);
            return;
        }
    }
}

void Solution() {
    dfs(s);

    int sum = 0, max_cost = 0;

    for (int i = 0; i < ans.size() - 1; i++) {
        int now = ans[i];
        int next = ans[i + 1];

        for (int j = 0; j < map[now].size(); j++) {
            int v = map[now][j].first;

            if (v == next) {
                sum += map[now][j].second;
                max_cost = max(map[now][j].second, max_cost);
                break;
            }
        }
    }

    cout << sum - max_cost;
}

void Input() {
    int v1, v2, cost;
    cin >> N >> s >> e;
    
    map.resize(N + 1);
    visit.resize(N + 1, false);

    for (int i = 0; i < N - 1; i++) {
        cin >> v1 >> v2 >> cost;
        
        map[v1].push_back({ v2, cost });
        map[v2].push_back({ v1, cost });
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}