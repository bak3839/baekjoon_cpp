#include <bits/stdc++.h>

using namespace std;

int N, ans;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end(), greater<int>());

    while (v.size() > 1) {
        ans++;
        v[0]--; v[1]--;
        sort(v.begin(), v.end(), greater<int>());

        while (!v.empty() && v.back() == 0)
            v.pop_back();
    }

    if(v.size()) ans += v[0];

    if (ans > 1440) ans = -1;
    cout << ans;
    return 0;
}