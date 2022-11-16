#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef struct {
    int cost;
    int r;
    int c;   
}coor;

int d[125][125];
short map[125][125];
short mv1[4] = { 0, 0, -1, 1 };
short mv2[4] = { -1, 1, 0, 0 };

struct cmp {
    bool operator()(coor c1, coor c2) {
        if (c1.cost > c2.cost) return true;
        else return false;
    }
};

void dijkstra(int N) {
    priority_queue<coor, vector<coor>, cmp> pq;
    coor c1;
    c1.r = 0; c1.c = 0; c1.cost = map[0][0];

    d[0][0] = map[0][0];
    pq.push(c1);

    while (!pq.empty()) {
        int x = pq.top().c;
        int y = pq.top().r;
        int dist = pq.top().cost;
        pq.pop();

        if (x == N - 1 && y == N - 1) break;

        if (d[y][x] < dist) continue;

        for (int i = 0; i < 4; i++) {
            c1.c = x + mv1[i];
            c1.r = y + mv2[i];

            if ((0 <= c1.r && c1.r < N) && (0 <= c1.c && c1.c < N)) {
                c1.cost = dist + map[c1.r][c1.c];

                if (c1.cost < d[c1.r][c1.c]) {
                    d[c1.r][c1.c] = c1.cost;
                    pq.push(c1);
                }
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, n = 1;
    fill(&d[0][0], &d[124][125], 20000000);

    while (1) {
        

        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }

        dijkstra(N);

        int res = min(d[N - 1][N - 2], d[N - 2][N - 1]) + map[N - 1][N - 1];
        cout << "Problem " << n++ << ": " << res << "\n";
        memset(map, 0, sizeof(map));
        fill(&d[0][0], &d[N - 1][N], 20000000);
    }

    return 0;
}