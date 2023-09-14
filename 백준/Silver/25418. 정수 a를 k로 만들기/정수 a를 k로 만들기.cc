#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int A, K;
vector<int> total;

int bfs() {
    queue<int> q;
    q.push(A);
    total[A] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == K) return total[now];

        if (now + 1 <= 1000000 && total[now + 1] > total[now] + 1) {
            q.push(now + 1);
            total[now + 1] = total[now] + 1;
        }

        if (now * 2 <= 1000000 && total[now * 2] > total[now] + 1) {
            q.push(now * 2);
            total[now * 2] = total[now] + 1;
        }
    }
}

void Solution() {
    cout << bfs();
}

void Input() {
    cin >> A >> K;

    total.resize(1000001, 1000001);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}