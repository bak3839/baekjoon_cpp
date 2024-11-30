#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, str1;
    char ch;

    cin >> str >> ch >> str1;

    int strsize = str.size();
    int str1size = str1.size();

    if (ch == '*') {
        int totalsize = strsize + str1size - 2;
        cout << '1';
        for (int i = 0; i < totalsize; i++) {
            cout << 0;
        }
    }

    else {
        if (strsize == str1size) {
            cout << '2';
            for (int i = 0; i < strsize - 1; i++) {
                cout << '0';
            }
        }
        else if (strsize != str1size) {
            int a = max(strsize, str1size);    
            int b = min(strsize, str1size);
            
            for (int i = a; i > 0; i--) {
                if (i == a || i == b) cout << '1';
                else cout << '0';
            }
        }
    }
    return 0;
}