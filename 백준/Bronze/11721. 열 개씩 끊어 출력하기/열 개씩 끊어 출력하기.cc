#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;

    int cnt = 0;

    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
        cnt++;
        if (cnt == 10) {
            cnt = 0;
            cout << "\n";
        }
    }
    return 0;
}