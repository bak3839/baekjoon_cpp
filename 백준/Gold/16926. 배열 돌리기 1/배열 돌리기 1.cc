#include <iostream>
#include <vector>

using namespace std;

int N, M, R, index, len;
vector<int> num;
vector<vector<int>> A;
vector<vector<int>> ans;

int GetIndex() {
    if (index > len - 1) index = 0;
    return index++;
}

// 회전 한 회수만큼 이동하여 수 가져오기
void RotationMatrix(int sx, int ex, int sy, int ey) {
    len = num.size();
    index = len - (R % len);

    for (int i = sx; i < ex; i++) ans[i][sy] = num[GetIndex()];
    for (int i = sy; i < ey; i++) ans[ex][i] = num[GetIndex()];
    for (int i = ex; i > sx; i--) ans[i][ey] = num[GetIndex()];
    for (int i = ey; i > sy; i--) ans[sx][i] = num[GetIndex()];
}

// 원본 배열을 돌면서 숫자 알아내기
void FillOriginNum(int sx, int ex, int sy, int ey) {
    for (int i = sx; i < ex; i++) num.push_back(A[i][sy]);
    for (int i = sy; i < ey; i++) num.push_back(A[ex][i]);
    for (int i = ex; i > sx; i--) num.push_back(A[i][ey]);
    for (int i = ey; i > sy; i--) num.push_back(A[sx][i]);
}

void ChangeCoordinate(int* sx, int* ex, int* sy, int* ey) {
    *sx = *sx + 1; *ex = *ex - 1;
    *sy = *sy + 1; *ey = *ey - 1;
}

void Solution() {
    int sx = 0, ex = N - 1, sy = 0, ey = M - 1;

    while (sx < ex && sy < ey) {
        FillOriginNum(sx, ex, sy, ey);
        RotationMatrix(sx, ex, sy, ey);
        ChangeCoordinate(&sx, &ex, &sy, &ey);
        num.clear();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

void Input() {
    cin >> N >> M >> R;

    A.resize(N, vector<int>(M));
    ans.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}