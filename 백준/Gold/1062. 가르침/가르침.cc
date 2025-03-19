#include <bits/stdc++.h>

using namespace std;

int N, K;
int word[51];
char c[5] = { 'a', 'n', 't', 'i', 'c' };

int count(int mask) {
    int cnt = 0;
    for (int w : word) {
        if (w && (w & mask) == w)cnt++;
    }
    return cnt;
}

int teach(int index, int k, int mask) {
    if (k < 0) return 0;

    if (index == 26) return count(mask);

    int res = 0;

    if (mask & (1 << index)) {
        res = teach(index + 1, k, mask);
    }
    else {
        res = teach(index + 1, k, mask);
        res = max(res, teach(index + 1, k - 1, mask | (1 << index)));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    if (K < 5) {
        cout << 0;
        return 0;
    }

    string s;
    int mask = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> s;

        for (char ch : s)
            word[i] |= (1 << (ch - 'a'));
    }

    for (char ch : c)
        mask |= (1 << (ch - 'a'));

    cout << teach(0, K - 5, mask);

    return 0;
}
