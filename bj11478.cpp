#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    set<string> s;
    string str, res = "";

    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        for (int j = i; j < str.size(); j++) {
            res += str[j];
            s.insert(res);
        }
        res = "";
    }

    cout << s.size();
    return 0;
}