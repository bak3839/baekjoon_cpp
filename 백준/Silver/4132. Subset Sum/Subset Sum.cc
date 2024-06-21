#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll ans = 0;
int N, M;
vector<ll> milk;

void Search(int x, ll sum) {
    if (sum >= N) {
        if (ans == 0) ans = sum;
        else ans = min(ans, sum);
        return;
    }

    for (int i = x; i < M; i++) {
        Search(i + 1, sum + milk[i]);
    }
}

void Solution() {
    Search(0, 0);
    
    if (ans != 0) cout << ans;
    else cout << "IMPOSSIBLE";
}

void Input() {
    cin >> N >> M;

    milk.resize(M);

    for (int i = 0; i < M; i++)
        cin >> milk[i];
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