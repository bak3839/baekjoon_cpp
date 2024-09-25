#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;

void Solution() {
    int ans = 0;
    string result;
    map<string, int> DOMjudge;
    map<string, int> Kattis;

    for (int i = 0; i < N; i++) {
        cin >> result;
        DOMjudge[result]++;
    }

    for (int i = 0; i < N; i++) {
        cin >> result;
        Kattis[result]++;
    }

    for (auto res : DOMjudge) {
        ans += (min(res.second, Kattis[res.first]));
    }

    cout << ans;
}

void Input() {
    cin >> N;
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