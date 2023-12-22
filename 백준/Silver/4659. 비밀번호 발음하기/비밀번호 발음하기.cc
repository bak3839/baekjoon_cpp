#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;

    while (1) {
        cin >> s;

        if (s == "end") break;

        bool pass = true;
        char prev = '.';
        int c = 0, v = 0, totalV = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (ch == 'a' || ch == 'i' || ch == 'o' || ch == 'e' || ch == 'u') {
                v++;
                totalV++;
                c = 0;
            }
            else {
                c++;
                v = 0;
            }

            if (prev == ch && !(ch == 'e' || ch == 'o')) {
                pass = false;
                break;
            }

            if (c >= 3 || v >= 3) {
                pass = false;
                break;
            }

            prev = ch;
        }

        if (pass && totalV > 0) cout << "<" << s << "> is acceptable.\n";
        else cout << "<" << s << "> is not acceptable.\n";
    }
    return 0;
}
