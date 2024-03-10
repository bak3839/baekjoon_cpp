#include <iostream>
#include <vector>

using namespace std;

int N, Z, O, M;
vector<vector<int>> paper;

int CutPaper(int x, int y, int len) {
    int n = paper[x][y];

    for (int i = x; i < len + x; i++) {
        for (int j = y; j < y + len; j++) {
            if (paper[i][j] != n) return 2;
        }
    }

    return n;
}

void Search(int x, int y, int len) {
    int halfLen = len / 3;
    int color = CutPaper(x, y, len);

    if (color == 1) O++;

    else if (color == 0) Z++;

    else if (color == -1) M++;

    else if (len > 1 && color == 2) {
        Search(x, y, halfLen);
        Search(x, y + halfLen, halfLen);
        Search(x + halfLen, y, halfLen);
        Search(x + halfLen, y + halfLen, halfLen);
        Search(x + halfLen * 2, y, halfLen);
        Search(x + halfLen * 2, y + halfLen, halfLen);
        Search(x, y + halfLen * 2, halfLen);
        Search(x + halfLen, y + halfLen * 2, halfLen);
        Search(x + halfLen * 2, y + halfLen * 2, halfLen);
    }
}

void Solution() {
    Search(0, 0, N);
    cout << M << "\n" << Z << "\n" << O;
}

void Input() {
    cin >> N;

    paper.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];
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
