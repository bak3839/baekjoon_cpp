#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
vector<int> name;
int dp[1001][1001];

int Solution(int index, int remain) {
    if (index >= N) return 0;

    int res = dp[index][remain];

    if (res != -1) return res;

    res = (M - remain + 1) * (M - remain + 1) + Solution(index + 1, name[index] + 1);

    if (remain + name[index] <= M) {
        res = min(res, Solution(index + 1, remain + name[index] + 1));
    }
    dp[index][remain] = res;

    return res;
}

void Input() {
    cin >> N >> M;

    name.resize(N);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) cin >> name[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    cout << Solution(0, 0);
    return 0;
}