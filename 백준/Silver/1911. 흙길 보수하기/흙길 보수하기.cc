#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
    int a;
    int b;
}dot;

bool cmp(dot d1, dot d2) {
    if (d1.a < d2.a) return true;
    else if (d1.a == d2.a) return d1.b < d2.b;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    dot d;
    int N, L, ans = 0, end = 0;
    vector<dot> v;

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> d.a >> d.b;
        v.push_back(d);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++) {
        d = v[i];

        if (d.a < end) d.a = end;
        int k = (d.b - d.a) / L;
        int mod = (d.b - d.a) % L;

        ans += k;

        if (mod > 0) {
            ++ans;
            end = d.b + L - mod;
        }
    }

    cout << ans;

    return 0;
}

