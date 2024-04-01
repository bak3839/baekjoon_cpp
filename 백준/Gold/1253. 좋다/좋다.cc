#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, ans;
vector<int> num;
vector<bool> good;

void CheckGoodNum(bool pass, int index) {
    if (pass) return;

    ans++;
    good[index] = true;
}

void Solution() {
    int n, index, target;

    for (int i = 0; i < N; i++) {
        n = num[i];

        if (i > 0 && good[i - 1] && num[i - 1] == n) {
            CheckGoodNum(false, i);
            continue;
        }

        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (n < num[j] && n >= 0) break;

            target = n - num[j];

            if (target > num[N - 1]) continue;

            index = lower_bound(num.begin(), num.end(), target) - num.begin();

            while (j == index || i == index) {
                index++;
            }

            if (index < N && target == num[index]) {
                CheckGoodNum(good[i], i);
            }
        }
    }

    cout << ans;
}

void Input() {
    cin >> N;

    num.resize(N);
    good.resize(N, false);

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