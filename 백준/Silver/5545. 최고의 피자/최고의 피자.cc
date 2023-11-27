#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, A, B, sum;
vector<int> toping;

void Solution() {
    int total = A, ans = sum / A;

    for (int i = 0;i < N;i++) {
        if (ans > (sum + toping[i]) / (total + B)) break;

        ans = (sum + toping[i]) / (total + B);
        sum += toping[i];
        total += B;
    }

    cout << ans;
}

void Input() {
    cin >> N >> A >> B >> sum;

    toping.resize(N);

    for (int i = 0;i < N;i++)
        cin >> toping[i];
    sort(toping.begin(), toping.end(), greater<int>());
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
