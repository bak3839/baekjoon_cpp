#include <iostream>
#include <vector>

using namespace std;

int N, K, ans;
vector<int> kit;
vector<bool> used;

void Routine(int sum, int cnt) {
    if (sum < 500) return;

    if (cnt == N) {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (used[i]) continue;
        
        used[i] = true;
        Routine(sum + kit[i] - K, cnt + 1);
        used[i] = false;
    }
}

void Solution() {
    Routine(500, 0);
    cout << ans;
}

void Input() {
    cin >> N >> K;
    kit.resize(N);
    used.resize(N, false);

    for (int i = 0; i < N; i++) 
        cin >> kit[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}