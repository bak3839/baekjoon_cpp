#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, L, R, X, ans;
vector<int> num;

void Search(int x, int sum, int max_num, int min_num, int cnt) {
    if (cnt == 0) {
        if (L <= sum && sum <= R && max_num - min_num >= X) ans++;
        return;
    }

    for (int i = x; i < N; i++) 
        Search(i + 1, sum + num[i], max(max_num, num[i]), min(min_num, num[i]), cnt - 1);
}

void Solution() {
    for (int i = 2; i <= N; i++)
        Search(0, 0, 0, 10000001, i);

    cout << ans;
}

void Input() {
    cin >> N >> L >> R >> X;
    num.resize(N);

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
