#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> candy;

bool CountCheck() {
    for (int i = 1; i < N; i++) {
        if (candy[i - 1] != candy[i]) return false;
    }

    return true;
}

void PassRight() {
    vector<int> tmp(candy.begin(), candy.end());

    for (int i = 0; i < N; i++) {
        candy[i] -= tmp[i] / 2;

        if (i < N - 1) candy[i + 1] += tmp[i] / 2;
        else candy[0] += tmp[i] / 2;
    }
}

void MakeEven() {
    for (int i = 0; i < N; i++) {
        if (candy[i] % 2 != 0) candy[i]++;
    }
}

void Solution() {
    int ans = 0;

    while (1) {
        if (CountCheck()) break;

        PassRight();
        MakeEven();
        ans++;
    }

    cout << ans << "\n";
}

void Input() {
    cin >> N;

    candy.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> candy[i];

        if (candy[i] % 2 != 0) candy[i]++;
    }
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
        candy.clear();
    }  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}