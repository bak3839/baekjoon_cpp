#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
    int count;
    int time;
    int clipboard;
}Emoticon;

int S;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

vector<vector<bool>> checked;

void BFS() {
    int c, t, cb;

    queue<Emoticon> q;
    q.push({1, 0, 0});
    checked[1][0] = true;
    
    while (!q.empty()) {
        c = q.front().count;
        t = q.front().time;
        cb = q.front().clipboard;
        q.pop();

        if (c == S) {
            cout << t;
            break;
        }

        // 1. 클립보드 화면에 붙여넣기
        if (cb + c <= 1001 && cb > 0 && !checked[cb + c][cb]) {
            q.push({ cb + c, t + 1, cb });
            checked[cb + c][cb] = true;
        }

        // 2. 화면 이모티콘 하나 삭제
        if (c - 1 > 0 && !checked[c - 1][cb]) {
            q.push({ c - 1, t + 1, cb });
            checked[c - 1][cb] = true;
        }

        // 3. 복사
        if (!checked[c][c]) {
            q.push({ c, t + 1, c });
            checked[c][c] = true;
        }
    }
}

void Solution() {
    BFS();
}

void Input() {
    cin >> S;
    checked.resize(1002, vector<bool>(1002, false));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}