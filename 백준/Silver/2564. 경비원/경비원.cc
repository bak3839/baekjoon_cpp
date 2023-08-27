#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct {
    int d; // 1. 북 2. 남 3. 서 4. 동
    int n;
}Loc;

int W, H, N, ans;
Loc my;
vector<Loc> v;

void Calculate(Loc l) {
    if (my.d == 1) {
        if (l.d == 1)
            ans += abs(l.n - my.n);

        else if (l.d == 2)
            ans += min(my.n + l.n + H, (W + H) * 2 - (my.n + l.n + H));

        else if (l.d == 3)
            ans += l.n + my.n;

        else
            ans += (W - my.n) + l.n;
    }

    else if (my.d == 2) {
        if (l.d == 1)
            ans += min(my.n + l.n + H, (W + H) * 2 - (my.n + l.n + H));

        else if (l.d == 2)
            ans += abs(l.n - my.n);

        else if (l.d == 3)
            ans += (H - l.n) + my.n;

        else
            ans += (W - my.n) + (H - l.n);
    }

    else if (my.d == 3) {
        if (l.d == 1)
            ans += l.n + my.n;

        else if (l.d == 2)
            ans += l.n + (H - my.n);

        else if (l.d == 3)
            ans += abs(my.n - l.n);

        else
            ans += min(my.n + l.n + W, (W + H) * 2 - (my.n + l.n + W));
    }

    else {
        if (l.d == 1)
            ans += (W - l.n) + my.n;

        else if (l.d == 2)
            ans += (W - l.n) + (H - my.n);

        else if (l.d == 3)
            ans += min(my.n + l.n + W, (W + H) * 2 - (my.n + l.n + W));

        else
            ans += abs(my.n - l.n);
    }
}

void Solution() {
    for (int i = 0; i < N; i++)
        Calculate(v[i]);

    cout << ans;
}

void Input() {
    cin >> W >> H >> N;

    for (int i = 0; i < N; i++) {
        Loc l;
        cin >> l.d >> l.n;

        v.push_back(l);
    }

    cin >> my.d >> my.n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
