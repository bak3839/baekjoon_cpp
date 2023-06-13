#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s, str = "UCPC";
    int index = 0;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (index == 4) break;
        if (str[index] == s[i]) index++;
    }
    if (index == 4) cout << "I love UCPC";
    else cout << "I hate UCPC";
    return 0;
}