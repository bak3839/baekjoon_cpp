#include <iostream>
#include <vector>

using namespace std;

string ticket;

void Solution() {
    int size = ticket.size();

    for (int len = size / 2; len >= 0; len--) {
        for (int i = 0; i < size; i++) {
            if (i + len * 2 > size) break;

            int L, R, sumL = 0, sumR = 0;

            for (L = i; L < i + len; L++) 
                sumL += ticket[L] - '0';

            for (R = L; R < L + len; R++) 
                sumR += ticket[R] - '0';

            if (sumL == sumR) {
                cout << len * 2;
                return;
            }
        }
    }

    cout << 0;
}

void Input() {
    cin >> ticket;
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