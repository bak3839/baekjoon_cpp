#include <iostream>
#include <vector>

using namespace std;

int N, M, ans;
vector<int> snow;

void MakeSnowBall(int size, int count, int index) {

    if (count == M) {
        ans = max(ans, size);
        return;
    }

    if (index + 1 < N)
        MakeSnowBall(size + snow[index + 1], count + 1, index + 1);
    else
        ans = max(ans, size);

    if (index + 2 < N)
        MakeSnowBall(size / 2 + snow[index + 2], count + 1, index + 2);
    else
        ans = max(ans, size);
}

void Solution() {
    MakeSnowBall(1, 0, -1);
    cout << ans;
}

void Input() {
    cin >> N >> M;

    snow.resize(N);

    for (int i = 0; i < N; i++)
        cin >> snow[i];
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
