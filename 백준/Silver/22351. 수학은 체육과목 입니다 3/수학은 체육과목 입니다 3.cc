#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int i = -1, j = -1;
    string s;
    cin >> s;

    for (i = 1; i <= 999; i++) {
        string tmp = "";
        for (j = i; j <= 999; j++) {
            tmp.append(to_string(j));

            if (tmp == s) {
                cout << i << " " << j;
                return 0;
            }

            if (tmp.size() > 2889) break;
        }
    }
    return 0;
}