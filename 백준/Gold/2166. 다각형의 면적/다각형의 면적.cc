#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using pdd = pair<double, double>;

int N;
vector<pdd> point;

void Solution() {
    double area = 0.0;

    for (int i = 0; i < N - 1; ++i) {
        area += point[i].first * point[i + 1].second;
        area -= point[i].second * point[i + 1].first;
    }

    area += point[N - 1].first * point[0].second;
    area -= point[N - 1].second * point[0].first;

    area = abs(area) / 2.0;

    cout << fixed;
    cout.precision(1);
    cout << round(area * 100.0) / 100.0;
}

void Input() {
    cin >> N;

    point.resize(N);

    for (int i = 0; i < N; i++)
        cin >> point[i].first >> point[i].second;
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