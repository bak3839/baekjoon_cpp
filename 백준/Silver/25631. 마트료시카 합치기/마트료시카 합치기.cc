#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> num;

void Solution() {
    int ans = 0, cnt = 1;

    for (int i = 1; i < N; i++) {
        if (num[i] == num[i - 1]) cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }

    ans = max(ans, cnt);
    cout << ans;
}

void Input() {
    cin >> N;

    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];
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