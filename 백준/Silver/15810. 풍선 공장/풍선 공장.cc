#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> T;

void Solution() {
    long long L = 1, R = 1000000000000, mid, ans = 0, cnt;

    while (L <= R) {
        cnt = 0;
        mid = (L + R) / 2;

        for (int i = 0; i < N; i++)
            cnt += mid / T[i];

        if (cnt >= M) {
            ans = mid;
            R = mid - 1;
        }
        else {
            L = mid + 1;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;
    
    T.resize(N);

    for (int i = 0; i < N; i++)
        cin >> T[i];
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