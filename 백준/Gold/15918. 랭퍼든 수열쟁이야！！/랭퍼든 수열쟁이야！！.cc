#include <iostream>
#include <vector>

using namespace std;

int N, x, y, ans, len;
vector<bool> visit;
vector<bool> check;

void Fill(int x, int n, bool b) {
    visit[x] = b;
    visit[x + n + 1] = b;
    check[n] = b;
}

void Search(int x) {
    if (x >= 2 * N) return;

    if (len == 0) {
        ans++;
        return;
    }

    if (visit[x]) {
        Search(x + 1);
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (x + i + 1 >= 2 * N) return;
        if (visit[x + i + 1] || check[i]) continue;

        Fill(x, i, true);
        len -= 2;

        Search(x + 1);

        Fill(x, i, false);
        len += 2;
    }
}

void Solution() {
    int diff = y - x - 1;
    check[diff] = true;

    len = 2 * N;
    len -= 2;

    visit[x - 1] = true; visit[y - 1] = true;
    Search(0);

    cout << ans;
}

void Input() {
    cin >> N >> x >> y;

    visit.resize(N * 2, false);
    check.resize(N + 1, false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}