#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

void Solution() {
    queue<int> q;
    long long res = 0, t = 1;

    for (int i = 1; i <= N; i++)
        q.push(i);

    while (q.size() != 1) {
        long long n = t * t * t;
        res = n % q.size();

        if (res == 0) res = q.size();

        for (int i = 0; i < res - 1; i++) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }

        q.pop();
        t++;
    }

    cout << q.front();
}

void Input() {
    cin >> N;
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