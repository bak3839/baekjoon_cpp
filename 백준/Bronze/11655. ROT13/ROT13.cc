#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    getline(cin, s);

    for (int i = 0;i < s.size();i++) {
        char ch = s[i];

        if ('a' <= ch && ch <= 'z') {
            if (ch - 'a' < 13) ch += 13;
            else ch -= 13;
        }

        else if ('A' <= ch && ch <= 'Z') {
            if (ch - 'A' < 13) ch += 13;
            else ch -= 13;
        }
        s[i] = ch;
    }
    cout << s;
    return 0;
}