#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long long sum;
vector<int> num;

void Solution() {
    long long ans = 0;

    for (int i = 0; i < N; i++) {
        ans += num[i] * (sum - num[i]);
        sum -= num[i];
    }

    cout << ans;
}

void Input() {
    cin >> N;

    num.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> num[i];
        sum += num[i];
    }
        
    sort(num.begin(), num.end());
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
