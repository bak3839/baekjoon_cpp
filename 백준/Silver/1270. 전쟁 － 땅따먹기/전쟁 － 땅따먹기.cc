#include <iostream>
#include <vector>

using namespace std;

int N;

void Solution() {
    vector<long long> res;

    while (N--) {
        int n, count = 0;
        long long candidate = 0;

        cin >> n;

        res.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> res[i];

            if (count == 0) candidate = res[i];
            if (res[i] == candidate) count++;
            else count--;
        }

        int check = 0;

        for (auto r : res) {
            if (candidate == r) check++;
        }

        if (check > n / 2) cout << candidate << "\n";
        else cout << "SYJKGW\n";
        res.clear();
    }
}

void Input() {
    cin >> N;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}