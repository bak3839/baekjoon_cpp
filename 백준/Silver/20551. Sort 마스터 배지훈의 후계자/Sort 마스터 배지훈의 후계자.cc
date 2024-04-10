#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> num;

void Solution() {
    int n;

    for (int i = 0; i < M; i++) {
        cin >> n;

        int index = lower_bound(num.begin(), num.end(), n) - num.begin();
        
        if (index < N && num[index] == n) cout << index << "\n";
        else cout << -1 << "\n";
    }
}

void Input() {
    cin >> N >> M;

    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];
    sort(num.begin(), num.end());
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