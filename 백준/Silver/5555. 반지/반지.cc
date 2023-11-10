#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
string target;
vector<string> ring;

void Solution() {
    int tLen = target.size(), ans = 0;

    for (int i = 0; i < N; i++) {
        string now = ring[i];
        int nLen = now.size();

        for (int j = 0; j < nLen; j++) {
            bool pass = true;

            for (int k = 0; k < tLen; k++) {
                if (now[(k + j) % nLen] == target[k]) continue;

                pass = false;
                break;
            }

            if (pass) {
                ans++;
                break;
            }
        }
    }

    cout << ans;
}

void Input() {
    cin >> target >> N;

    ring.resize(N);

    for (int i = 0; i < N; i++)
        cin >> ring[i];
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
