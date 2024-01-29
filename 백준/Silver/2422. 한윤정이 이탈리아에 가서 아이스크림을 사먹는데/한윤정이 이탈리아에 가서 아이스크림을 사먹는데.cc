#include <iostream>
#include <vector>

using namespace std;

int N, M, ans;
vector<int> num;
vector<vector<bool>> imp;

bool CheckCombination() {
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (imp[num[i]][num[j]]) return false;
        }
    }

    return true;
}

void Search(int x) {
    if (num.size() == 3) {
        if (CheckCombination()) ans++;
        return;
    }

    for (int i = x; i <= N; i++) {
        num.push_back(i);
        Search(i + 1);
        num.pop_back();
    }
}

void Solution() {
    Search(1);
    cout << ans;
}

void Input() {
    int a, b;
    cin >> N >> M;

    imp.resize(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        imp[a][b] = true;
        imp[b][a] = true;
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
