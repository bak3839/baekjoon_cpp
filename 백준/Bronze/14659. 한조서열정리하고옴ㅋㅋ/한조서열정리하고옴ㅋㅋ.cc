#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;

void Solution() {
    int ans = 0;

    for (int i = 0; i < N - 1; i++) {
        int now = v[i], cnt = 0;

        for (int j = i + 1; j < N; j++) {
            if (now < v[j]) break;

            cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans;
}

void Input() {
    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];
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
