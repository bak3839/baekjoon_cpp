#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s, tmp;
    cin >> s;
    tmp = s;

    reverse(tmp.begin(), tmp.end());

    if (s == tmp) cout << 1;
    else cout << 0;
    return 0;
}