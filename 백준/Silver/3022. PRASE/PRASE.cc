#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;

void Solution() {   
    string name;
    int cnt = 0, ans = 0;

    map<string, int> m;

    for (int i = 0; i < N; i++) {
        cin >> name;

        if (cnt - m[name] < m[name]) ans++;

        cnt++;
        m[name]++;
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