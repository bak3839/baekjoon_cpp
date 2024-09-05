#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N;
vector<pii> num;

void Solution() {
    long long ans = 0;

    for (int i = 0; i < N; i++) 
        ans += (num[i].first * i) + num[i].second;
        
    cout << ans;
}

void Input() {
    cin >> N;

    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i].second;

    for (int i = 0; i < N; i++)
        cin >> num[i].first;

    sort(num.begin(), num.end());
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