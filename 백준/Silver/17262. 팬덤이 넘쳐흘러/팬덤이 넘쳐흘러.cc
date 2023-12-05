#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N;
vector<pii> T;

bool compare(pii t1, pii t2) {
    if (t1.second < t2.second) return true;
    else if (t1.second == t2.second) {
        if (t1.first < t2.first) return true;
        return false;
    }
    return false;
}

void Solution() {
    int ans = 0, last = T[0].second;

    for (int i = 1;i < N;i++) {
        if (T[i].first <= last) continue;

        ans += T[i].first - last;
        last = T[i].first;
    }

    cout << ans;
}

void Input() {
    int s, e;
    cin >> N;

    for (int i = 0;i < N;i++) {
        cin >> s >> e;
        T.push_back({ s, e });
    }
    sort(T.begin(), T.end(), compare);
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
