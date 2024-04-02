#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

int N, M;
vector<int> times;

void Solution() {
    ull L = 1, R = 1e19, mid, cnt, ans = 1e19;

    while(L <= R) {
        cnt = 0;
        mid = (L + R) / 2;

        for(int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
            if(cnt >= M) break;
        }

        if(cnt >= M) {
            ans = min(ans, mid);
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    times.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> times[i];
    }
    sort(times.begin(), times.end());
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