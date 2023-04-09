#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Solution(string str) {

    string ans = "";
    ans.push_back(str[0]);

    for (int i = 1; i < str.size(); i++) {
        if (ans[i - 1] < str[i]) ans = str[i] + ans;
        else ans += str[i];
    }
    reverse(ans.begin(), ans.end());

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str;
    cin >> str;

    Solution(str);
    return 0;
}