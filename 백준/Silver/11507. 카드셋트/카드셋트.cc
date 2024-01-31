#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string str;
map<char, int> m;
vector<vector<bool>> exist;


void Solution() {
    bool pass = true;

    for (int i = 0; i < str.size(); i = i + 3) {
        string res = str.substr(i, 3);

        char ch = res[0];
        int num = stoi(res.substr(1, 2)) - 1;

        switch (ch){
        case 'P':
            if (exist[0][num]) {
                pass = false;
                break;
            }

            exist[0][num] = true;
            break;

        case 'K':
            if (exist[1][num]) {
                pass = false;
                break;
            }

            exist[1][num] = true;
            break;

        case 'H':
            if (exist[2][num]) {
                pass = false;
                break;
            }

            exist[2][num] = true;
            break;

        case 'T':
            if (exist[3][num]) {
                pass = false;
                break;
            }

            exist[3][num] = true;
            break;
        }

        if (!pass) {
            cout << "GRESKA";
            return;
        }
    }

    for (int i = 0; i < 4; i++) {
        int cnt = 0;

        for (int j = 0; j < 13; j++) {
            if (!exist[i][j]) cnt++;
        }

        cout << cnt << " ";
    }
}

void Input() {
    cin >> str;
    exist.resize(4, vector<bool>(13, false));
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
