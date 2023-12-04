#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int J, N;
vector<int> box;

void Solution() {
    int ans = 0, index = 0;

    while (index < N && J > 0) {
        J -= box[index++];
        ans++;
    }

    cout << ans << "\n";
    box.clear();
}

void Input() {
    int R, C;
    cin >> J >> N;

    box.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> R >> C;
        box[i] = R * C;
    }
    sort(box.begin(), box.end(), greater<int>());
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
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
