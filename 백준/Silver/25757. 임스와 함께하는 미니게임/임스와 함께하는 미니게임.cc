#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
char game;
set<string> s;

void Solution() {
    int n;

    if (game == 'Y') n = 1;
    else if (game == 'F') n = 2;
    else n = 3;

    cout << s.size() / n;
}

void Input() {
    cin >> N >> game;

    string name;

    for (int i = 0; i < N; i++) {
        cin >> name;
        s.insert(name);
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
