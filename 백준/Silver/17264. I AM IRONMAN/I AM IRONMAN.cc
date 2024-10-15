#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<string> S;
vector<string> match;
int N, P, W, L, G;

void Solution() {
    int ans = 0;

    for (auto m : match) {
        if (S.find(m) != S.end()) ans += W;
        else {
            ans -= L;
            if (ans < 0) ans = 0;
        }

        if (ans >= G) break;
    }

    if (ans >= G) cout << "I AM NOT IRONMAN!!";
    else cout << "I AM IRONMAN!!";
}

void Input() {
    char state;
    string name;
    cin >> N >> P >> W >> L >> G;

    for (int i = 0; i < P; i++) {
        cin >> name >> state;

        if (state == 'W') S.insert(name);
    }

    for (int i = 0; i < N; i++) {
        cin >> name;
        match.push_back(name);
    }
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