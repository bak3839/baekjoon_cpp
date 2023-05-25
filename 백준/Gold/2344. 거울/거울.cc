#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int x;
    int y;
    int d;
}Light;

int N, M;
int mv[5][2] = { {0,0},{0,1},{-1,0},{0,-1},{1, 0} };
vector<vector<int>> box;
vector<Light> start;
vector<int> ans;

int ChangeDir(int d) {
    switch (d){
    case 1:
        return 2;
    case 2:
        return 1;
    case 3:
        return 4;
    case 4:
        return 3;
    }
}

void Move(int index) {
    Light now = start[index];
    int x = now.x; int y = now.y; int d = now.d;

    while (1) {
        x = x + mv[d][0];
        y = y + mv[d][1];

        if (x <= 0 || x > N || y <= 0 || y > M) {
            ans.push_back(box[x][y]);
            break;
        }

        if (box[x][y] == 1) d = ChangeDir(d);
    }
}

void Solution() {
    for (int i = 0; i < start.size(); i++) {
        Move(i);
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

void Input() {
    cin >> N >> M;
    box.resize(N + 2, vector<int>(M + 2, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            cin >> box[i][j];
    }

    int cnt = 1;

    for (int i = 1; i <= N; i++) {
        box[i][0] = cnt++;
        start.push_back({ i, 0, 1 });
    }
    for (int i = 1; i <= M; i++) {
        box[N + 1][i] = cnt++;
        start.push_back({ N + 1, i, 2 });
    }
    for (int i = N; i >= 1; i--) {
        box[i][M + 1] = cnt++;
        start.push_back({ i, M + 1, 3 });
    }
    for (int i = M; i >= 1; i--) {
        box[0][i] = cnt++;
        start.push_back({ 0, i, 4 });
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}