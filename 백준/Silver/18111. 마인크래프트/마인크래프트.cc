#include <bits/stdc++.h>

using namespace std;

int N, M, B;
vector<vector<int>> H;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ansTime = 210000000, ansHeight = 0;
    cin >> N >> M >> B;

    H.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> H[i][j];
        }
    }

    for (int h = 0; h <= 256; h++) {
        int b = B, cnt = 0, time = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (h == H[i][j]) continue;

                cnt = H[i][j] - h;

                if (cnt > 0) {
                    time += cnt * 2;
                    b += cnt;
                }
                else {
                    time += cnt * -1;
                    b -= cnt * -1;
                }
            }
        }

        if (b >= 0 && ansTime >= time) {
            ansTime = time;
            ansHeight = h;
        }
    }

    cout << ansTime << " " << ansHeight;
    return 0;
}