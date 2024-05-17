#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int N;
vector<pii> student;

bool cmp(pii p1, pii p2) {
    if (p1.first == p2.first) return p1.second < p2.second;

    return p1.first > p2.first;
}

void Solution() {
    sort(student.begin(), student.end(), cmp);

    int solve = student[4].first, ans = 0;

    for (int i = 5; i < N; i++) {
        if (solve != student[i].first) break;

        ans++;
    }

    cout << ans;
}

void Input() {
    cin >> N;

    student.resize(N);

    for (int i = 0; i < N; i++)
        cin >> student[i].first >> student[i].second;
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