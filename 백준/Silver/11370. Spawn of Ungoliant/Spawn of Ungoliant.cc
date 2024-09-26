#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int W, H, N;
vector<string> map;
int mv[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int x, int y)
{
    queue<pii> q;
    q.push({x, y});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W || map[nx][ny] != 'T')
                continue;

            map[nx][ny] = 'S';
            q.push({nx, ny});
        }
    }
}

void Solution()
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (map[i][j] == 'S')
                bfs(i, j);
        }
    }

    for (int i = 0; i < H; i++)
        cout << map[i] << "\n";
}

void Input()
{
    map.resize(H);

    for (int i = 0; i < H; i++)
    {
        cin >> map[i];
    }
}

void Solve()
{
    while (1)
    {
        cin >> W >> H;

        if (W == 0 && H == 0)
            break;

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