#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> s;
vector<vector<int>> seq;

bool CheckNum(int sum) {
    string res = to_string(sum);

    for (int i = 0; i < res.size(); i++) {
        if (res[i] != '5' && res[i] != '8') return false;
    }

    return true;
}

void Search(int x, int sum) {
    if (x == 3) {
        if (CheckNum(sum)) s.insert(sum);
        return;
    }

    for (int i = 0; i < seq[x].size(); i++) {
        Search(x + 1, sum + seq[x][i]);
    }
}

void Solution() {
    Search(0, 0);
    cout << s.size() << "\n";
}

void Input() {
    int N;
    seq.resize(3);

    for (int i = 0; i < 3; i++) {
        cin >> N;

        seq[i].resize(N);

        for (int j = 0; j < N; j++) cin >> seq[i][j];
    }
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
        s.clear();
        seq.clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
