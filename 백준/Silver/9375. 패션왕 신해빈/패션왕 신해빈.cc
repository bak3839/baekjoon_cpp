#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;
map<string, int> m;

void Solution() {
    int ans = 1;

    for (auto iter : m) {
        ans *= iter.second + 1;
    }

    cout << --ans << "\n";
}

void Input() {

    string name, type;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> name >> type;

        m[type]++;
    }

}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
        m.clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
