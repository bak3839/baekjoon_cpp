#include <bits/stdc++.h>

using namespace std;

int N, M, R;
vector<int> num;
vector<vector<int>> A, ans;

void RotateMatrix(int sx, int ex, int sy, int ey) {
    int len = num.size();
    int index = len - (R % len);

    for (int i = sx; i < ex; i++) ans[i][sy] = num[index++ % len];
    for (int i = sy; i < ey; i++) ans[ex][i] = num[index++ % len];
    for (int i = ex; i > sx; i--) ans[i][ey] = num[index++ % len];
    for (int i = ey; i > sy; i--) ans[sx][i] = num[index++ % len];
    num.clear();
}

void MakeNumList(int sx, int ex, int sy, int ey) {
    for (int i = sx; i < ex; i++) num.push_back(A[i][sy]);
    for (int i = sy; i < ey; i++) num.push_back(A[ex][i]);
    for (int i = ex; i > sx; i--) num.push_back(A[i][ey]);
    for (int i = ey; i > sy; i--) num.push_back(A[sx][i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;

    A.resize(N, vector<int>(M));
    ans.resize(N, vector<int>(M));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    int sx = 0, sy = 0, ex = N - 1, ey = M - 1;

    while (sx < ex && sy < ey) {
        MakeNumList(sx, ex, sy, ey);
        RotateMatrix(sx, ex, sy, ey);  
        sx++; sy++;
        ex--; ey--;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
