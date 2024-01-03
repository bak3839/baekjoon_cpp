#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> v1, v2;

int Difference_set1() {
    vector<int> diff(v1.size() + v2.size());

    auto iter = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), diff.begin());
    diff.erase(iter, diff.end());

    return diff.size();
}

int Difference_set2() {
    vector<int> diff(v1.size() + v2.size());

    auto iter = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), diff.begin());
    diff.erase(iter, diff.end());

    return diff.size();
}

void Solution() {
    cout << Difference_set1() + Difference_set2();
}

void Input() {
    cin >> N >> M;

    v1.resize(N);
    v2.resize(M);

    for (int i = 0; i < N; i++)
        cin >> v1[i];

    for (int i = 0; i < M; i++)
        cin >> v2[i];

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
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
