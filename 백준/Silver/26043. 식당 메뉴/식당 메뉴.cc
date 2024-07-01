#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int N;
vector<bool> done;

void Solution() {
    int S, a, b;
    queue<pii> q;

    vector<vector<int>> list(3);

    for (int i = 0; i < N; i++) {
        cin >> S;

        if (S == 1) {
            cin >> a >> b;
            q.push({ a, b });
            done[a] = true;
        }
        else {
            a = q.front().first;
            cin >> b;

            if (q.front().second == b) list[0].push_back(a);
            else list[1].push_back(a);

            done[a] = false;
            q.pop();
        }
    }

    for (int i = 1; i <= N; i++) {
        if (done[i]) list[2].push_back(i);
    }

    
    for (int i = 0; i < 3; i++) {
        sort(list[i].begin(), list[i].end());

        if (list[i].empty()) cout << "None\n";
        else {
            for (int j = 0; j < list[i].size(); j++)
                cout << list[i][j] << " ";
            cout << "\n";
        }
    }
}

void Input() {
    cin >> N;

    done.resize(N + 1, false);
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