#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> DP;
vector<int> num;

void Solution() {
    int ans = 0;

    for (int i = 1; i < N; i++) {
        
        for (int j = i - 1; j >= 0; j--) {
            if (num[i] < num[j]) continue;

            DP[i] = max(DP[i], DP[j] + 1);
        }
        ans = max(ans, DP[i]);
    }

    cout << N - ans;
}

void Input() {
    cin >> N;

    DP.resize(N, 1);
    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}