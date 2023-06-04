#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, ans;
vector<int> bead;
vector<bool> check;

void Choice(int sum, int len) {
    int a = 0, b = 0;

    if(len == 2){
        ans = max(ans, sum);
        return;
    }

    for (int i = 1; i < N - 1; i++) {
        if (check[i]) continue;

        check[i] = true;

        for (int idx = i - 1; idx >= 0; idx--) {
            if (!check[idx]) {
                a = bead[idx];
                break;
            }
        }

        for (int idx = i + 1; idx < N; idx++) {
            if (!check[idx]) {
                b = bead[idx];
                break;
            }
        }
        
        Choice(sum + (a * b), len - 1);
        check[i] = false;
    }
}

void Solution() {
    Choice(0, N);
    cout << ans;
}

void Input() {
    cin >> N;
    bead.resize(N);
    check.resize(N, false);

    for (int i = 0; i < N; i++)
        cin >> bead[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}