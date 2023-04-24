#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void Solution(int N) {
    int n, a = 0, b = 0, ans = 0;
    cin >> n;

    for (int i = 0; i < N; i++) {
        if (v[i] >= n) {
            a = i > 0 ? v[i - 1] + 1 : 1;
            b = v[i] - 1;
            break;
        }
    }
    if (a > n) {
        cout << 0;
        return;
    }

    for (int i = a; i <= n; i++) {
        for (int j = n; j <= b; j++) {
            if (i == j) continue;
            ans++;
        }
    }

    cout << ans;
}

void Input(int N) {
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    Input(N);
    Solution(N);
    return 0;
}