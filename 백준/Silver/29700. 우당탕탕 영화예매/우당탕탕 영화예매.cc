#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M, K;
string target = "";
vector<string> seat;

void Solution() {
    int ans = 0, index;

    for (int i = 0; i < N; i++) {
        index = 0;

        while ((index = seat[i].find(target, index)) != string::npos) {
            ans++;
            index++;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M >> K;

    seat.resize(N);

    for (int i = 0; i < N; i++)
        cin >> seat[i];

    for (int i = 0; i < K; i++)
        target.push_back('0');
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