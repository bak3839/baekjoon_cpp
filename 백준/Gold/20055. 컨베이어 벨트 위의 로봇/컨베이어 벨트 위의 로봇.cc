#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K, S, down = 0;
vector<int> D;
vector<bool> robot;

int StartPoint(int r) {
    int index = S - (r % S);
    return (index >= S ? 0 : index);
}

int EndPoint(int r) {
    int index = StartPoint(r) + N - 1;
    return (index % S);
}

void MoveRobot(int now, int next) {
    robot[now] = false;
    robot[next] = true;
    D[next]--;

    if (D[next] == 0) down++;
}

void DropRobot(int now, int next) {
    robot[now] = false;

    if (next != -1) {
        D[next]--;

        if (D[next] == 0) down++;
    }
}

void PutRobot(int now) {
    robot[now] = true;
    D[now]--;

    if (D[now] == 0) down++;
}

void Solution() {
    int ans = 0, rotation = 0;
    int size, now, start, end, next;
    queue<int> q;

    while (down < K) {
        ans++;
        size = q.size();

        // 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전
        rotation++;
        start = StartPoint(rotation);
        end = EndPoint(rotation);

        // 2. 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동. 이동할 수 없다면 가만히
        while (size--) {
            now = q.front();
            q.pop();

            if (now == end) {
                DropRobot(now, -1);
                continue;
            }

            next = (now + 1) % S;

            if (D[next] <= 0 || robot[next]) {
                q.push(now);
                continue;
            }

            if (next == end) DropRobot(now, next);
            else {
                MoveRobot(now, next);
                q.push(next);
            }      
        }

        // 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        if (D[start] > 0) {
            PutRobot(start);
            q.push(start);
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> K;

    S = 2 * N;
    D.resize(N * 2);
    robot.resize(N * 2, false);

    for (int i = 0; i < N * 2; i++)
        cin >> D[i];
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}