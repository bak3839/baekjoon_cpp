#include <bits/stdc++.h>

using namespace std;

vector<int> v, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, n;
    cin >> N;

    v.resize(N);
    ans.resize(N, -1);

    for (int i = 0; i < N; i++) 
        cin >> v[i];

    stack<int> s;

    for (int i = N - 1; i >= 0; i--) {
        n = v[i];

        while (!s.empty()) {
            if (s.top() > n) {
                ans[i] = s.top();
                break;
            }

            s.pop();
        }

        s.push(n);
    }
    
    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
    return 0;
}
