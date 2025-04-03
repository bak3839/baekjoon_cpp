#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int H; int M; int S;
}A;

int N;
A a[5001];

bool cmp(A a1, A a2) {
    if (a1.H == a2.H) {
        if (a1.M == a2.M) return a1.S < a2.S;
        return a1.M < a2.M;
    }

    return a1.H < a2.H;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i].H >> a[i].M >> a[i].S;
    }
    sort(a, a + N, cmp);

    for (int i = 0; i < N; i++) {
        cout << a[i].H << " " << a[i].M << " " << a[i].S << "\n";
    }
    return 0;
}