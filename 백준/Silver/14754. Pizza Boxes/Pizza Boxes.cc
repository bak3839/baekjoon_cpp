#include <bits/stdc++.h>
using namespace std;

long long ans;
bool checked[1001][1001];
int N, M, A[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int maxH = 0;

        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            if (A[i][maxH] < A[i][j]) maxH = j;
        }
        checked[i][maxH] = true;
    }

    for (int j = 0; j < M; j++) {
        int maxH = 0;

        for (int i = 0; i < N; i++) {
            if (A[maxH][j] < A[i][j]) maxH = i;
        }
        checked[maxH][j] = true;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (checked[i][j]) continue;

            ans += A[i][j];
        }
    }

    cout << ans;
    return 0;
}