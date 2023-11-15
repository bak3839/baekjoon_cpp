#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> book;

void Solution() {
    int ans = 0, sum = 0;

    for (int i = 0; i < N; i++) {
        if (sum + book[i] <= M) {
            if (sum == 0) ans++;
            sum += book[i];
        }
        else {
            sum = 0;
            i -= 1;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    book.resize(N);

    for (int i = 0; i < N; i++)
        cin >> book[i];
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
