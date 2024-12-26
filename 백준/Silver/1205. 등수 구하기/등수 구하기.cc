#include <iostream>
#include <vector>

using namespace std;

int N, P, C;
vector<int> nums;

void Solution() {
    int ans = 0, same = 0;

    for (int i = 0; i < N; i++) {
        if (nums[i] > P) {
            ans++;
        }
        else if (nums[i] == P) {
            for (int j = i; j < N; j++) {
                if (nums[j] != P) break;
                same++;
            }
            break;
        }
        else break;
    }

    if (ans + same >= C) cout << -1;
    else cout << ans + 1;
}

void Input() {
    cin >> N >> P >> C;

    nums.resize(N);

    for (int i = 0; i < N; i++)
        cin >> nums[i];
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