#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int A, B, res = 2000000001;
    cin >> A >> B;

    queue<pair<ll, int>> q;
    q.push({ A, 1 });

    while (!q.empty()) {
        ll now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (now == B) res = min(res, cnt);

        if (now * 2 <= B) q.push({ now * 2, cnt + 1 });
        if (now * 10 + 1 <= B) q.push({ now * 10 + 1, cnt + 1 });
    }

    if (res == 2000000001) cout << "-1";
    else cout << res;
    return 0;
}