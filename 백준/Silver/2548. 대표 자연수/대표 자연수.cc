#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> num, visit;

void Solution() {
    int diff = 2100000000, ans = 10000;

    for (int i = 0; i < N; i++) {
        int n = num[i], res = 0;

        if (visit[n]) continue;

        visit[n] = true;

        for (int j = 0; j < N; j++) 
            res += abs(num[j] - n);

        if (diff == res && ans > n) ans = n;
        else if (diff > res) {
            ans = n;
            diff = res;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N;

    num.resize(N);
    visit.resize(10001, false);

    for (int i = 0; i < N; i++)
        cin >> num[i];
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