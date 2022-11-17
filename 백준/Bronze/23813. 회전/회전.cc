#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll res = 0;
    string n, a, b;
    cin >> n;
    int index = n.size() - 1, cnt = 1, x = 10;
    for (int i = 1; i < index; i++) x *= 10;

    for (int i = 1; i < n.size(); i++) {
        a = "0"; b = "0";

        a = n.substr(0, n.size() - i);
        b = n.substr(index, cnt);

        res += stol(a) + stol(b) * x;
        x /= 10;
        cnt++;
        index--;
    }

    cout << res + stol(n);
    return 0;
}
