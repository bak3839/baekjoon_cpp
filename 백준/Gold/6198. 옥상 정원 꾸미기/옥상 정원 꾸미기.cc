#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using pii = pair<int, int>;

int N;
vector<int> H;

void Solution() {
    long long ans = 0;

    stack<pii> s;
    s.push({ H[N - 1],0 });

    for (int i = N - 2; i >= 0; i--) {
        int now = H[i], cnt = 0;

        while (!s.empty()) {
            int h = s.top().first;
            int total = s.top().second;

            if (now > h) {
                cnt += (total + 1);
                s.pop();
            }
            else break;
        }

        ans += cnt;
        s.push({ now, cnt });
    }

    cout << ans;
}

void Input() {
    cin >> N;

    H.resize(N);

    for (int i = 0; i < N; i++)
        cin >> H[i];
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
