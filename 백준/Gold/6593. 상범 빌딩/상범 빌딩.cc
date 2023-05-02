#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
    int l;
    int r;
    int c;
    int cnt;
}Coor;

Coor s;
char map[31][31][31];
bool visit[31][31][31];

int mv[6][3] = { {1,0,0}, {-1,0,0}, {0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };

void Solution(int L, int R, int C) {
    int ans = -1;
    queue<Coor> q;
    q.push(s);
    visit[s.l][s.r][s.c] = true;

    while (!q.empty()) {
        int l = q.front().l;
        int r = q.front().r;
        int c = q.front().c;
        int cnt = q.front().cnt;
        q.pop();

        if (map[l][r][c] == 'E') {
            ans = cnt;
            break;
        }

        for (int i = 0; i < 6; i++) {
            Coor next;
            next.l = l + mv[i][0];
            next.r = r + mv[i][1];
            next.c = c + mv[i][2];
            next.cnt = cnt + 1;
            
            if (0 > next.l || next.l >= L || 0 > next.r || next.r >= R || 0 > next.c || next.c >= C) continue;
            if (visit[next.l][next.r][next.c] || map[next.l][next.r][next.c] == '#') continue;
            
            q.push(next);
            visit[next.l][next.r][next.c] = true;
        }
    }

    if (ans > 0) cout << "Escaped in " << ans << " minute(s).\n";
    else cout << "Trapped!\n";
}

void Input(int L, int R, int C) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                cin >> map[i][j][k];
                if (map[i][j][k] == 'S') {
                    s.l = i; s.r = j; s.c = k; s.cnt = 0;
                }
            }             
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (1) {
        int L, R, C;
        cin >> L >> R >> C;
        if (!L && !R && !C) break;

        Input(L, R, C);
        Solution(L, R, C);
        fill(&visit[0][0][0], &visit[30][30][31], false);
    }

    return 0;
}