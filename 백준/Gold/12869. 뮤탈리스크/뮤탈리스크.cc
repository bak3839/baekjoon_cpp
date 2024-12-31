#include <bits/stdc++.h>

using namespace std;

int N, ans = 100000001;
vector<int> scv(3, 0);
int visited[64][64][64];
int at[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9}
};

typedef struct {
    int a, b, c;
}A;

void bfs() {
    int a = scv[0], b = scv[1], c = scv[2];
    queue<A> q;
    q.push({ a, b, c });
    visited[a][b][c] = true;

    while (q.size()) {
        a = q.front().a;
        b = q.front().b;
        c = q.front().c;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int na = max(0, a - at[i][0]);
            int nb = max(0, b - at[i][1]);
            int nc = max(0, c - at[i][2]);

            if (visited[na][nb][nc]) continue;

            if (na == 0 && nb == 0 && nc == 0) {
                ans = visited[a][b][c];
                return;
            }
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({ na, nb, nc });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> scv[i];
   
    bfs();


    cout << ans;
    return 0;
}