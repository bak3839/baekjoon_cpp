#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool finish;
int N, r, c, cnt;

void Search(int x, int y, int len) {
    if (x == r && y == c) {
        cout << cnt;
        exit(0);
    }

    if (r >= x && c >= y && r < x + len && c < y + len) {
        int halfLen = len / 2;

        Search(x, y, halfLen);
        Search(x, y + halfLen, halfLen);
        Search(x + halfLen, y, halfLen);
        Search(x + halfLen, y + halfLen, halfLen);
    }
    else {
        cnt += len * len;
    }
}

void Solution() {
    Search(0, 0, pow(2, N));
}

void Input() {
    cin >> N >> r >> c;
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
