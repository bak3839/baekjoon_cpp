#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;

void Solution() {
    int ans = 0;

    for (int i = N; i <= M; i++) {
        string num = to_string(i);

        for (int j = 0; j < num.size(); j++) {
            if (num[j] == '0') ans++;
        }
    }

    cout << ans << "\n";
}

void Input() {
    cin >> N >> M;
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
