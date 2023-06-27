#include <iostream>
#include <vector>

using namespace std;

int N, M;
int mat[201][201];

void Solution() {
    int ans = -2100000000;
    int x1, x2, y1, y2;

    for (int i = 1; i <= min(N, M); i++) {

        for (int r = i; r <= N; r++) {
            for (int c = i; c <= M; c++) {               
                x2 = r; y2 = c;
                x1 = x2 - i + 1; y1 = y2 - i + 1;

                ans = max(mat[x2][y2] - mat[x2][y1 - 1] - mat[x1 - 1][y2] + mat[x1 - 1][y1 - 1], ans);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i == j) continue;

            for (int r = i; r <= N; r++) {
                for (int c = j; c <= M; c++) {
                    x1 = r - i + 1; y1 = c - j + 1;
                    x2 = r; y2 = c;

                    ans = max(mat[x2][y2] - mat[x2][y1 - 1] - mat[x1 - 1][y2] + mat[x1 - 1][y1 - 1], ans);
                }
            }
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> mat[i][j];
            mat[i][j] += mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();

    return 0;
}