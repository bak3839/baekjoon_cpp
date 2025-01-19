#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, T, n, cnt = 0;
    cin >> N >> T;

    deque<int> dq;
    vector<int> target(T), ans;

    for (int i = 0; i < N * 2; i++) {
        cin >> n;
        dq.push_back(n);
    }

    for (int i = 0; i < T; i++)
        cin >> target[i];

    for (int t : target) {
        while (1) {
            cnt++;

            if (t == cnt) {
                cnt = 0;
                ans.push_back(dq.front());
                break;
            }

            dq.push_back(dq.front());
            dq.pop_front();
        }
    }

    for (int a : ans)
        cout << a << " ";

    return 0;
}