#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> point;

void Solution() {
    cout << point[k - 1];
}

void Input() {
    cin >> n >> k;

    point.resize(n);

    for (int i = 0; i < n; i++)
        cin >> point[i];
    sort(point.begin(), point.end(), greater<int>());
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