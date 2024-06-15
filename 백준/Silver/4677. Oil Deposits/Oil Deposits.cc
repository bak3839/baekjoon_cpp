#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, M;
vector<string> map;
int mv[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void bfs(int r, int c) {
    queue<pii> q;
    q.push({r, c});
    map[r][c] = '*';

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 8; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == '*') continue;

            q.push({nx, ny});
            map[nx][ny] = '*';
        }
    }
}

void Solution(){
    int ans = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == '*') continue;

            bfs(i ,j);
            ans++; 
        }
    }

    cout << ans << "\n";
}

void Input() {
    map.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> map[i];
    }
}

void Solve() {
    while(1) {
        cin >> N >> M;

        if(N == 0 && M == 0) break;
    
        Input();
        Solution();
        map.clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}