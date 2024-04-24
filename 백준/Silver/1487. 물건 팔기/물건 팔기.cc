#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N;
vector<pii> pay;
vector<bool> check;

void Solution() {
    int base, sum, ans = 0, ansSum = 0;

    for (int i = 0; i < N; i++) {
        base = pay[i].first, sum = 0;

        for (int j = 0; j < N; j++) {
            if (pay[j].first < base || base - pay[j].second < 0) continue;

            sum += base - pay[j].second;
        }

        if (ansSum == sum) {
            if (base < ans) {
                ans = base;
                ansSum = sum;
            }
        }

        else if (ansSum < sum) {
            ans = base;
            ansSum = sum;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N;

    pay.resize(N);

    for (int i = 0; i < N; i++)
        cin >> pay[i].first >> pay[i].second;
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