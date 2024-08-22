#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<string> window;

void Solution() {
    vector<int> ans(5, 0);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int r = i * 4 + 1 + i;
            int c = j * 4 + 1 + j;
            int cnt = 0;

            for(int k = 0; k < 4; k++) {
                if(window[r + k][c] == '.') break;

                cnt++;
            }

            ans[cnt]++;
        }
    }

    for(int i = 0; i < 5; i++) {
        cout << ans[i] << " ";
    }
}

void Input() {
    cin >> N >> M;

    window.resize(N * 5 + 1);

    for(int i = 0; i < N * 5 + 1; i++) {
        cin >> window[i];
    }
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