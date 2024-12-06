#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> S;
    int N, l, s, ans = 1;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> l >> s;
        S.push(s);
    }

    int first = S.top();
    S.pop();

    while (!S.empty()) {
        if (S.top() <= first) {
            ans++;
            first = S.top();
        }

        S.pop();
    }

    cout << ans;
    return 0;
}