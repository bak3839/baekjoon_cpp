#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string S, ans;
int cnt = 0, N;
bool finish = false;
vector<bool> used;

void Permu(string tmp) {
    if (tmp.size() == S.size()) {
        cnt++;
        if (cnt == N) {
            ans = tmp;
            finish = true;
            return;
        }
        return;
    }

    for (int i = 0; i < S.size(); i++) {
        if (used[i]) continue;

        used[i] = true;
        Permu(tmp + S[i]);
        used[i] = false;

        if (finish) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> S >> N) {
        used.resize(S.size(), false);
        Permu("");
        used.clear();

        cout << S << " " << N << " = ";

        if (finish) cout << ans << "\n";
        else cout << "No permutation\n";

        cnt = 0;
        finish = false;
    }
    return 0;
}