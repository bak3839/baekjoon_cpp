#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
vector<int> nums;

void Solution() {
    int L = 0, R = 1, smaller, larger, diff, ans = 2000000001;

    while (L < R && R < N) {
        smaller = nums[L];
        larger = nums[R];
        diff = abs(larger - smaller);

        if (diff >= M) {
            ans = min(ans, diff);

            if (ans == M) break;
            L++;
        }
        else R++;

        if (L == R) R++;
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    nums.resize(N);

    for (int i = 0; i < N; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}