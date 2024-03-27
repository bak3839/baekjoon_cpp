#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, C;
vector<int> house;

void Solution() {
    int prev = 0, ans = 0, L = 1, R = house[N - 1] - house[0], router, mid;

    while (L <= R) {
        router = 1;
        prev = house[0];
        mid = (L + R) / 2;
        
        for (int i = 1; i < N; i++) {
            if (house[i] - prev >= mid) {
                router++;
                prev = house[i];
            }
        }

        if (router >= C) {
            ans = max(ans, mid);
            L = mid + 1;
        }
        else R = mid - 1;
    }

    cout << ans;
}

void Input() {
    cin >> N >> C;

    house.resize(N);

    for (int i = 0; i < N; i++)
        cin >> house[i];
    sort(house.begin(), house.end());
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