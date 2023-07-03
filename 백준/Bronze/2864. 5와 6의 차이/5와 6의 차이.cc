#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Change(string s, bool flag) {
    for (int i = 0; i < s.size(); i++) {
        if (flag && s[i] == '6') s[i] = '5';
        else if(!flag && s[i] == '5') s[i] = '6';
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s1, s2;
    vector<string> num(4);
    cin >> s1 >> s2;

    num[0] = Change(s1, true);
    num[1] = Change(s2, true);
    num[2] = Change(s1, false);
    num[3] = Change(s2, false);

    cout << stoi(num[0]) + stoi(num[1]) << " " << stoi(num[2]) + stoi(num[3]);
    return 0;
}