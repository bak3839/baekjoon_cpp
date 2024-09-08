#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pss = pair<string, string>;

int N;
vector<pss> couple;

bool cmp(pss p1, pss p2) {
    if (p1.first < p2.first) return true;
    else if (p1.first == p2.first) return p1.second > p2.second;

    return false;
}

void Solution() {
    sort(couple.begin(), couple.end(), cmp);

    for (int i = 0; i < N; i++)
        cout << couple[i].first << " " << couple[i].second << "\n";
}

void Input() {
    cin >> N;

    couple.resize(N);

    for (int i = 0; i < N; i++)
        cin >> couple[i].first >> couple[i].second;
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