#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int len;
int DP[5][5][100002];
vector<int> DDR;

int Power(int from, int to) {
    if (from == 0) return 2;
    else if (from == to) return 1;
    else if (abs(from - to) == 2) return 4;
    return 3;
}

int Memo(int x, int y, int cnt) {
    if (cnt == len) return 0;
    if (DP[x][y][cnt] != -1) return DP[x][y][cnt];

    int l = Memo(DDR[cnt], y, cnt + 1) + Power(x, DDR[cnt]);
    int r = Memo(x, DDR[cnt], cnt + 1) + Power(y, DDR[cnt]);

    return DP[x][y][cnt] = min(l, r);
}

void Solution() {
    cout << Memo(0, 0, 0);
}

void Input() {
    int n;

    while (1) {
        cin >> n;

        if (n == 0) break;

        DDR.push_back(n);
    }

    len = DDR.size();
    memset(DP, -1, sizeof(DP));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}