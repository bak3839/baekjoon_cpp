#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;
map<string, int> m;

void Solution() {
    string name;

    for (int i = 0; i < N - 1; i++) {
        cin >> name;
        m[name]--;
    }

    for (auto iter : m) {
        if (iter.second == 0) continue;

        cout << iter.first;
        break;
    }       
}

void Input() {
    cin >> N;

    string name;

    for (int i = 0; i < N; i++) {
        cin >> name;
        m[name]++;
    }
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
