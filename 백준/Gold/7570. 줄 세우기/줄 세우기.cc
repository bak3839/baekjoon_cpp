#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> num;
vector<int> DP;

void Solution() {
    int ans = 0;

    for (int i = 1; i <= N; i++) {
        int n = num[i];

        DP[n] = DP[n - 1] + 1;
        ans = max(ans, DP[n]);
    }

    cout << N - ans;
}

void Input() {
    cin >> N;

    DP.resize(N + 1, 0);
    num.resize(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> num[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}