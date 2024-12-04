#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, N, M, count, ans = 0;
    cin >> N >> M;

    vector<int> claps(M + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> count;
            claps[j] += count;
        }
    }

    for (int i = 2; i <= M; i++) 
        claps[i] += claps[i - 1];

    cin >> A;

    for (int i = 0; i <= M - A; i++)
        ans = max(ans, claps[i + A] - claps[i]);

    cout << ans;
    return 0;
}