#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> num;
vector<bool> check;

void Solution() {
    int cnt = 0, ans = 0;

    for (int i = 0; i < N * 2; i++) {
        int menu = num[i];

        if (check[menu]) cnt--;
        else {
            cnt++;
            check[menu] = true;
        }

        ans = max(ans, cnt);
    }

    cout << ans;
}

void Input() {
    cin >> N;

    num.resize(N * 2);
    check.resize(N + 1, false);

    for (int i = 0; i < N * 2; i++)
        cin >> num[i];
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