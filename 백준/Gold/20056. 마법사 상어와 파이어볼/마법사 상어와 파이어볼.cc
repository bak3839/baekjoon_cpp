#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

typedef struct {
    int r;
    int c;
    int m;
    int s;
    int d;
}fire;

vector<fire> ball;
vector<fire> map[52][52];

int mv1[4] = { 0, 2, 4, 6 };
int mv2[4] = { 1, 3, 5, 7 };
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void Move_FireBall(int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            map[i][j].clear();
        }
    }

    for (int i = 0; i < ball.size(); i++)
    {
        int r = ball[i].r;
        int c = ball[i].c;
        int Mass = ball[i].m;
        int Speed = ball[i].s;
        int Dir = ball[i].d;
    
        int Move = Speed % N;
        int nr = r + dx[Dir] * Move;
        int nc = c + dy[Dir] * Move;
        if (nr > N) nr -= N;
        if (nc > N) nc -= N;
        if (nr < 1) nr += N;
        if (nc < 1) nc += N;

        map[nr][nc].push_back({ nr,nc,Mass,Speed,Dir });
        ball[i].r = nr;
        ball[i].c = nc;
    }
}

void Sum_FireBall(int N)
{
    vector<fire> tmp;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (map[i][j].size() == 0)continue;
            if (map[i][j].size() == 1)
            {
                tmp.push_back(map[i][j][0]);
                continue;
            }

            int Massive_Sum = 0;
            int Speed_Sum = 0;
            int Cnt = map[i][j].size();

            bool Even = true;
            bool Odd = true;

            for (int k = 0; k < map[i][j].size(); k++)
            {
                Massive_Sum += map[i][j][k].m;
                Speed_Sum += map[i][j][k].s;
                if (map[i][j][k].d % 2 == 0) Odd = false;
                else Even = false;
            }

            int Mass = Massive_Sum / 5;
            int Speed = Speed_Sum / Cnt;

            if (Mass == 0) continue;
            if (Even == true || Odd == true)
            {
                for (int k = 0; k < 4; k++) tmp.push_back({ i, j, Mass, Speed, mv1[k] });
            }
            else
            {
                for (int k = 0; k < 4; k++) tmp.push_back({ i, j, Mass, Speed, mv2[k] });
            }
        }
    }

    ball = tmp;
}

void Solution(int N, int K)
{
    for (int i = 0; i < K; i++)
    {
        Move_FireBall(N);
        Sum_FireBall(N);
    }

    int ans = 0;
    for (int i = 0; i < ball.size(); i++) ans += ball[i].m;

    cout << ans;
}

void input(int N, int M) {
    fire f;

    for (int i = 0; i < M; i++) {
        cin >> f.r >> f.c >> f.m >> f.s >> f.d;

        ball.push_back(f);
        map[f.r][f.c].push_back(f);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    input(N, M);
    Solution(N, K);
    return 0;
}