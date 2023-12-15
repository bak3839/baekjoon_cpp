#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> num;

void Solution() {
    int ans = 10;

    for (int i = 0; i < N; i++) {
        int sum = 1, cnt = 0;

        for (int j = i + 1; j < N; j++) {
            if (5 - sum >= num[j] - num[j - 1]) {
                sum += num[j] - num[j - 1];
                cnt += num[j] - num[j - 1] - 1;
            }
            else {
                cnt += 5 - sum;
                break;
            }
        }
        if (cnt < 5) {
            cnt += 5 - sum;
        }
        ans = min(ans, cnt);
    }

    cout << ans;
}

void Input() {
    cin >> N;

    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];
    sort(num.begin(), num.end());
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
