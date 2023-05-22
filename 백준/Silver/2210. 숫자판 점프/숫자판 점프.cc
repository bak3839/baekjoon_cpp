#include <iostream>
#include <vector>
#include <string>

using namespace std;

char num[5][5];
int mv[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
vector<bool> visit;
int ans;

void check(string s) {
    int n = stoi(s);

    if (!visit[n]) {
        ans++;
        visit[n] = true;
    }
}

void search(int x, int y, string s) {
    if (s.size() == 6) {
        check(s);
        return;
    }

    s.push_back(num[x][y]);

    for (int i = 0;i < 4;i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;

        search(nx, ny, s);
    }
}

void Solution() {
    for (int i = 0;i < 5;i++) {
        for (int j = 0;j < 5;j++) {
            search(i, j, "");
        }
    }

    cout << ans;
}

void Input() {
    visit.resize(1000000, false);

    for (int i = 0;i < 5;i++) {
        for (int j = 0; j < 5;j++)
            cin >> num[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}