#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N;
int mv[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int point[5] = { 0, 1, 10, 100, 1000 };

typedef struct {
    int x;
    int y;
    int like;
    int empty;   
}Status;

vector<vector<int>> map;
vector<vector<int>> student;
vector<Status> res;
vector<vector<bool>> Like;
vector<int> seq;

bool cmp(Status s1, Status s2) {
    if (s1.like == s2.like) {
        if (s1.empty == s2.empty) {
            if (s1.x == s2.x) {
                return s1.y < s2.y;
            }
            else return s1.x < s2.x;
        }
        else return s1.empty > s2.empty;
    }
    else return s1.like > s2.like;
}

void Calculate() {
    int ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int cnt = 0;
            int now = map[i][j];

            for (int k = 0; k < 4; k++) {
                int nx = i + mv[k][0];
                int ny = j + mv[k][1];

                if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
                if (Like[now][map[nx][ny]]) cnt++;
            }

            ans += point[cnt];
        }
    }
    cout << ans;
}

void Reccomend(int n) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] != 0) continue;

            Status s = { i, j, 0, 0 };

            for (int k = 0; k < 4; k++) {
                int nx = i + mv[k][0];
                int ny = j + mv[k][1];                

                if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
                if (map[nx][ny] == 0) s.empty++;
                if (Like[n][map[nx][ny]]) s.like++;                
            }
            res.push_back(s);
        }
    }

    sort(res.begin(), res.end(), cmp);
    map[res[0].x][res[0].y] = n;
}

void Solution() {
    for (int i = 0; i < N * N; i++) {
        Reccomend(seq[i]);
        res.clear();
    }
}

void Input() {
    cin >> N;
  
    seq.resize(N * N);
    map.resize(N + 1, vector<int>(N + 1, 0));
    Like.resize(N * N + 1, vector<bool>(N * N + 1, false));

    int n;
    for (int i = 0; i < N * N; i++) {
        cin >> seq[i];
        for (int j = 0; j < 4; j++) {
            cin >> n;
            Like[seq[i]][n] = true;
        }          
    }           
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    Calculate();
    return 0;
}