#include <iostream>
#include <vector>

using namespace std;

string str;

bool Change(int index, int cnt) {
    int i;
    int A = cnt / 4;
    int B = (cnt % 4) / 2;   

    if ((cnt % 4) % 2) return false;

    for (i = index; i < index + A * 4; i++)
        str[i] = 'A';

    index = index + A * 4;

    for (i = index; i < index + B * 2; i++)
        str[i] = 'B';

    return true;
}

void Solution() {
    bool pass = true;
    int index = 0, cnt = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'X') {
            if (cnt == 0) index = i;
            cnt++;
        }

        else if (str[i] == '.' && cnt != 0) {
            pass = Change(index, cnt);
            cnt = 0;
        }

        if (!pass) {
            cout << -1;
            return;
        }
    }

    if (cnt != 0) {
        pass = Change(index, cnt);
    }
    if (pass) cout << str;
    else cout << -1;
}

void Input() {
    cin >> str;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
