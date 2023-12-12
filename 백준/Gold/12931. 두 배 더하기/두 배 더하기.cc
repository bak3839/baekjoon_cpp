#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> num;

void Solution() {
    int ans = 0;

    while (1) {
        bool pass = true;
        int z = 0;

        for (int i = 0; i < N; i++) {
            if (num[i] == 0) z++;

            else if (num[i] % 2) {
                pass = false;
                num[i] -= 1;
                break;
            }
        }

        if (z == N) break;

        else if (pass) {
            for (int i = 0; i < N; i++)
                num[i] /= 2;
        }

        ans++;
    }

    cout << ans;
}

void Input() {
    cin >> N;

    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];
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
