#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

void Solution() {
    int n, ans = 0, num = 100001;
    queue<int> q;

    for (int i = 0; i < N; i++) {
        cin >> n;

        if (n == 1) {
            cin >> n;
            q.push(n);

            int cnt = q.size();

            if (ans == cnt) num = min(num, n);

            else if (ans < cnt) {
                ans = cnt;
                num = n;
            }
        }

        else q.pop();
    }

    cout << ans << " " << num;
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