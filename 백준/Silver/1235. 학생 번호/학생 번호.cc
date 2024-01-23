#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
vector<string> num;

void Solution() {
    set<string> s;
    int size = num[0].size(), ans = 0;

    for (int k = 1; k <= size; k++) {
        for (int i = 0; i < N; i++) s.insert(num[i].substr(size - k, k));

        if (s.size() == N) {
            ans = k;
            break;
        }

        s.clear();
    }

    cout << ans;
}

void Input() {
    cin >> N;

    num.resize(N);

    for (int i = 0; i < N; i++)
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
