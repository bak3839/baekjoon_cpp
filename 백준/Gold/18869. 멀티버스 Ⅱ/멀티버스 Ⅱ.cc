#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int size[10001];
vector<string> ans;
vector<vector<int>> cpy;
vector<vector<int>> universe;

int search(int M) {
    int cnt = 0;

    for (int i = 0; i < M; i++) {
        string now = ans[i];
        for (int j = i + 1; j < M; j++) {
            if (now == ans[j]) cnt++;
        }
    }

    return cnt;
}

void solve(int N, int M) {
    int index;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            index = lower_bound(universe[i].begin(), universe[i].end(), cpy[i][j]) - universe[i].begin();
            ans[i].push_back(index + 48);
        }
    }
}

void input(int N, int M) {
    ans.resize(M, "");
    cpy.resize(M, vector<int>(N));
    universe.resize(M, vector<int>(N));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> universe[i][j];
            cpy[i][j] = universe[i][j];
        }
        sort(universe[i].begin(), universe[i].end());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
     
    int N, M; // N: 행성수  M: 우주의 개수
    cin >> M >> N;

    input(N, M);
    solve(N, M);
    cout << search(M);
    return 0;
}