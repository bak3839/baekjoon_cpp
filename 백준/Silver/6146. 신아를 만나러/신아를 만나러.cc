#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int X, Y, N;
vector<vector<int>> map;
int mv[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void Solution()
{
    queue<pii> q;
    q.push(make_pair(500, 500));
    map[500][500] = 0;

    int ans = 0;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == X + 500 && y == Y + 500){
                cout << ans;
                return;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + mv[i][0];
                int ny = y + mv[i][1];

                if (nx > 1000 || nx < 0 || ny > 1000 || ny < 0 || map[nx][ny] == 0) {
                    continue;
                }

                q.push(make_pair(nx, ny));
                map[nx][ny] = 0;
            }
        }
        ans++;
    }
}

void Input()
{
    int x, y;
    cin >> X >> Y >> N;
    map.resize(1001, vector<int>(1001, 1));

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        map[x + 500][y + 500] = 0;
    }
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}