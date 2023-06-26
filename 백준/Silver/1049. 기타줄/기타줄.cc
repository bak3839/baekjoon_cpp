#include <iostream>
#include <vector>

using namespace std;

int N, M, pack = 1001, single = 1001, ans = 100001;

void Solution() {
    int c = N / 6;
    ans = min(ans, pack * c + single * (N - 6 * c));
    ans = min(ans, pack * (c + 1));
    ans = min(ans, single * N);

    cout << ans;
}

void Input() {
    cin >> N >> M;

    int p, s;

    for (int i = 0; i < M; i++) {
        cin >> p >> s;

        pack = min(pack, p);
        single = min(single, s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();

    return 0;
}