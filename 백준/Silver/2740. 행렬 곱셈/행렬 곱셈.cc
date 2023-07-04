#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int mat1[101][101], mat2[101][101], ans[101][101];

void Solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {

            for (int k = 0; k < M; k++) {
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}

void Input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> mat1[i][j];
    }

    cin >> M >> K;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++)
            cin >> mat2[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}