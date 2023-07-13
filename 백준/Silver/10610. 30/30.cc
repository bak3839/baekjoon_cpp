#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> n;
    string s;
    cin >> s;

    sort(s.begin(), s.end(), greater<>());

    if (s[s.size() - 1] != '0') cout << -1;

    else {
        long long sum = 0;

        for (int i = 0; i < s.size(); i++)
            sum += s[i] - '0';

        if (sum % 3 == 0) cout << s;
        else cout << -1;
    }

    return 0;
}