#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N, X;
vector<int> DP;
vector<pii> pipe;

void Solution() {
    DP[0] = 1;

    for (int i = 0; i < N; i++) {
        int l = pipe[i].first;
        int c = pipe[i].second;

        for (int j = X; j >= 0; j--) {
            for (int k = 1; k <= c && j - l * k >= 0; k++) {
                DP[j] += DP[j - l * k];
            }
        }
    }

    cout << DP[X];
}

void Input() {
    cin >> N >> X;

    pipe.resize(N);
    DP.resize(X + 1, 0);

    for (int i = 0; i < N; i++)
        cin >> pipe[i].first >> pipe[i].second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
