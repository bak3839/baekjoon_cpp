#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> DP;
vector<int> num;

void Palindrome(int s, int e) {
    if (DP[s][e] != -1) return;

    if (num[s] != num[e]) {
        DP[s][e] = 0;
        return;
    }

    if (s == e || e - s == 1) {
        DP[s][e] = 1;
        return;
    }

    if (s + 1 <= e - 1) {
        Palindrome(s + 1, e - 1);
        DP[s][e] = DP[s + 1][e - 1] ? 1 : 0;
    }
}

void Solution() {
    int M, s, e;
    cin >> M;

    while (M--) {
        cin >> s >> e;

        if (DP[s][e] == -1) Palindrome(s, e);
        cout << DP[s][e] << "\n";
    }
}

void Input() {
    cin >> N;

    DP.resize(N + 1, vector<int>(N + 1, -1));
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