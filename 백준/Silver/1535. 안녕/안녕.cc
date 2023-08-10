#include <iostream>
#include <vector>

using namespace std;

int N;
int DP[101];

vector<int> fatigue;
vector<int> happy;

void Solution() {
    for (int i = 1; i <= N; i++) {
        int f = fatigue[i], h = happy[i];

        for (int j = 100; j > f; j--)
            DP[j] = max(DP[j], DP[j - f] + h);
    }

    cout << DP[100];
}

void Input() {
    cin >> N;

    fatigue.resize(N + 1);
    happy.resize(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> fatigue[i];

    for (int i = 1; i <= N; i++)
        cin >> happy[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}