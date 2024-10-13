#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;
vector<string> res;
map<string, int> m;

void Solution() {
    int first, second, ans = 0;

    for (int i = 0; i < N - 1; i++) {
        first = m[res[i]];

        for (int j = i + 1; j < N; j++) {
            second = m[res[j]];

            if (first < second) ans++;
        }
    }

    cout << ans << "/" << (N * (N - 1)) / 2;
}

void Input() {
    string name;
    cin >> N;

    res.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> name;
        m[name] = i;
    }

    for (int i = 0; i < N; i++) 
        cin >> res[i];
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}