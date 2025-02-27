#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M, ans = 0;
vector<string> A;
int mv[8][2] = { {-2, 1}, {-2, -1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1} };

int move(int a, int b) {
    queue<pii> q;
    q.push({ a, b });
    A[a][b] = '*';

    while (q.size()) {
        int size = q.size();

        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nx = x + mv[i][0];
                int ny = y + mv[i][1];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M || A[nx][ny] == '*') continue;
                if (A[nx][ny] == 'H') return ans + 1;

                q.push({ nx, ny });
                A[nx][ny] = '*';
            }
        }

        ans++;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    cin >> M >> N;

    A.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];

        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] == 'K') {
                x = i; y = j;
            }
        }
    }
        
    cout << move(x, y);
    return 0;
}
