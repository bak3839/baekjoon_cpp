#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, ans;
vector<string> S;

void Solution() {
    string now;
    bool pass;

    for (int i = 0; i < N - 1; i++) {
        now = S[i];
       
        for (int j = i + 1; j < N; j++) {
            pass = true;

            for (int k = 0; k < now.size(); k++) {
                if (S[j][k] != now[k]) {
                    pass = false;
                    break;
                }
            }

            if (pass) {
                ans++;
                break;
            }
        }
    }
    cout << N - ans;
}

void Input() {
    cin >> N;
    S.resize(N);

    for (int i = 0; i < N; i++)
        cin >> S[i];
    sort(S.begin(), S.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}