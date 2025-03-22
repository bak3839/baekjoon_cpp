#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct A {
    int t;
    int a;
    int h;
};

int N;
ll maxHp = LLONG_MAX;
A room[123456];

bool check(ll hp, ll atk) {
    ll cur = hp;

    for (A r : room) {
        if (r.t == 1) {
            ll cntY = r.h / atk + (r.h % atk ? 1 : 0);
            ll cntM = cntY - 1;
            cur -= cntM * r.a;

            if (cur <= 0) return false;
        }
        else {
            atk += r.a;
            cur = min(cur + r.h, hp);
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll atk;
    cin >> N >> atk;

    for (int i = 0; i < N; i++) {
        cin >> room[i].t >> room[i].a >> room[i].h;
    }

    ll L = 1, R = maxHp - 1, mid;

    while (L <= R) {
        mid = (L + R) / 2;

        if (check(mid, atk)) {
            R = mid - 1;
            maxHp = min(mid, maxHp);
        }
        else L = mid + 1;
    }

    cout << maxHp;
    return 0;
}