#include <bits/stdc++.h>

using namespace std;

int N, maxPoint;
int hitter[10];
bool visited[10], base[4];
vector<vector<int>> R;

int Move(int n) {
    int res = 0;

    for (int i = 3; i >= 0; i--) {
        if (base[i] && i + n >= 4) {
            res++;
            base[i] = false;
        }
        else if (base[i] && i + n < 4) {
            base[i] = false;
            base[i + n] = true;
        }
    }

    return res;
}

void GameStart() {
    int outCnt = 0, idx = 1, n, point = 0;
    
    for (int i = 1; i <= N; i++) {
        while (outCnt < 3) {
            n = R[i][hitter[idx++]];

            if (idx > 9) idx = 1;

            if (n == 0) {
                outCnt++;
                continue;
            }

            base[0] = true;
            point += Move(n);
        }
        
        outCnt = 0;
        memset(base, false, sizeof(base));
    }

    maxPoint = max(maxPoint, point);
}

void Search(int num) {
    if (num == 10) {
        GameStart();
        return;
    }

    if (num == 4) num++;

    for (int i = 2; i <= 9; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        hitter[num] = i;
        Search(num + 1);
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    cin >> N;
    R.resize(N + 1, vector<int>(10));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 9; j++)
            cin >> R[i][j];
    }

    hitter[4] = 1;
    Search(1);
    cout << maxPoint;

    return 0;
}