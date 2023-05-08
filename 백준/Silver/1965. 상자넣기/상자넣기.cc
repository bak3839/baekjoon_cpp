#include <iostream>
#include <vector>

using namespace std;

vector<int> box;
vector<int> DP;

void Input(int N) {
    box.resize(N);
    DP.resize(N, 1);

    for (int i = 0;i < N;i++)
        cin >> box[i];
}

void Solution(int N) {
    int ans = 1;

    for (int i = 1;i < N;i++) {
        int now = box[i];
        for (int j = i - 1;j >= 0;j--) {
            if (now > box[j]) {
                DP[i] = max(DP[j] + 1, DP[i]);
                ans = max(ans, DP[i]);
            }
        }
    }

    cout << ans;
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