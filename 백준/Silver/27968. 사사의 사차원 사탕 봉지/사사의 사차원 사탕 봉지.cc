#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int N, M;
vector<ll> candy;

void Solution() {
    ll target;

    for (int i = 0; i < N; i++) {
        cin >> target;

        int index = lower_bound(candy.begin(), candy.end(), target) - candy.begin();
        
        if (index > M) cout << "Go away!\n";
        else cout << index << "\n";
    }
    
}

void Input() {
    ll n;
    cin >> N >> M;

    candy.resize(M + 1, 0);

    for (int i = 1; i <= M; i++) {
        cin >> n;
        candy[i] = candy[i - 1] + n;
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