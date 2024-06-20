#include <iostream>
#include <queue>

using namespace std;

int N, K;

void Solution() {
    queue<int> q;

    for (int i = 1; i <= N; i++)
        q.push(i);

    while (q.size() > 1) {
        int first = q.front();
        q.pop();

        for (int i = 0; i < K - 1; i++) {
            if (q.size() == 0) break;
            q.pop();
        }

        q.push(first);
    }

    cout << q.front();
}

void Input() {
    cin >> N >> K;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}