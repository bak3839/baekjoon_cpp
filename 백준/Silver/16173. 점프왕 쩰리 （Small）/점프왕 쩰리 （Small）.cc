#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N;
int arr[3][3];
bool visited[3][3];

bool bfs() {
    queue<pii> q;
    q.push({ 0, 0 });
    visited[0][0] = true;

    int x, y, nx, ny, step;

    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        step = arr[x][y];
        q.pop();

        if (step == -1) return true;

        nx = x + step; ny = y + step;

        if (nx < N && !visited[nx][y]) {
            visited[nx][y] = true;
            q.push({ nx, y });
        }

        if (ny < N && !visited[x][ny]) {
            visited[x][ny] = true;
            q.push({ x, ny });
        }   
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    if (bfs()) cout << "HaruHaru";
    else cout << "Hing";

    return 0;
}