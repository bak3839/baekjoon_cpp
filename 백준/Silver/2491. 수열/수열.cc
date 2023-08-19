#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> num;
vector<vector<int>> DP;

void Solution() {
    int ans = 1;

    for (int i = 1; i < N; i++) {
        if (num[i - 1] < num[i]) 
            DP[0][i] = DP[0][i - 1] + 1;

        else if(num[i - 1] > num[i]) 
            DP[1][i] = DP[1][i - 1] + 1;

        else {
            DP[0][i] = DP[0][i - 1] + 1;
            DP[1][i] = DP[1][i - 1] + 1;
        }

        ans = max(ans, max(DP[0][i], DP[1][i]));
    }

    cout << ans;
}

void Input() {
    cin >> N;
    num.resize(N);
    DP.resize(2, vector<int>(N, 1));

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