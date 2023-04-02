#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> top;
vector<int> bottom;

void input(int N, int H) {
    top.resize(H + 1, 0);
    bottom.resize(H + 1, 0);

    int h;
    for (int i = 1; i <= N; i++) {
        cin >> h;

        if (i % 2) bottom[h]++;
        else top[H - h + 1]++;
    }
}

void solve(int H) {
    for (int i = H - 1; i > 0; i--) {
        bottom[i] += bottom[i + 1];
    }
    for (int i = 2; i <= H; i++) {
        top[i] += top[i - 1];
    }

    int ans = 200001, cnt = 0;
    for (int i = 1; i <= H; i++) {
        int sum = top[i] + bottom[i];
        if (sum < ans) {
            ans = sum; cnt = 1;
        }
        else if (sum == ans) cnt++;
    }

    cout << ans << " " << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, H;
    cin >> N >> H;

    input(N, H);
    solve(H);
    return 0;
}