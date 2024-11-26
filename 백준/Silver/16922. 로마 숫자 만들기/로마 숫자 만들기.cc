#include <iostream>
#include <vector>

using namespace std;

int N, ans = 0;
int R[4] = { 1, 5, 10, 50 };
vector<bool> checked(1001, false);

void Combination(int x, int count, int sum) {
    if (count == N) {
        if (!checked[sum]) {
            ans++;
            checked[sum] = true;
        }
        
        return;
    }

    for (int i = x; i < 4; i++) {
        Combination(i, count + 1, sum + R[i]);
    }
}

void Solution() {
    Combination(0, 0, 0);
    cout << ans;
}

void Input() {
    cin >> N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}