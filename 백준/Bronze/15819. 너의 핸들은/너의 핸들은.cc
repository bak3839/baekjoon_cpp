#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<string> handle;

void Solution() {
    cout << handle[M - 1];
}

void Input() {
    cin >> N >> M;

    handle.resize(N);

    for (int i = 0; i < N; i++)
        cin >> handle[i];
    sort(handle.begin(), handle.end());
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