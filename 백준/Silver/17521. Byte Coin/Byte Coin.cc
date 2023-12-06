#include <iostream>
#include <vector>

using namespace std;

int n;
long long W;
vector<int> coin;

void Solution() {
    int low = coin[0];
    long long cnt = W / coin[0];

    for (int i = 1;i < n;i++) {
        if (low > coin[i]) {            
            low = coin[i];
            cnt = W / low;
            continue;
        }

        else if (i != n - 1 && coin[i] < coin[i + 1]) continue;

        W -= low * cnt;
        W += coin[i] * cnt;

        if (i == n - 1) continue;

        low = coin[i + 1];
        cnt = W / coin[i + 1];
        i++;
    }

    cout << W;
}

void Input() {
    cin >> n >> W;

    coin.resize(n);

    for (int i = 0;i < n;i++)
        cin >> coin[i];
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
