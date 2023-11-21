#include <iostream>
#include <vector>

using namespace std;

int N, K;
string str;

void Solution() {
    int ans = 0;

    for (int i = 0;i < N;i++) {
        bool eat = false;

        if (str[i] == 'H' || str[i] == 'X') continue;

        for (int j = K; j >= 1; j--) {
            int index = i - j;

            if (index < 0) continue;

            if (str[index] == 'H') {
                str[index] = 'X';
                eat = true;
                ans++;
                break;
            }
        }

        if (eat) continue;

        for (int j = 1; j <= K; j++) {
            int index = i + j;

            if (index >= N) break;

            if (str[index] == 'H') {
                str[index] = 'X';
                ans++;
                break;
            }
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> K >> str;
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
