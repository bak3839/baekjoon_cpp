#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int N;
vector<pii> v;

bool compare1(pii p1, pii p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first;
}

bool compare2(pii p1, pii p2) {
    if (p1.second == p2.second) return p1.first > p2.first;
    return p1.second < p2.second;
}

void Solution() {
    sort(v.begin(), v.end(), compare1);

    for (int i = 0; i < 2; i++)
        cout << v[i].first << " " << v[i].second << " ";
    cout << "\n";

    sort(v.begin(), v.end(), compare2);

    for (int i = 0; i < 2; i++)
        cout << v[i].first << " " << v[i].second << " ";
}

void Input() {
    cin >> N;

    v.resize(N);

    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
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