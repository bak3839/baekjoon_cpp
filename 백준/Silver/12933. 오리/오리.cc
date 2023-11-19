#include <iostream>
#include <vector>

using namespace std;

int q, u, a, c, k;
string voice;

void Solution() {
    int ans = 0, i = 0;

    for (i = 0; i < voice.size(); i++) {
        char now = voice[i];

        if (now == 'q') q++;

        else if (now == 'u') {
            if (q > u) u++;
            else break;
        }

        else if (now == 'a') {
            if (u > a) a++;
            else break;
        }

        else if (now == 'c') {
            if (a > c) c++;
            else break;
        }

        else if (now == 'k') {
            if (c > k) {
                ans = max(q, ans);
                q--; u--; a--; c--;
            }
            else break;
        }
    }
    
    if (i != voice.size() || q != 0) ans = -1;

    cout << ans;
}

void Input() {
    cin >> voice;
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
