#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int K, N, cnt;
vector<int> point;

void Solution() {
    int ansMax = point[0], ansMin = point[N - 1], largeGap = 0;

    for (int i = 0; i < N - 1; i++)
        largeGap = max(largeGap, point[i] - point[i + 1]);

    cout << "Class " << cnt << "\n";
    cout << "Max " << ansMax << ", Min " << ansMin << ", Largest gap " << largeGap << "\n";
}

void Input() {
    cin >> N;

    point.resize(N);

    for (int i = 0; i < N; i++)
        cin >> point[i];

    sort(point.begin(), point.end(), greater<int>());
}

void Solve() {
    cin >> K;

    while (K--) {
        cnt++;
        Input();
        Solution();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
