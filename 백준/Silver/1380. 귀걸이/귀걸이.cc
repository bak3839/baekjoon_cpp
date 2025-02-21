#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char ch;
    int n, num, total, cnt = 1;
    vector<string> name;
    vector<bool> check;

    while (1) {
        cin >> n;

        if (n == 0) break;

        total = (n * (n + 1)) / 2;
        name.resize(n);
        check.resize(n, false);

        cin.ignore();
        for (int i = 0; i < n; i++)
            getline(cin, name[i]);

        for (int i = 0; i < 2 * n - 1; i++) {
            cin >> num >> ch;

            if (!check[num - 1]) check[num - 1] = true;
            else total -= num;
        }

        cout << cnt++ << " " << name[total - 1] << "\n";
        name.clear(); check.clear();
    }
    return 0;
}
