#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, cnt = 1;

void Solution() {
    int n, ans;
    set<int> s;

    for (int i = 0; i < N; i++) {
        cin >> n;

        if (s.find(n) != s.end()) {
            s.erase(n);
        }
        else {
            s.insert(n);
        }
    }

    for (auto res : s) {
        ans = res;
        break;
    }

    cout << "Case #" << cnt << ": " << ans << "\n";
}

void Input() {
    cin >> N;
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
        cnt++;
    }    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}