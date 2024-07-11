#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> milk;

void Solution() {
    int prev = 2, ans = 0;

    for (int i = 0; i < N; i++) {
        int m = milk[i];

        if ((m == 0 && prev == 2) || (m == 1 && prev == 0) || (m == 2 && prev == 1)) {
            prev = m;
            ans++;
        } 
    }

    cout << ans;
}

void Input() {
    cin >> N;

    milk.resize(N);

    for (int i = 0; i < N; i++)
        cin >> milk[i];
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