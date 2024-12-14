#include <iostream>
#include <vector>

using namespace std;

int R, C;
string ans;
vector<string> puzzle;

inline void Compare(string tmp) {
    if(tmp.size() < 2) return;

    ans = min(ans, tmp);
}

void Solution() {
    char ch;
    string tmp;
    ans = "zzzzzzzzzzzzzzzzzzzz";

    for(int i = 0; i < R; i++) {
        tmp = "";

        for(int j = 0; j < C; j++) {
            ch = puzzle[i][j];

            if(ch == '#') {
                Compare(tmp);
                tmp = "";
                continue;
            }

            tmp.push_back(ch);
        }
        Compare(tmp);
    }

    for(int i = 0; i < C; i++) {
        tmp = "";

        for(int j = 0; j < R; j++) {
            ch = puzzle[j][i];

            if(ch == '#') {
                Compare(tmp);
                tmp = "";
                continue;
            }

            tmp.push_back(ch);
        }
        Compare(tmp);
    }

    cout << ans;
}

void Input() {
    cin >> R >> C;

    puzzle.resize(R);

    for(int i = 0; i < R; i++) {
        cin >> puzzle[i];
    }     
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}