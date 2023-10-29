#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> price;

void Solution() {
    int ans = 0;

    for (int i = 0; i < N; i += 3) {
        for (int j = i; j < N && j < i + 2; j++)
            ans += price[j];
    }

    cout << ans;
}

void Input() {
    cin >> N;

    price.resize(N);

    for (int i = 0;i < N;i++)
        cin >> price[i];
    sort(price.begin(), price.end(), greater<int>());
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
